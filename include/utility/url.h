//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_URL_H
#define LETO_URL_H

#include <string>

class Url {
public:
    virtual std::string escape() = 0;
};

#endif //LETO_URL_H
