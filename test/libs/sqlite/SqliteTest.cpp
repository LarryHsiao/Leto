//
// Created by Larry Hsiao on 4/23/2018.
//

#include <gtest/gtest.h>
#include <sqlite3.h>

TEST(SQLite, available) {
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);
    sqlite3_close(db);
    ASSERT_EQ(0, rc);
}
