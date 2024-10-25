-- init_db.sql

-- Create the Games table if it doesn't already exist
CREATE TABLE IF NOT EXISTS Games (
    GameID INTEGER PRIMARY KEY AUTOINCREMENT,
    Title TEXT NOT NULL,
    Genre TEXT,
    ReleaseDate TEXT,
    Developer TEXT,
    Publisher TEXT,
    Platform TEXT,
    Description TEXT,
    Rating REAL
);

-- Create the Reviews table if it doesn't already exist
CREATE TABLE IF NOT EXISTS Reviews (
    ReviewID INTEGER PRIMARY KEY AUTOINCREMENT,
    UserID INTEGER,
    GameID INTEGER,
    ReviewText TEXT,
    Rating REAL,
    FOREIGN KEY(GameID) REFERENCES Games(GameID)
);

-- Optionally, insert some sample data to work with
INSERT INTO Games (Title, Genre, ReleaseDate, Developer, Platform, Description, Rating)
VALUES ('The Legend of Zelda', 'Action-Adventure', '1986-02-21', 'Nintendo', 'NES', 'A classic adventure game', 9.5);

INSERT INTO Games (Title, Genre, ReleaseDate, Developer, Platform, Description, Rating)
VALUES ('Super Mario Bros.', 'Platformer', '1985-09-13', 'Nintendo', 'NES', 'A revolutionary platform game', 9.7);
