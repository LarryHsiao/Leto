//
// Created by Larry Hsiao on 4/13/2018.
//

#include <utility/WebBrowser.h>
#include <curl/curl.h>
#include <spotify/AuthImpl.h>
#include "../utility/CurlEscape.h"
#include <iostream>
#include <server_http.hpp>
#include <condition_variable>
#include <chrono>
#include "AuthUrl.h"

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
        success = true;

        *response << "HTTP/1.1 301 Moved Permanently\r\n"
                  << "Location: https://www.spotify.com" << "\r\n\r\n";
    };

    thread serverThread([&]() {
        server.start();
    });

    browser->open(AuthUrl(config).value());

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

