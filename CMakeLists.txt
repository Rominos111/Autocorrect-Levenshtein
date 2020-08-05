cmake_minimum_required(VERSION 3.10)
project(Autocorrect_Levenshtein C)

set(CMAKE_C_STANDARD 11)

include_directories(./include)

set(HEADER_FILES
        include/main.h
        include/types.h
        include/queue.h)

set(SOURCE_FILES
        src/dictionary.c
        src/main.c
        src/queue.c)

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
#  -std=c11

add_executable(Autocorrect_Levenshtein ${SOURCE_FILES} ${HEADER_FILES})
