//
// Created by Larry Hsiao on 4/25/2018.
//

#ifndef LETO_JSON_STORAGE_H
#define LETO_JSON_STORAGE_H

#include <storage/pair_storage.h>
#include <map>

class MemoryStorage : public PairStorage {
public :
    void store(string key, string value) override;
    string value(string key) override;
    void clear() override;
private:
    map<string, string> keyValue;
};

#endif //LETO_JSON_STORAGE_H
