//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_URL_IMPL_H
#define LETO_URL_IMPL_H

#include <utility/url.h>

class CurlUrl :Url{
public:
    explicit CurlUrl(std::string input);
    std::string escape() override;

private:
    const std::string raw;
};


#endif //LETO_URL_IMPL_H
