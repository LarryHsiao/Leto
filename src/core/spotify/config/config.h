//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_CONFIG_H
#define LETO_CONFIG_H

#include <string>

class Config{
public:
    std::string clientId();
    std::string redirectPath();
    int port();
};
#endif //LETO_CONFIG_H
