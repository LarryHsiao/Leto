//
// Created by Larry Hsiao on 4/13/2018.
//

#include <string>
#include "NetSurf.h"

void Netsurf::open(std::string url) {
    auto command = std::string("DISPLAY=:0 netsurf '") + url+"' &";
    system(command.c_str());
}


