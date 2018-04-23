//
// Created by Larry Hsiao on 4/13/2018.
//

#include <utility/web_browser.h>
#include <curl/curl.h>
#include <utility/url_escape.h>
#include <spotify/auth_impl.h>
#include <utility/curl_escape.h>
#include <iostream>
#include <server_http.hpp>
#include <condition_variable>
#include <chrono>

using namespace std;
using namespace SimpleWeb;
using HttpServer=Server<HTTP>;

void AuthImpl::launch() {
    auto success = false;
    HttpServer server;
    server.config.port = 29901;
    server.resource["^/auth/callback/"]["GET"] = [&](shared_ptr<HttpServer::Response> response,
                                                     shared_ptr<HttpServer::Request> request) {
        auto queryParameters = request->parse_query_string();
        auto code = queryParameters.find("code")->second;
        cout << "This is code " << code << endl;
        success = true;
    };

    thread serverThread([&]() {
        server.start();
    });
    std::string rawUrl("https://accounts.spotify.com/authorize?response_type=code");
    rawUrl += "&client_id=";
    rawUrl += CurlUrlEscape(config.clientId()).escape();
    rawUrl += "&redirect_uri=" + CurlUrlEscape("http://localhost:").escape();
    rawUrl += std::string(std::to_string(config.port()));
    rawUrl += CurlUrlEscape(config.redirectPath()).escape();
    browser->open(rawUrl);

    mutex mutex;
    unique_lock<std::mutex> lock(mutex);
    auto now = chrono::system_clock::now();
    condition_variable cv;
    cv.wait_until(lock, now + kTimeout, [&]() { return success; });
    server.stop();
    serverThread.join();
}

AuthImpl::AuthImpl(const Config &config, WebBrowser *webBrowser) {
    this->config = config;
    this->browser = webBrowser;
}

