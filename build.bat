mkdir build
cd build
cmake -G "CodeBlocks - MinGW Makefiles" ..
cmake --build . --target Leto  -- -j 4
cmake --build . --target Leto_test  -- -j 4

Leto_test.exe