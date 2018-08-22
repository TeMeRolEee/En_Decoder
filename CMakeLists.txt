cmake_minimum_required(VERSION 2.8.11)

project(En_Decoder)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core HINTS ~/Qt/5.11.1/gcc_64/)

# compiling
add_executable(En_Decoder main.cpp Encoder.cpp Decoder.cpp Dictionary.cpp)

# copy dict to build dir
configure_file(dict.json dict.json COPYONLY)

# linking
target_link_libraries(En_Decoder Qt5::Core Qt5::Core)
