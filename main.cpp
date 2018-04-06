#include <iostream>
#include <thread>
#include <unistd.h>
#include "leto.h"

using namespace std;

void loop(){
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
