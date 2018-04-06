cmake_minimum_required(VERSION 3.5)
project(Leto)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(include
        include/leto.h
        include/sensors/sensor.h include/sensors/temperature_sensor.h)

aux_source_directory(src sources)

add_library(Leto_core ${include} ${sources})
add_executable(Leto main.cpp)
target_link_libraries(Leto pthread)
target_link_libraries(Leto Leto_core)

# Unit testing ==========
configure_file(test/CMakeLists.txt test/gtest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download" )
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download" )

# available targets: gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/test/gtest-src" "${CMAKE_BINARY_DIR}/test/gtest-build")

enable_testing()
aux_source_directory(test test_src)

add_executable(Leto_test ${test_src})
target_link_libraries(Leto_test gtest gtest_main)
target_link_libraries(Leto_test Leto_core)
# Unit testing ----------
