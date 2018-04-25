cmake_minimum_required(VERSION 3.5)
set(PROJECT_NAME Leto)
set(CORE_NAME ${PROJECT_NAME}_core)
set(TEST_NAME ${PROJECT_NAME}_test)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)
set(headers include/Leto.h include/utility/WebBrowser.h include/spotify/Auth.h include/storage/PairDB.h)
set(sources src/core/Leto.cpp src/core/spotify/AuthImpl.cpp src/core/spotify/config/Config.cpp include/spotify/AuthImpl.h include/spotify/config/Config.h src/core/utility/CurlEscape.cpp src/core/utility/CurlEscape.h src/core/spotify/AuthUrl.cpp src/core/spotify/AuthUrl.h src/core/storage/MemoryPairDB.cpp src/core/storage/MemoryPairDB.h)
add_library(${CORE_NAME} ${headers} ${sources})

# sqlite ==========
find_package(SQLite3 REQUIRED)
include_directories(${SQLITE3_INCLUDE_DIRS})
target_link_libraries(${CORE_NAME} ${SQLITE3_LIBRARIES})
# sqlite ----------

# curl ==========
find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(${CORE_NAME} ${CURL_LIBRARY})
# curl ----------

# json ==========
configure_file(libs/json.cmake libs/json/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/json/")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/json/")
add_subdirectory("${CMAKE_BINARY_DIR}/libs/json/source/" "${CMAKE_BINARY_DIR}/libs/json/build")
include_directories("${CMAKE_BINARY_DIR}/libs/json/source/include")
target_link_libraries(${CORE_NAME} nlohmann_json)
# json ----------

# web server ==========
configure_file(libs/web_server.cmake libs/web_server/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/web_server/")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/libs/web_server/")
add_subdirectory("${CMAKE_BINARY_DIR}/libs/web_server/source/" "${CMAKE_BINARY_DIR}/libs/web_server/build")
include_directories("${CMAKE_BINARY_DIR}/libs/web_server/source/include")
target_link_libraries(${CORE_NAME} simple-web-server)
# web server ----------

# main ==========
add_executable(${PROJECT_NAME} src/main/Main.cpp src/main/utility/NetSurf.cpp src/main/utility/NetSurf.h src/main/utility/Opera.cpp src/main/utility/Opera.h)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} ${CORE_NAME})
# main ----------

# main ==========
set(PROJECT_WIN ${PROJECT_NAME}_win)
add_executable(${PROJECT_WIN} src/main_win/Main.cpp src/main_win/utility/DefaultBrowser.cpp src/main_win/utility/DefaultBrowser.h)
target_link_libraries(${PROJECT_WIN} pthread)
target_link_libraries(${PROJECT_WIN} ${CORE_NAME})
# main ----------

# Unit testing ==========
configure_file(test/CMakeLists.txt test/gtest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")
execute_process(COMMAND "${CMAKE_COMMAND}" --build . WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/test/gtest-download")
# available targets: gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/test/gtest-src" "${CMAKE_BINARY_DIR}/test/gtest-build")

enable_testing()
add_executable(${TEST_NAME} test/LetoTest.cpp test/libs/curl/CurlTest.cpp test/libs/json/JsonTest.cpp test/libs/web_server/WebServerTest.cpp test/spotify/utility/CurlEscapeTest.cpp test/spotify/AuthImplTest.cpp test/mock/MockWebBrowser.h test/mock/MockWebBrowser.cpp test/libs/sqlite/SqliteTest.cpp test/storage/MemoryStorageTest.cpp)
target_link_libraries(${TEST_NAME} gtest gtest_main pthread)
target_link_libraries(${TEST_NAME} ${CORE_NAME})

SET(GCC_COVERAGE_COMPILE_FLAGS "-fprofile-arcs -ftest-coverage")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_test(${TEST_NAME} ${TEST_NAME})
# Unit testing ----------
