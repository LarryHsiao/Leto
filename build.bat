mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=%Phantom_Libs% -G "CodeBlocks - MinGW Makefiles" ..
cmake --build . --target Leto_win  -- -j 4
cmake --build . --target Leto_test  -- -j 4

Leto_test.exe