#include "SearchVideoPage.h"
#include "../../model/Video.cpp"
//added by Alexa

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

void SearchVideoPage::searchVideo()
{
    // get the title the user typed into the search box
    std::string searchTitle = titleEdit->text().toStdString();

    // gets all videos stored in videos.json
    // this calls the static function in Video.cpp
    std::vector<VideoStruct> videos = Video::getVideos();

    // variable to keep track of if the movie was found
    bool found = false;

    // for loop that goes through every video in the vector
    for (const auto& video : videos)
    {
        // compares the movie title from the json file with the title the user entered
        // case insensitive so the user can use any capitalization they want
        if (QString::fromStdString(video.title)
            .compare(titleEdit->text(), Qt::CaseInsensitive) == 0)
        {
            found = true;

            // display title
            titleLabel->setText(QString::fromStdString(video.title));

            // display genre
            genreLabel->setText(QString::fromStdString(video.genre));

            // display year
            yearLabel->setText(QString::number(video.year));

            // display how many copies are available
            copiesLabel->setText(QString::number(video.copies_available));

            // if at least one copy exists, shows "Available"
            if (video.copies_available > 0)
            {
                availableLabel->setText("Available");
            }
            else
            {
                // if not shows it is out of stock
                availableLabel->setText("Out of Stock");
            }

            // update the status label
            statusLabel->setText("Movie Found");

            // stops searching if movie was found
            break;
        }
    }

    //  if movie is not found
    if (!found)
    {
        // sets the label to show movie not found
        statusLabel->setText("Movie Not Found");
    }
}