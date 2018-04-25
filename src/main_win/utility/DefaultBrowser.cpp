//
// Created by Larry Hsiao on 4/20/2018.
//

#include "DefaultBrowser.h"

void DefaultBrowser::open(std::string url) {
    auto command = std::string(R"(start "" /B /WAIT ")") + url+ R"(")";
    system(command.c_str());
}
