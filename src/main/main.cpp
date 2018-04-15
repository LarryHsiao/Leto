#include <iostream>
#include <thread>
#include <unistd.h>
#include <spotify/auth.h>
#include <spotify/auth_impl.h>
#include "leto.h"
#include "utility/opera.h"

using namespace std;

void loop(){
    auto netsurf = Opera();
    auto config = Config();
    auto auth = AuthImpl(&config,&netsurf);
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
