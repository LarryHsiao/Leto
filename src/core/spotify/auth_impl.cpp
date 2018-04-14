//
// Created by Larry Hsiao on 4/13/2018.
//

#include <utility/web_browser.h>
#include <curl/curl.h>
#include <utility/url.h>
#include "auth_impl.h"
#include "../utility/curl_url.h"

void AuthImpl::launch() {
    std::string rawUrl("https://accounts.spotify.com/authorize?response_type=code");
    rawUrl += "&client_id=";
    rawUrl += config->clientId();
    rawUrl += "&redirect_uri=http://localhost:";
    rawUrl += std::string(std::to_string(config->port()));
    rawUrl += config->redirectPath();
    browser->open(rawUrl);
}

AuthImpl::AuthImpl(Config* config, WebBrowser* webBrowser) {
    this->config = config;
    this->browser = webBrowser;
}

