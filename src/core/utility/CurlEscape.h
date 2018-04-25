//
// Created by Larry Hsiao on 4/14/2018.
//

#ifndef LETO_URL_IMPL_H
#define LETO_URL_IMPL_H

#include <string>

class CurlUrlEscape{
public:
    explicit CurlUrlEscape(std::string input);
    std::string escape();

private:
    const std::string raw;
};


#endif //LETO_URL_IMPL_H
