cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME Leto)
set(CORE_NAME ${PROJECT_NAME}_core)
set(TEST_NAME ${PROJECT_NAME}_test)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
set(headers include/leto.h include/sensors/sensor.h include/temperature/temperature.h)
set(sources src/leto.cpp)
add_library(${CORE_NAME} ${headers} ${sources})

# curl ==========
configure_file(libs/curl/CMakeLists.txt libs/curl/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/curl")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/curl/")
add_subdirectory("${CMAKE_BINARY_DIR}/libs/curl/source/" "${CMAKE_BINARY_DIR}/libs/curl/build")
include_directories("${CMAKE_BINARY_DIR}/libs/curl/source/include")
target_link_libraries(${CORE_NAME} libcurl)
# curl ----------

# main ==========
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} ${CORE_NAME})
# main ----------

# Unit testing ==========
configure_file(test/CMakeLists.txt test/gtest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")
# available targets: gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/test/gtest-src" "${CMAKE_BINARY_DIR}/test/gtest-build")

enable_testing()
set(test_src test/leto_test.cpp test/libs/curl/edge.cpp)
add_executable(${TEST_NAME} ${test_src})
target_link_libraries(${TEST_NAME} gtest gtest_main)
target_link_libraries(${TEST_NAME} ${CORE_NAME})

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_test(${TEST_NAME} ${TEST_NAME})
# Unit testing ----------
