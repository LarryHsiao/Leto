//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_AUTHIMPL_H
#define LETO_AUTHIMPL_H

#include <spotify/auth.h>
#include <utility/web_browser.h>
#include "config/config.h"
#include "../../main/utility/netsurf.h"

class AuthImpl : public Auth {
public:
    AuthImpl(Config* config, WebBrowser* webBrowser);
    void launch() override;

private:
    Config* config;
    WebBrowser* browser;
};

#endif //LETO_AUTHIMPL_H