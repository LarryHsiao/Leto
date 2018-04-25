//
// Created by Larry Hsiao on 4/20/2018.
//

#include <Leto.h>
#include <thread>
#include <spotify/AuthImpl.h>
#include <spotify/Auth.h>
#include <unistd.h>
#include "utility/DefaultBrowser.h"

using namespace std;

void loop(){
    auto browser = DefaultBrowser();
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
