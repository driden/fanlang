#!/bin/bash

set -e

mkdir -p build

clang++ -std=c++17 -o build/fantasyc src/*.cpp
echo "Build complete! Run using ./build/fantasyc <file.fan> (--jit | --aot)"

#!/bin/bash
set -e  # Exit on first error

# Create build directory
mkdir -p build

# Compiler settings
CXX=clang++
CXXFLAGS="-std=c++17 -Wall -Wextra -pedantic"

# Compile source files
$CXX $CXXFLAGS -o build/fantasyc src/*.cpp

# INCLUDE_FLAGS="-I./src -I/usr/local/include -I/Library/Developer/CommandLineTools/usr/bin/../include/c++/v1 -I/Library/Developer/CommandLineTools/usr/include -I/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include"
# $CXX $CXXFLAGS $INCLUDE_FLAGS -o build/fantasyc src/*.cpp

echo "✅ Build successful! Run with: ./build/fantasyc <file.fan>"

