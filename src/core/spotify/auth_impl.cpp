//
// Created by Larry Hsiao on 4/13/2018.
//

#include <utility/web_browser.h>
#include <curl/curl.h>
#include <utility/url_escape.h>
#include <spotify/auth_impl.h>
#include <utility/curl_escape.h>

void AuthImpl::launch() {
    std::string rawUrl("https://accounts.spotify.com/authorize?response_type=code");
    rawUrl += "&client_id=";
    rawUrl += CurlUrlEscape(config->clientId()).escape();
    rawUrl += "&redirect_uri=" + CurlUrlEscape("http://localhost:").escape();
    rawUrl += std::string(std::to_string(config->port()));
    rawUrl += CurlUrlEscape(config->redirectPath()).escape();
    browser->open(rawUrl);
}

AuthImpl::AuthImpl(Config* config, WebBrowser* webBrowser) {
    this->config = config;
    this->browser = webBrowser;
}

