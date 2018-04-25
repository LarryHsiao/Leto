//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_MOCK_WEB_BROWSER_H
#define LETO_MOCK_WEB_BROWSER_H

#include <utility/WebBrowser.h>
#include <functional>

class MockWebBrowser: public WebBrowser{
private:
    std::function<void()> callback;

public:
    explicit MockWebBrowser(std::function<void()> callback);
    void open(std::string url) override ;
};

#endif //LETO_MOCK_WEB_BROWSER_H
