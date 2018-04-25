//
// Created by Larry Hsiao on 4/14/2018.
//

#include "MockWebBrowser.h"

void MockWebBrowser::open(std::string url) {
    callback();
}

MockWebBrowser::MockWebBrowser(std::function<void()> callback) {
    this->callback = callback;
}
