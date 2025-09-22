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
};