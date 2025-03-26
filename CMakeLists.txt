cmake_minimum_required(VERSION 3.31)

set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(REPO_URL "https://github.com/v-maxson/snek")

# Config
project(
        snek
        LANGUAGES C
        VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_SOURCE src/*.c)

include_directories(./include)
file(GLOB_RECURSE PROJECT_HEADERS include/*.h)

# Generate version.h
set(GENERATED_HEADERS_DIR ${CMAKE_BINARY_DIR}/${PROJECT_NAME}_generated)
configure_file(include/version.h.in ${GENERATED_HEADERS_DIR}/version.h)
include_directories(${GENERATED_HEADERS_DIR})

# Compilation
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE} ${PROJECT_HEADERS})

# Dependencies