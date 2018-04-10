cmake_minimum_required(VERSION 2.8.2)

project(curl)

include(ExternalProject)
ExternalProject_Add(curl
        GIT_REPOSITORY https://github.com/curl/curl.git
        GIT_TAG master
        SOURCE_DIR "${CMAKE_BINARY_DIR}/libs/curl/source"
        BINARY_DIR "${CMAKE_BINARY_DIR}/libs/curl/build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
)