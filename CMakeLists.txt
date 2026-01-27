cmake_minimum_required(VERSION 3.5)
project(CPP_TP5_JACK_ANNA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

file(MAKE_DIRECTORY output) # Create directory for outputs

set(sources
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/ecrire/main.cpp
    # ${CMAKE_CURRENT_SOURCE_DIR}/src/ecrire/Semaphore.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/threadTrains/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/threadTrains/Controleur.hpp

)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

add_compile_definitions(PROJECT_PATH="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(CPP_TP5_JACK_ANNA ${sources})