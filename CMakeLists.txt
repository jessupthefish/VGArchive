cmake_minimum_required(VERSION 3.10)
project(VGarchive)

set(CMAKE_CXX_STANDARD 14)

set(SQLite3_INCLUDE_DIRS /opt/homebrew/Cellar/sqlite/3.47.0/include)
set(SQLite3_LIBRARIES /opt/homebrew/Cellar/sqlite/3.47.0/lib/libsqlite3.dylib)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(VGarchive main.cpp)

target_link_libraries(VGarchive ${SQLite3_LIBRARIES})
