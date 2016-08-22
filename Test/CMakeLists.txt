cmake_minimum_required(VERSION 3.4)

set(root Test/)
include_directories(Include
        /usr/local/Cellar/cunit/2.1-3/include
        /usr/local/Cellar/valgrind/3.11.0/include
        )
set(SOURCE_ROOT ${root}/*.c)
file(GLOB_RECURSE SOURCE_FILES ${SOURCE_ROOT})

link_directories(lib /usr/local/lib
        /usr/local/Cellar/cunit/2.1-3/lib
        /usr/local/Cellar/valgrind/3.11.0/lib
         )
link_libraries(Library cunit)
#link_libraries(cunit valgrind)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY Bin)
add_executable(Test ${SOURCE_FILES})
