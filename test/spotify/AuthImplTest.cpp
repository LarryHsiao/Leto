//
// Created by Larry Hsiao on 4/14/2018.
//

#include <gtest/gtest.h>
#include "spotify/AuthImpl.h"
#include "../mock/MockWebBrowser.h"

TEST(AuthImpl, triggered){
    bool launched =false;
    Config config = Config();
    MockWebBrowser webBrowser([&](){
        launched = true;
    });
    AuthImpl auth(config, &webBrowser);
    auth.launch();
    ASSERT_TRUE(launched);
}