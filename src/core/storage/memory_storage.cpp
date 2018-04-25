//
// Created by Larry Hsiao on 4/25/2018.
//

#include "memory_storage.h"

void MemoryStorage::store(string key, string value) {
    keyValue[key] = value;
}

string MemoryStorage::value(string key) {
    return keyValue[key];
}

void MemoryStorage::clear() {
    keyValue.clear();
}
