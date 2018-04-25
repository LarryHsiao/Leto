//
// Created by Larry Hsiao on 4/25/2018.
//

#ifndef LETO_STORAGE_H
#define LETO_STORAGE_H

#include <string>

using namespace std;

class PairStorage {
public:
    virtual void store(string key, string value) = 0;
    virtual string value(string key) = 0;
    virtual void clear() = 0;
};

#endif //LETO_STORAGE_H
