cmake_minimum_required(VERSION 3.26)
project(Main C)

set(CMAKE_C_STANDARD 11)

# header files
include_directories("src/_2023_11_14_1")

# source code directory
set(SRC_DIR "src")

# add exec
add_executable(Main ${SRC_DIR}/main.c ${SRC_DIR}/_2023_11_14_1/daily.c)
