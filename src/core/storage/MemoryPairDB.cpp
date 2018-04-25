//
// Created by Larry Hsiao on 4/25/2018.
//

#include "MemoryPairDB.h"

void MemoryPairDB::store(string key, string value) {
    keyValue[key] = value;
}

string MemoryPairDB::value(string key) {
    return keyValue[key];
}

void MemoryPairDB::clear() {
    keyValue.clear();
}
