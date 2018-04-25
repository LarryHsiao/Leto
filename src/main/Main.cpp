#include <iostream>
#include <thread>
#include <unistd.h>
#include <spotify/Auth.h>
#include <spotify/AuthImpl.h>
#include "Leto.h"
#include "utility/Opera.h"


using namespace std;

void loop(){
    auto netsurf = Opera();
    auto config = Config();
    auto auth = AuthImpl(config, &netsurf);
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
