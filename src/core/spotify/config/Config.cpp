//
// Created by Larry Hsiao on 4/14/2018.
//

#include <spotify/config/Config.h>

std::string Config::clientId() {
    return std::string("6573bd0fcc9d4d5d83bfbbd0956bd970");
}

std::string Config::redirectPath() {
    return std::__cxx11::string("/auth/callback/");
}

int Config::port() {
    return 29901;
}
