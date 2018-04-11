cmake_minimum_required(VERSION 2.8.2)

project(web_server)

include(ExternalProject)
ExternalProject_Add(web_server
        GIT_REPOSITORY https://github.com/eidheim/Simple-Web-Server.git
        GIT_TAG master
        SOURCE_DIR "${CMAKE_BINARY_DIR}/libs/web_server/source"
        BINARY_DIR "${CMAKE_BINARY_DIR}/libs/web_server/build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        )