//
// Created by Larry Hsiao on 4/20/2018.
//

#ifndef LETO_BROWSER_DEFAULT_H
#define LETO_BROWSER_DEFAULT_H

#include <utility/WebBrowser.h>


class DefaultBrowser : public WebBrowser{
public:
    void open(std::string url) override;

};


#endif //LETO_BROWSER_DEFAULT_H
