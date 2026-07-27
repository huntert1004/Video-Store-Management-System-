#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

//ADDED BY ETHAN
// Handles renting and returning. Every change to copies_available happens here.
class Rental
{
public:
    // Takes one copy off the shelf and returns a message for the page to show
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
};
