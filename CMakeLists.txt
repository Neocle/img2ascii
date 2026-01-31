cmake_minimum_required(VERSION 4.1)
project(img2ascii)

set(CMAKE_CXX_STANDARD 20)

find_package(OpenCV REQUIRED)

include_directories(include/img2ascii)
add_executable(
        img2ascii
        src/main.cpp
        src/core/Image.cpp
        src/core/Palette.cpp
        src/core/Arguments.cpp
        src/core/ImageConverter.cpp
        src/ascii/AsciiArt.cpp
)

target_link_libraries(img2ascii PRIVATE ${OpenCV_LIBS})
