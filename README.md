# VG Archive

A C++ command-line application for managing a video game database, backed by
SQLite. Add, view, update, delete, and search game records.

This was the first project I built.

## Requirements

- A C++ compiler
- CMake
- SQLite3

## Build and run

```bash
cmake -B build
cmake --build build
./build/VGArchive
```

Run it from the project root. The database path is relative (`data/video_game_archive.db`),
so launching the binary from inside `build/` will fail to open it.

## Usage

The application presents a menu:

1. **Add Game**: enter title, genre, release date, developer, platform, description, and rating
2. **View All Games**: display everything currently stored
3. **Update Game Rating**: change the rating for a game by title
4. **Delete Game**: remove a game by title
5. **Search Game**: search by title, genre, or platform
6. **Exit**

## Project structure

```
src/
  main.cpp                 # Application and all database interactions
data/
  video_game_archive.db    # Pre-populated SQLite database
  init_db.sql              # Schema initialization script
CMakeLists.txt             # Build configuration
```

The included database is ready to use. To start from an empty one, create it
from the schema:

```bash
sqlite3 data/video_game_archive.db < data/init_db.sql
```

## Acknowledgments

- **SQLite**: the database engine used to store game data.
