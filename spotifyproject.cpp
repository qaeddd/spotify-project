// ====================
// Qaed's Initial Commit: Project setup, class skeleton, and basic data structure
// ====================
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

// SpotifyAssistant class manages a simple artist/album database
class SpotifyAssistant
{
private:
    // Stores artist names and their albums
    std::map<std::string, std::vector<std::string>> artistAlbums;

    // Converts a string to lowercase for case-insensitive searching
    std::string toLower(const std::string &str)
    {
        std::string result = str;
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        return result;
    }

public:
    // Constructor: initializes the sample data
    SpotifyAssistant()
    {
        // Initialize with some sample data
        initializeSampleData();
    }

    // Populates the database with sample artists and their albums
    void initializeSampleData()
    {
        artistAlbums["taylor swift"] = {
            "Taylor Swift", "Fearless", "Speak Now", "Red", "1989",
            "Reputation", "Lover", "Folklore", "Evermore", "Midnights"};

        artistAlbums["ed sheeran"] = {
            "Plus", "Multiply", "Divide", "No.6 Collaborations Project", "Equals", "Subtract"};

        artistAlbums["the beatles"] = {
            "Please Please Me", "With the Beatles", "A Hard Day's Night", "Beatles for Sale",
            "Help!", "Rubber Soul", "Revolver", "Sgt. Pepper's Lonely Hearts Club Band",
            "Magical Mystery Tour", "The Beatles (White Album)", "Yellow Submarine",
            "Abbey Road", "Let It Be"};

        artistAlbums["drake"] = {
            "Thank Me Later", "Take Care", "Nothing Was the Same", "Views", "Scorpion",
            "Certified Lover Boy", "Honestly, Nevermind", "Her Loss"};

        artistAlbums["billie eilish"] = {
            "When We All Fall Asleep, Where Do We Go?", "Happier Than Ever"};

        // New artists added
        artistAlbums["travis scott"] = {
            "Owl Pharaoh", "Days Before Rodeo", "Rodeo", "Birds in the Trap Sing McKnight",
            "Astroworld", "Jackboys", "Utopia"};

        artistAlbums["justin bieber"] = {
            "My World 2.0", "Under the Mistletoe", "Believe", "Purpose",
            "Changes", "Justice", "Ghost Stories"};

        artistAlbums["hujan"] = {
            "Hiba", "Aku Scandal", "Pagi Yang Gelap", "Kotak Hati",
            "Muda"};

        artistAlbums["sza"] = {
            "See.SZA.Run", "S", "Z", "Ctrl", "SOS"};

        artistAlbums["one direction"] = {
            "Up All Night", "Take Me Home", "Midnight Memories", "Four", "Made in the A.M."};
    }

    // ====================
    // Haiqal's Commit: Search and display functionality
    // ====================

    // Searches for albums by artist name (case-insensitive, supports partial match)
    std::vector<std::string> searchAlbums(const std::string &artistName)
    {
        std::string searchKey = toLower(artistName);

        // Direct match
        auto it = artistAlbums.find(searchKey);
        if (it != artistAlbums.end())
        {
            return it->second;
        }

        // Partial match search
        for (const auto &pair : artistAlbums)
        {
            if (pair.first.find(searchKey) != std::string::npos)
            {
                return pair.second;
            }
        }

        // Return empty vector if no match found
        return std::vector<std::string>();
    }

    // Displays the albums of a given artist in a formatted way
    void displayAlbums(const std::string &artistName, const std::vector<std::string> &albums)
    {
        if (albums.empty())
        {
            std::cout << "No albums found for artist: " << artistName << std::endl;
            std::cout << "Please check the spelling or try another artist." << std::endl;
            return;
        }

        std::cout << "\n"
                  << std::string(50, '=') << std::endl;
        std::cout << "Albums by " << artistName << ":" << std::endl;
        std::cout << std::string(50, '=') << std::endl;

        // List albums with numbering
        for (size_t i = 0; i < albums.size(); ++i)
        {
            std::cout << (i + 1) << ". " << albums[i] << std::endl;
        }

        std::cout << "\nTotal albums found: " << albums.size() << std::endl;
        std::cout << std::string(50, '=') << std::endl;
    }

    // Adds a new artist and their albums to the database
    void addArtist(const std::string &artistName, const std::vector<std::string> &albums)
    {
        std::string key = toLower(artistName);
        artistAlbums[key] = albums;
        std::cout << "Artist '" << artistName << "' added successfully!" << std::endl;
    }

    // ====================
    // Danish Commit: Artist listing, interactive menu, and main function
    // ====================

    // Lists all artists in the database with numbering and album count
    void listAllArtists()
    {
        std::cout << "\nAvailable artists in database:" << std::endl;
        std::cout << std::string(30, '-') << std::endl;

        int idx = 1;
        for (const auto &pair : artistAlbums)
        {
            std::cout << idx << ". " << pair.first << " (" << pair.second.size() << " albums)" << std::endl;
            idx++;
        }
    }

    // Runs the interactive menu for searching and listing artists/albums
    void runInteractiveSearch()
    {
        std::string input;

        while (true)
        {
            // Display menu
            std::cout << "\n"
                      << std::string(60, '*') << std::endl;
            std::cout << "         SPOTIFY ALBUM SEARCH ASSISTANT" << std::endl;
            std::cout << std::string(60, '*') << std::endl;
            std::cout << "Options:" << std::endl;
            std::cout << "1. Search for albums by artist name" << std::endl;
            std::cout << "2. List all available artists" << std::endl;
            std::cout << "3. Exit" << std::endl;
            std::cout << "\nEnter your choice (1-3): ";

            std::getline(std::cin, input);

            // Handle user input
            if (input == "1")
            {
                std::cout << "\nEnter artist name: ";
                std::string artistName;
                std::getline(std::cin, artistName);

                if (!artistName.empty())
                {
                    std::vector<std::string> albums = searchAlbums(artistName);
                    displayAlbums(artistName, albums);
                }
                else
                {
                    std::cout << "Please enter a valid artist name." << std::endl;
                }
            }
            else if (input == "2")
            {
                listAllArtists();
            }
            else if (input == "3")
            {
                std::cout << "Thank you for using Spotify Album Search Assistant!" << std::endl;
                break;
            }
            else
            {
                std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
            }
        }
    }
};

// qaed commit : Main function added in final commit
int main()
{
    SpotifyAssistant assistant;
    assistant.runInteractiveSearch();
    return 0;

}
