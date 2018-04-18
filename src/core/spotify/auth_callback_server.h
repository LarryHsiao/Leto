//
// Created by Larry Hsiao on 4/18/2018.
//

#ifndef LETO_AUTH_CALLBACK_SERVER_H
#define LETO_AUTH_CALLBACK_SERVER_H

#include <functional>
#include <string>

using namespace std;

class auth_callback_server {
public:
    void launch(std::function<void(std::string)> callback);
};


#endif //LETO_AUTH_CALLBACK_SERVER_H
