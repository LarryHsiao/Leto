//
// Created by Larry Hsiao on 4/13/2018.
//

#ifndef LETO_NETSURF_H
#define LETO_NETSURF_H

#include "utility/web_browser.h"

class Netsurf : WebBrowser{
public:
    void open(std::string url) override;
};

#endif //LETO_NETSURF_H
