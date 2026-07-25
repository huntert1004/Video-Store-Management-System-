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
    ~Video()
    {
    }
};
