cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME Leto)
set(CORE_NAME ${PROJECT_NAME}_core)
set(TEST_NAME ${PROJECT_NAME}_test)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(include
        include/leto.h
        include/sensors/sensor.h include/sensors/temperature_sensor.h)

aux_source_directory(src sources)

add_library(${CORE_NAME} ${include} ${sources})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} ${CORE_NAME})

# Unit testing ==========
configure_file(test/CMakeLists.txt test/gtest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")

# available targets: gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/test/gtest-src" "${CMAKE_BINARY_DIR}/test/gtest-build")

enable_testing()
aux_source_directory(test test_src)

add_executable(${TEST_NAME} ${test_src})
target_link_libraries(${TEST_NAME} gtest gtest_main)
target_link_libraries(${TEST_NAME} ${CORE_NAME})

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_test(${TEST_NAME} ${TEST_NAME})
# Unit testing ----------
