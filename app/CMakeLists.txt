cmake_minimum_required(VERSION 3.22.1)
project("edgedetectionviewer")

set(OpenCV_DIR "E:\opencv-android-sdk\opencv")
find_package(OpenCV REQUIRED)

add_library(edge-detection-lib SHARED
        src/main/cpp/edge-detection.cpp)

target_link_libraries(edge-detection-lib
        ${OpenCV_LIBS})

target_include_directories(edge-detection-lib PRIVATE
        ${OpenCV_INCLUDE_DIRS})
