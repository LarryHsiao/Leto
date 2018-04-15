//
// Created by Larry Hsiao on 4/15/2018.
//

#include "opera.h"

void Opera::open(std::string url) {
    auto command = std::string("DISPLAY=:0 opera '") + url+"'";
    system(command.c_str());
}
