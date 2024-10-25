import requests
import sqlite3
import os

# API and Database Configurations
API_KEY = "b6435cd3f8734635b7151575475276a4"
BASE_URL = "https://api.rawg.io/api/games"
DB_PATH = "/Users/stevenjessup/Desktop/VGarchive/video_game_archive.db"

# Function to fetch data from the API
def fetch_game_data(page=1):
    params = {
        "key": API_KEY,
        "page": page,
        "page_size": 100  # Number of games per page; adjust as needed
    }
    response = requests.get(BASE_URL, params=params)
    response.raise_for_status()  # Raise an error for bad responses
    return response.json()

# Function to insert data into the database
def insert_into_db(game_data):
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()

    for game in game_data['results']:
        title = game.get('name')
        genre = ", ".join([genre['name'] for genre in game.get('genres', [])])  # Join multiple genres
        release_date = game.get('released')
        developer = game.get('developers', [{}])[0].get('name', 'Unknown')  # Only first developer listed
        platform = ", ".join([platform['platform']['name'] for platform in game.get('platforms', [])])
        description = game.get('description', 'No description available')
        rating = game.get('rating')

        # Insert the data into the database
        cursor.execute('''
            INSERT INTO Games (Title, Genre, ReleaseDate, Developer, Platform, Description, Rating) 
            VALUES (?, ?, ?, ?, ?, ?, ?)''', (title, genre, release_date, developer, platform, description, rating))

    conn.commit()
    conn.close()
    print("Data inserted successfully")

def main():
    page = 1
    while page <= 5:  # Fetch first 5 pages, adjust as needed
        print(f"Fetching data for page {page}")
        game_data = fetch_game_data(page)
        insert_into_db(game_data)
        page += 1

if __name__ == "__main__":
    main()
