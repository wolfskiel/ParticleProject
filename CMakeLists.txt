cmake_minimum_required(VERSION 3.10)

project(ParticleSimulator)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES
        Particle.cpp
        main.cpp
)


add_executable(ParticleSimulator ${SOURCE_FILES})
