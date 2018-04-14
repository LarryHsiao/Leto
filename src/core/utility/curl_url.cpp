//
// Created by Larry Hsiao on 4/14/2018.
//

#include <curl/curl.h>
#include "curl_url.h"

std::string CurlUrl::escape() {
    CURL *curl = curl_easy_init();
    const char *rawStr = raw.c_str();
    char *result = curl_easy_escape(curl, rawStr, 0);
    curl_easy_cleanup(curl);
    return std::string(result);
}

CurlUrl::CurlUrl(std::string input) : raw(input) {
}

