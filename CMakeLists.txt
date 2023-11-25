cmake_minimum_required(VERSION 3.26)
project(Main C)

set(CMAKE_C_STANDARD 11)

# source code directory
set(SRC_DIR "src")

# daily source code directory
set(DAILY_SRC_DIR "src/_2023_11_25")

# header files
include_directories(${DAILY_SRC_DIR})

# add exec
add_executable(Main ${SRC_DIR}/main.c ${DAILY_SRC_DIR}/daily.c)
