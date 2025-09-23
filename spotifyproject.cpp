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
},

