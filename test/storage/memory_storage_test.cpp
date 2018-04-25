//
// Created by Larry Hsiao on 4/25/2018.
//

#include<gtest/gtest.h>
#include "../../src/core/storage/memory_storage.h"

TEST(MemoryStorage, store) {
    auto storage = MemoryStorage();
    storage.store("key", "value");
    ASSERT_EQ("value", storage.value("key"));
}

TEST(MemoryStorage, NonExistKey) {
    auto storage = MemoryStorage();
    ASSERT_EQ("", storage.value("key"));
}

TEST(MemoryStorage, replaceKey) {
    auto storage = MemoryStorage();
    storage.store("key", "value");
    storage.store("key", "NewValue");
    ASSERT_EQ("NewValue", storage.value("key"));
}

TEST(MemoryStorage, clear) {
    auto storage = MemoryStorage();
    storage.store("key", "value");
    storage.clear();
    ASSERT_EQ("", storage.value("key"));
}


