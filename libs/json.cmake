cmake_minimum_required(VERSION 2.8.2)

project(json)

include(ExternalProject)
ExternalProject_Add(json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.1.2
        SOURCE_DIR "${CMAKE_BINARY_DIR}/libs/json/source"
        BINARY_DIR "${CMAKE_BINARY_DIR}/libs/json/build"
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
        TEST_COMMAND ""
        )