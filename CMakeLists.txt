cmake_minimum_required(VERSION 3.25)
project(tracker LANGUAGES CXX)

# Set output directory for executable
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../output/ )

# Build static libraries for SFML to link
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_BUILD_TYPE DEBUG)
set(SFML_STATIC_LIBRARIES TRUE)

# Pull SFML if on Windows
if (WIN32)
include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
endif (WIN32)

include_directories(includes/)
file(GLOB SOURCES "src/*.cpp")
add_executable(tracker ${SOURCES})

# Link SFML static libs
target_link_libraries(tracker PRIVATE sfml-system sfml-graphics sfml-window)
target_compile_features(tracker PRIVATE cxx_std_17)
target_link_libraries(tracker ${SFML_LIBRARIES} ${SFML_DEPEDENCIES})

# Copy resources into output directory
file(COPY fonts/ DESTINATION "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/fonts/")

install(TARGETS tracker)
