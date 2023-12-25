cmake_minimum_required(VERSION 3.10)

project(Physics-Simulator)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        Particle.cpp
        main.cpp
)

include_directories(path/to/library/include)

target_link_libraries(Physics-Simulator path/to/library/bin/libraryfile)

add_executable(Physics-Simulator ${SOURCE_FILES})
