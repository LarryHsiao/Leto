//
// Created by Larry Hsiao on 4/11/2018.
//

#include <gtest/gtest.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

TEST(json, FromObject){
    json json;
    json["key"] = "value";
    ASSERT_EQ("value", json["key"]);
}

TEST(json, Deserialization) {
    auto json = R"(
        {
            "key" : "value"
        }
    )"_json;

    ASSERT_EQ("value", json["key"]);
}