cmake_minimum_required(VERSION 3.17)
project(image_processor)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

add_executable(image_processor
    image_processor.cpp
    lib/parser.cpp
    lib/bmp_picture.cpp
    lib/io.cpp
    lib/filters/filter.cpp
    lib/filters/grayscale.cpp
    lib/filters_factory.cpp
    lib/filters/negative.cpp
    lib/filters/crop.cpp
    lib/filters/sharpening.cpp
    lib/weighted_amount_of_colors.cpp
    lib/color.cpp
    lib/help.cpp
    lib/filters/edge_detection.cpp
    lib/filters/gaussian_blur.cpp
    lib/filters/pixellate.cpp
)
