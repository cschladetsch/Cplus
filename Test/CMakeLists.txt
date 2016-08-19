cmake_minimum_required(VERSION 3.4)

set(root Test/)
include_directories(Include /usr/local/Cellar/cunit/2.1-3/include)
set(SOURCE_ROOT ${root}/*.c)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})

link_directories(lib /usr/local/lib /usr/local/Cellar/cunit/2.1-3/lib)
link_libraries(Library)
link_libraries(cunit)

add_executable(Test ${SOURCE_FILES})
