cmake_minimum_required(VERSION 3.10)
project(Autocorrect_Levenshtein C)

set(CMAKE_C_STANDARD 11)

include_directories(./include)

set(HEADER_FILES
        include/dictionary.h
        include/levenshtein.h
        include/main.h
        include/queue.h
        include/utils.h
        )

set(SOURCE_FILES
        src/dictionary.c
        src/levenshtein.c
        src/main.c
        src/queue.c
        src/utils.c
        )

set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c11")

add_executable(Autocorrect_Levenshtein ${SOURCE_FILES} ${HEADER_FILES})
