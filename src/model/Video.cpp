#include <iostream>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>

using namespace std;
using json = nlohmann::json;

struct VideoStruct
{
    string title;
    string genre;
    int year;
    int copies_available;
    
};

class Video
{
private:
    string title;
    string genre;
    int year;
    int copies_available;
    

public:
    Video(string t, string g, int y, int ca)
    {
        title = t;
        genre = g;
        year = y;
        copies_available = ca;

    }

    string getTitle()
    {
        return title;
    }
    string getGenre()
    {
        return genre;
    }
    int getYear()
    {
        return year;
    }
    int getCopiesAvailable()
    {
        return copies_available;
    }
    string checkout(){
        if (copies_available > 0){
            return "Checkout Successful: " + to_string(copies_available) + " copies remaining";
        }
        else{
            return "Checkout Error: Non in stock";
        }

    }
    
    void save()
    {
        json videos = json::array();

        // Read existing file if it exists
        ifstream input("database/videos.json");
        if (input.is_open())
        {
            input >> videos;
            input.close();
        }

        // Create a JSON object for this video
        json video = {
            {"title", title},
            {"genre", genre},
            {"year", year},
            {"copies_available", copies_available}};

        // Add to array
        videos.push_back(video);

        // Save back to file
        ofstream output("database/videos.json");
        output << videos.dump(4); // Pretty print with 4-space indentation
        output.close();
    }

    static vector<VideoStruct> getVideos()
    {
        vector<VideoStruct> videos;

        ifstream input("database/videos.json");

        if (!input.is_open())
        {
            cout << "Could not open videos.json" << endl;
            return videos;
        }

        json data;
        input >> data;

        for (const auto &item : data)
        {
            VideoStruct video;

            video.title = item.value("title", "");
            video.genre = item.value("genre", "");
            video.year = item.value("year", 0);
            video.copies_available = item.value("copies_available", 0);
            

            videos.push_back(video);
        }

        return videos;
    }
    // Added By Ethan
    static string rentVideo(string title)
    {
        json videos;

        // Read existing file if it exists
        ifstream input("database/videos.json");

        if (!input.is_open())
        {
            return "Error: could not open videos.json";
        }

        input >> videos;
        input.close();

        // Look through the list for the title the user picked
        for (int i = 0; i < static_cast<int>(videos.size()); i++)
        {
            if (videos[i]["title"] == title)
            {
                int copies = videos[i]["copies_available"];

                // The file only tracks copies on the shelf, so the first time
                // we touch a video we record how many the store owns
                if (!videos[i].contains("total_copies"))
                {
                    videos[i]["total_copies"] = copies;
                }

                if (copies == 0)
                {
                    return "Rent failed: no copies in stock";
                }
                else
                {
                    copies = copies - 1;
                    videos[i]["copies_available"] = copies;

                    // Save back to file
                    ofstream output("database/videos.json");
                    output << videos.dump(4);
                    output.close();

                    return "Success: " + to_string(copies) + " copies remaining";
                }
            }
        }

        return "Error: title not found";
    }
    // Added By Ethan
    // Puts one copy back on the shelf and returns a message for the page to show
    static string returnVideo(string title)
    {
        json videos;

        // Read existing file if it exists
        ifstream input("database/videos.json");

        if (!input.is_open())
        {
            return "Error: could not open videos.json";
        }

        input >> videos;
        input.close();

        // Look through the list for the title the user picked
        for (int i = 0; i < static_cast<int>(videos.size()); i++)
        {
            if (videos[i]["title"] == title)
            {
                int copies = videos[i]["copies_available"];

                if (!videos[i].contains("total_copies"))
                {
                    videos[i]["total_copies"] = copies;
                }

                int total = videos[i]["total_copies"];

                // If every copy is already here then nothing is rented out
                if (copies >= total)
                {
                    return "Return failed: all copies are already in stock";
                }
                else
                {
                    copies = copies + 1;
                    videos[i]["copies_available"] = copies;

                    // Save back to file
                    ofstream output("database/videos.json");
                    output << videos.dump(4);
                    output.close();

                    return "Success: " + to_string(copies) + " copies remaining";
                }
            }
        }

        return "Error: title not found";
    }
    ~Video()
    {
    }
};
