cmake_minimum_required(VERSION 3.10)
project(playground)

set(CMAKE_OSX_ARCHITECTURES "arm64") 
# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.0
        GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

# Add an executable
add_executable(playground main.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
