cmake_minimum_required(VERSION 3.10)
project(VGArchive)

set(CMAKE_CXX_STANDARD 14)

set(SQLite3_INCLUDE_DIRS /opt/homebrew/Cellar/sqlite/3.47.0/include)
set(SQLite3_LIBRARIES /opt/homebrew/Cellar/sqlite/3.47.0/lib/libsqlite3.dylib)

include_directories(${SQLite3_INCLUDE_DIRS})

add_executable(VGArchive src/main.cpp
        src/main.cpp)

target_link_libraries(VGArchive ${SQLite3_LIBRARIES})
