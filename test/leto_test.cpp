//
// Created by Larry Hsiao on 4/6/2018.
//

#include <gtest/gtest.h>
#include <leto.h>

TEST(Assertion, 123fdsa){
    auto leto = new Leto();
    leto->compute();
    ASSERT_TRUE(true);
}
