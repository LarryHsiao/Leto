//
// Created by Larry Hsiao on 4/14/2018.
//

#include <gtest/gtest.h>
#include "../../../src/core/utility/curl_url.h"

TEST(CurlUrl, escape){
    CurlUrl curlUrl("https://google.com?param=\\/fds");
    std::string result = curlUrl.escape();
    std::string expected("https%3A%2F%2Fgoogle.com%3Fparam%3D%5C%2Ffds");
    ASSERT_EQ(expected,result);
}

