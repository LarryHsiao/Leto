//
// Created by Larry Hsiao on 4/23/2018.
//

#include <string>
#include "../utility/curl_escape.h"
#include "auth_url.h"

using namespace std;

std::string AuthUrl::value() {
    const string scope ="user-read-recently-played "
                        "user-read-currently-playing "
                        "user-modify-playback-state "
                        "user-read-playback-state "
                        "user-top-read "
                        "user-library-modify "
                        "user-library-read "
                        "playlist-modify-private "
                        "playlist-modify-public "
                        "playlist-read-private";
    string url("https://accounts.spotify.com/authorize?response_type=code");
    url += "&client_id=" + CurlUrlEscape(config.clientId()).escape();
    url += "&redirect_uri=" + CurlUrlEscape("http://localhost:" + to_string(config.port()) + config.redirectPath()).escape();
    url += "&scope=" + CurlUrlEscape(scope).escape();
    return url;
}

AuthUrl::AuthUrl(Config &config){
    this->config = config;
}