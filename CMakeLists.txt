cmake_minimum_required(VERSION 3.10)
project(VGArchive)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SQLite3 REQUIRED)

add_executable(VGArchive src/main.cpp)

target_include_directories(VGArchive PRIVATE ${SQLite3_INCLUDE_DIRS})
target_link_libraries(VGArchive PRIVATE ${SQLite3_LIBRARIES})
