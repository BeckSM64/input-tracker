cmake_minimum_required(VERSION 3.25)
project(tracker LANGUAGES CXX)

set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_TYPE DEBUG)
set(SFML_STATIC_LIBRARIES TRUE)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(tracker src/main.cpp)
target_link_libraries(tracker PRIVATE sfml-system sfml-graphics sfml-window)
target_compile_features(tracker PRIVATE cxx_std_17)
target_link_libraries(tracker ${SFML_LIBRARIES} ${SFML_DEPEDENCIES})

install(TARGETS tracker)
