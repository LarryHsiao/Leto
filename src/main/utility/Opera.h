//
// Created by Larry Hsiao on 4/15/2018.
//

#ifndef LETO_OPERA_H
#define LETO_OPERA_H


#include <utility/WebBrowser.h>

class Opera : public WebBrowser{
public:
    void open(std::string url) override;
};


#endif //LETO_OPERA_H
