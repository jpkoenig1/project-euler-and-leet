#!/bin/bashbash

# Clean build directory
rm -rf build/
mkdir build && cd build

# Configure with Ninja (or your preferred generator)
cmake  -G "Visual Studio 17 2022" .. -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build . --config Release --parallel 4

# Run a problem
# ./leetcode_framework two_sum
