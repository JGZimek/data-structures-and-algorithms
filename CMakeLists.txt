cmake_minimum_required(VERSION 3.10)
project(data-structures-and-algorithms LANGUAGES CXX)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the output directory for executables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Enable testing so that CTest can find the test configuration
enable_testing()

# Add subdirectories for source code and tests
add_subdirectory(src)
add_subdirectory(tests)
