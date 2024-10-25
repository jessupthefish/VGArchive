
# VGArchive

A C++ and Python application for managing a video game database. Users can add, view, update, delete, and search game records, and even fetch new game data directly from the RAWG API.

## Project Structure

- **VGArchive/**: Main project folder
  - **src/**: Contains the main application code
    - `main.cpp`: Main C++ code for interacting with the database
    - `fetch_games.py`: Python script for fetching data from RAWG API
  - **data/**: Stores the SQLite database and SQL initialization script
    - `video_game_archive.db`: SQLite database file
    - `init_db.sql`: SQL script for initializing the database schema
  - `.gitignore`: To exclude certain files from version control
  - `README.md`: Project documentation
  - `CMakeLists.txt`: Build configuration for the C++ part

## Requirements

### System Requirements

- **C++ Compiler** (supporting C++11 or higher)
- **Python 3.12** or higher
- **SQLite3**

## Setup Instructions

### 1. Initialize the Database

To create the database schema, use the SQL initialization script:

```bash
sqlite3 data/video_game_archive.db < data/init_db.sql
```

### 2. Fetch Data from the RAWG API (Optional)

Populate the database with data from the RAWG API using `fetch_games.py`. This requires a RAWG API key.

- **Obtain an API key** from the RAWG website.
- Run the script and enter your API key when prompted:

  ```bash
  python3 src/fetch_games.py
  ```

  The script will populate the database with game data.

### 3. Build and Run the C++ Application

Build the C++ code using CMake:

```bash
mkdir build && cd build
cmake ..
make
./VGArchive
```

## Usage

When you run the C++ application (`VGArchive`), you will see a menu with the following options:

1. **Add Game**: Manually add a new game entry by entering details such as title, genre, release date, developer, platform, description, and rating.
2. **View All Games**: Display all games currently stored in the database.
3. **Update Game Rating**: Update the rating of a specified game by its title.
4. **Delete Game**: Delete a game entry from the database by its title.
5. **Search Game**: Search for games by title, genre, or platform.
6. **Exit**: Close the application.
7. **Fetch New Data from API**: Run the Python script to fetch game data from the RAWG API. This option will prompt for an API key if not already provided.

## Example Workflow

- **Add Game**: Input game details manually to populate the database with a custom entry.
- **Fetch New Data from API** (Option 7): If you wish to automatically fetch game data from RAWG, select this option and enter your API key.
- **View and Search**: Use options 2 and 5 to view and search for specific games in the database.
- **Update or Delete**: Modify game entries with options 3 and 4.

## Notes on API Usage

- **API Key Requirement**: To fetch data from the RAWG API, you must obtain an API key and enter it when prompted.
- **Optional Fetch**: Fetching from the API is optional. You can still use the application with manually entered data.

## Contributions

Contributions are welcome. Please open an issue or submit a pull request for any changes.

## Acknowledgments

- **RAWG API**: This application uses the RAWG API to fetch video game data.
- **SQLite**: SQLite is used as the database engine for storing game data.
