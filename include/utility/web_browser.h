//
// Created by Larry Hsiao on 4/13/2018.
//

#ifndef LETO_WEB_BROWSER_H
#define LETO_WEB_BROWSER_H

#include <string>

class WebBrowser {
public:
    virtual void open(std::string url)=0;
};

#endif //LETO_WEB_BROWSER_H
