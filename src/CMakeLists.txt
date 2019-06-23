cmake_minimum_required(VERSION 3.0)

project(a2600)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH "../../bin")

file(GLOB a2600_SRC
    "*.h"
    "*.cpp"
)

add_executable(a2600
    ${a2600_SRC}
)