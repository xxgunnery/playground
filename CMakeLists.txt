cmake_minimum_required(VERSION 3.10)
project(playground)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_SHALLOW 1
    )
    FetchContent_MakeAvailable(raylib)
endif()

include_directories(src/include src/include/external)

# Add an executable
add_executable(playground 
    src/main.cpp
    src/Game.cpp
    src/ResourceManager.cpp
    src/TextManager.cpp
)

add_custom_command(
  TARGET playground 
  POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_directory 
  ${CMAKE_SOURCE_DIR}/assets 
  ${CMAKE_BINARY_DIR}/$<CONFIG>/assets
)

target_link_libraries(${PROJECT_NAME} PUBLIC raylib)

