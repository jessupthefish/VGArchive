
# Video Game Archive

A C++ and Python application for managing a video game database. Users can add, view, update, delete, and search game records, with optional data fetching from the RAWG API to update the database.

## Project Structure

* **VGArchive/**: Main project folder
  * **src/**: Contains the main application code
    * `main.cpp`: Main C++ file for database interactions
    * `fetch_games.py`: Python script to fetch data from the RAWG API
  * **data/**: Stores the SQLite database and SQL initialization script
    * `video_game_archive.db`: SQLite database file
    * `init_db.sql`: SQL script to initialize the database schema, if needed
  * `.gitignore`: Excludes specific files from version control
  * `README.md`: Project documentation
  * `CMakeLists.txt`: Build configuration for C++

## Requirements

### System Requirements

- **C++ Compiler**
- **Python 3.12** or higher
- **SQLite3**

## Setup Instructions

### 1. Database Setup

The project includes a pre-existing SQLite database (`video_game_archive.db`) in the `data/` folder, which should be ready to use. If you need to repopulate the database, use the `fetch_games.py` script with a RAWG API key.

### 2. Fetch Data from the RAWG API (Optional)

To update the database with the latest data from the RAWG API, use `fetch_games.py`. This requires a RAWG API key, which should be set as an environment variable for secure handling.

- **Set the Environment Variable**:
  - In your terminal, set the API key for the session by running:
    ```bash
    export RAWG_API_KEY="your_actual_api_key"
    ```
  - This will make the API key available to the `fetch_games.py` script when it's run.

- Run the script with Python, entering your API key when prompted:

  ```bash
  python3 src/fetch_games.py
  ```

  This will update the database with new game data.

### 3. Build and Run the C++ Application

To compile and run the application, use the provided CMake configuration.

```bash
mkdir build && cd build
cmake ..
make
./VGArchive
```

## Usage

When you run the C++ application (`VGArchive`), the following menu options are available:

1. **Add Game**: Enter details to add a new game (title, genre, release date, developer, platform, description, and rating).
2. **View All Games**: Display all games currently stored in the database.
3. **Update Game Rating**: Update the rating for a specific game by its title.
4. **Delete Game**: Delete a game entry from the database by its title.
5. **Search Game**: Search for games by title, genre, or platform.
6. **Exit**: Close the application.
7. **Fetch New Data from API**: Run the Python script to refresh game data in the database.

## Notes on API Usage

- **API Key Requirement**: To fetch data from the RAWG API, obtain an API key and set it as the `RAWG_API_KEY` environment variable.
- **Optional Fetch**: Fetching from the API is only necessary to update or refresh the database. The program will function with the provided `video_game_archive.db`.

## Contributions

Contributions are welcome. Please open an issue or submit a pull request for any changes.

## Acknowledgments

- **RAWG API**: Used to fetch game data updates.
- **SQLite**: SQLite is the database engine used to store game data.
