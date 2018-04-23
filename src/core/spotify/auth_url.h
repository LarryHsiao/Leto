//
// Created by Larry Hsiao on 4/23/2018.
//

#ifndef LETO_AUTH_URL_H
#define LETO_AUTH_URL_H


#include <spotify/config/config.h>

class AuthUrl {
public:
    std::string value();
    AuthUrl(Config &config);
private:
    Config config;

};


#endif //LETO_AUTH_URL_H
