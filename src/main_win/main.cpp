//
// Created by Larry Hsiao on 4/20/2018.
//

#include <leto.h>
#include <thread>
#include <spotify/auth_impl.h>
#include <spotify/auth.h>
#include <unistd.h>
#include "utility/browser_default.h"

using namespace std;

void loop(){
    auto browser = BrowserDefault();
    auto config = Config();
    auto auth = AuthImpl(config, &browser);
    auth.launch();
    auto * leto = new Leto();
    while (leto->running()){
        leto->compute();
        usleep(1000000);
    }
}

int main() {
    thread thread(loop);
    thread.join();
    return 0;
}
