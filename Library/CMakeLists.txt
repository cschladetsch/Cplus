cmake_minimum_required(VERSION 3.4)

set(root Library/)
include_directories(Include)
set(SOURCE_ROOT ${root}/*.c)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})
add_library(Library ${SOURCE_FILES})

