#include <iostream>
#include <sqlite3.h>
#include <string>

// Function to add a game to the database
int addGame(sqlite3* db, const std::string& title, const std::string& genre, const std::string& releaseDate,
            const std::string& developer, const std::string& platform, const std::string& description, double rating) {
    std::string sql = "INSERT INTO Games (Title, Genre, ReleaseDate, Developer, Platform, Description, Rating) VALUES ('" +
                      title + "', '" + genre + "', '" + releaseDate + "', '" + developer + "', '" + platform + "', '" +
                      description + "', " + std::to_string(rating) + ");";

    char* errMsg = 0;
    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);

    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return rc;
    }

    std::cout << "Game added successfully!" << std::endl;
    return rc;
}

// Function to fetch and display all games in the database
int fetchGames(sqlite3* db) {
    std::string sql = "SELECT * FROM Games;";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch games: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "GameID: " << sqlite3_column_int(stmt, 0) << std::endl;

        const unsigned char* title = sqlite3_column_text(stmt, 1);
        std::cout << "Title: " << (title ? (const char*)title : "N/A") << std::endl;

        const unsigned char* genre = sqlite3_column_text(stmt, 2);
        std::cout << "Genre: " << (genre ? (const char*)genre : "N/A") << std::endl;

        const unsigned char* releaseDate = sqlite3_column_text(stmt, 3);
        std::cout << "Release Date: " << (releaseDate ? (const char*)releaseDate : "N/A") << std::endl;

        const unsigned char* developer = sqlite3_column_text(stmt, 4);
        std::cout << "Developer: " << (developer ? (const char*)developer : "N/A") << std::endl;

        const unsigned char* platform = sqlite3_column_text(stmt, 5);
        std::cout << "Platform: " << (platform ? (const char*)platform : "N/A") << std::endl;

        const unsigned char* description = sqlite3_column_text(stmt, 6);
        std::cout << "Description: " << (description ? (const char*)description : "N/A") << std::endl;

        if (sqlite3_column_type(stmt, 7) != SQLITE_NULL) {
            std::cout << "Rating: " << sqlite3_column_double(stmt, 7) << std::endl;
        } else {
            std::cout << "Rating: N/A" << std::endl;
        }

        std::cout << "-----------------------------" << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}


// Function to update a game's rating
int updateGameRating(sqlite3* db, const std::string& title, double newRating) {
    std::string sql = "UPDATE Games SET Rating = " + std::to_string(newRating) + " WHERE Title = '" + title + "';";
    char* errMsg = 0;

    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return rc;
    }

    std::cout << "Game rating updated successfully!" << std::endl;
    return rc;
}

// Function to delete a game by title
int deleteGame(sqlite3* db, const std::string& title) {
    std::string sql = "DELETE FROM Games WHERE Title = '" + title + "';";
    char* errMsg = 0;

    int rc = sqlite3_exec(db, sql.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
        return rc;
    }

    std::cout << "Game deleted successfully!" << std::endl;
    return rc;
}

// Function to search for games by title, genre, or platform
int searchGames(sqlite3* db, const std::string& field, const std::string& value) {
    std::string sql = "SELECT * FROM Games WHERE " + field + " LIKE '%" + value + "%';";
    sqlite3_stmt* stmt;

    int rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, 0);
    if (rc != SQLITE_OK) {
        std::cerr << "Failed to fetch games: " << sqlite3_errmsg(db) << std::endl;
        return rc;
    }

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        std::cout << "GameID: " << sqlite3_column_int(stmt, 0) << std::endl;
        std::cout << "Title: " << sqlite3_column_text(stmt, 1) << std::endl;
        std::cout << "Genre: " << sqlite3_column_text(stmt, 2) << std::endl;
        std::cout << "Release Date: " << sqlite3_column_text(stmt, 3) << std::endl;
        std::cout << "Developer: " << sqlite3_column_text(stmt, 4) << std::endl;
        std::cout << "Platform: " << sqlite3_column_text(stmt, 5) << std::endl;
        std::cout << "Description: " << sqlite3_column_text(stmt, 6) << std::endl;
        std::cout << "Rating: " << sqlite3_column_double(stmt, 7) << std::endl;
        std::cout << "-----------------------------" << std::endl;
    }

    sqlite3_finalize(stmt);
    return rc;
}

// Input validation functions
bool isValidRating(double rating) {
    return rating >= 0.0 && rating <= 10.0;
}

bool isNotEmpty(const std::string& input) {
    return !input.empty();
}


int main() {
    sqlite3* db;
    int exit = sqlite3_open("data/video_game_archive.db", &db);
    if (exit) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        return -1;
    }

    int choice;
    while (true) {
        std::cout << "\n1. Add Game\n2. View All Games\n3. Update Game Rating\n4. Delete Game\n5. Search Game\n6. Exit\n7. Fetch New Data from API\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // Logic to add a game
            std::string title, genre, releaseDate, developer, platform, description;
            double rating;

            std::cout << "Enter title: "; std::cin >> title;
            std::cout << "Enter genre: "; std::cin >> genre;
            std::cout << "Enter release date: "; std::cin >> releaseDate;
            std::cout << "Enter developer: "; std::cin >> developer;
            std::cout << "Enter platform: "; std::cin >> platform;
            std::cout << "Enter description: "; std::cin.ignore(); std::getline(std::cin, description);
            std::cout << "Enter rating: "; std::cin >> rating;

            addGame(db, title, genre, releaseDate, developer, platform, description, rating);

        } else if (choice == 2) {
            // View all games
            fetchGames(db);

        } else if (choice == 3) {
            // Update game rating
            std::string title;
            double newRating;
            std::cout << "Enter title of the game to update: "; std::cin >> title;
            std::cout << "Enter new rating: "; std::cin >> newRating;
            updateGameRating(db, title, newRating);

        } else if (choice == 4) {
            // Delete game
            std::string title;
            std::cout << "Enter title of the game to delete: "; std::cin >> title;
            deleteGame(db, title);

        } else if (choice == 5) {
            // Search for a game
            std::string field, value;
            std::cout << "Search by (title/genre/platform): "; std::cin >> field;
            std::cout << "Enter value to search: "; std::cin >> value;
            searchGames(db, field, value);

        } else if (choice == 6) {
            // Exit
            break;

        } else if (choice == 7) {
            // Fetch data from API
            std::cout << "Running fetch_games.py to fetch data from the RAWG API...\n";
            int result = system("python3 src/fetch_games.py");
            if (result == 0) {
                std::cout << "Data fetched successfully!\n";
            } else {
                std::cout << "Failed to fetch data. Please ensure Python and the necessary packages are installed.\n";
            }

        } else {
            std::cout << "Invalid choice, please try again." << std::endl;
        }
    }

    sqlite3_close(db);
    return 0;
}
