cmake_minimum_required(VERSION 3.10)
project(Autocorrect_Levenshtein C)

set(CMAKE_C_STANDARD 11)

include_directories(./include)

set(SOURCE_FILES
        src/main.c)

set(HEADER_FILES
        include/main.h)

add_executable(Autocorrect_Levenshtein ${SOURCE_FILES} ${HEADER_FILES})
