cmake_minimum_required(VERSION 3.22.1)
project("edgedetectionviewer")

# Add the native library
add_library(edge-detection-lib SHARED
        src/main/cpp/edge-detection.cpp
)

# Include directories
target_include_directories(edge-detection-lib PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp
)
