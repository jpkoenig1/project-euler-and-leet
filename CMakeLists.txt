cmake_minimum_required(VERSION 3.20)

project(leetcode_framework LANGUAGES CXX)

# Set C++ standard and enforce it
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Recursively find all .cpp files in leetcode/ and project_euler/
file(GLOB_RECURSE PROBLEM_SOURCES
    "leetcode/*.cpp"
    "project_euler/*.cpp"
)

# Add the main executable (assumes your main.cpp is in the root)
add_executable(${PROJECT_NAME}
    main.cpp
    ${PROBLEM_SOURCES}
)

# Optionally, include directories if you have headers outside the source dirs
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# (Optional) Enable warnings for MSVC and other compilers
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4 /permissive-)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()
