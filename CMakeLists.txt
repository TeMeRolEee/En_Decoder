cmake_minimum_required(VERSION 2.8.11)

project(En_Decoder)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core HINTS ~/Qt/5.11.1/gcc_64/)
find_package(Qt5Widgets HINTS ~/Qt/5.11.1/gcc_64/)
find_package(QFile HINTS ~/Qt/5.11.1/gcc_64/)

# compiling
file(GLOB sources *.cpp)

add_executable(En_Decoder
        ${sources} Decoder.h Dictionary.h Encoder.cpp En_Decoder.cpp Decoder.cpp Dictionary.cpp Encoder.h)

# linking
target_link_libraries(En_Decoder Qt5::Core)
target_link_libraries(En_Decoder Qt5::Widgets)
