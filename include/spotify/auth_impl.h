//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_AUTHIMPL_H
#define LETO_AUTHIMPL_H

#include <spotify/auth.h>
#include <utility/web_browser.h>
#include <spotify/config/config.h>
#include <functional>
#include <chrono>

using namespace std::chrono;

class AuthImpl : public Auth {
public:
    AuthImpl(const Config& config, WebBrowser* webBrowser);
    void launch() override;

private:
    const seconds kTimeout = 5s;
    Config config;
    WebBrowser* browser;

};

#endif //LETO_AUTHIMPL_H