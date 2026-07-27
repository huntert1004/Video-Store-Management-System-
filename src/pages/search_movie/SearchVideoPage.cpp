#include "SearchVideoPage.h"
#include "../../model/Video.cpp"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QString>

#include <vector>

SearchVideoPage::SearchVideoPage(QWidget* parent)
    : QDialog(parent)
{
    // Page heading
    QLabel* pageTitleLabel = new QLabel("Search Video");

    // Search input
    QLabel* searchLabel = new QLabel("Enter Video Title:");
    titleEdit = new QLineEdit();

    // Search button
    searchButton = new QPushButton("Search");

    // Output labels
    titleLabel = new QLabel("Title: ");
    genreLabel = new QLabel("Genre: ");
    yearLabel = new QLabel("Year: ");
    copiesLabel = new QLabel("Copies Available: ");
    availableLabel = new QLabel("Availability: ");
    statusLabel = new QLabel("");

    // Connect the button to the search function
    connect(
        searchButton,
        &QPushButton::clicked,
        this,
        &SearchVideoPage::searchVideo
    );
    this->setStyleSheet(
        "QLabel {"
        "    color: #FEA902;"
        "}"
        "QPushButton {"
        "    background-color: #0C3EA8;"
        "    color: #FEA902;"
        "}"
        "QPushButton:hover {"
        "    color: #39528B;"
        "}");
    // Layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(pageTitleLabel);
    mainLayout->addWidget(searchLabel);
    mainLayout->addWidget(titleEdit);
    mainLayout->addWidget(searchButton);

    mainLayout->addWidget(statusLabel);
    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(genreLabel);
    mainLayout->addWidget(yearLabel);
    mainLayout->addWidget(copiesLabel);
    mainLayout->addWidget(availableLabel);

    setLayout(mainLayout);
    setWindowTitle("Search Video");
}

void SearchVideoPage::searchVideo()
{
    QString searchTitle = titleEdit->text().trimmed();

    // Prevent an empty search
    if (searchTitle.isEmpty())
    {
        statusLabel->setText("Please enter a video title.");
        return;
    }

    std::vector<VideoStruct> videos = Video::getVideos();

    bool found = false;

    for (const auto& video : videos)
    {
        QString storedTitle = QString::fromStdString(video.title);

        if (storedTitle.compare(searchTitle, Qt::CaseInsensitive) == 0)
        {
            found = true;

            titleLabel->setText(
                "Title: " + QString::fromStdString(video.title)
            );

            genreLabel->setText(
                "Genre: " + QString::fromStdString(video.genre)
            );

            yearLabel->setText(
                "Year: " + QString::number(video.year)
            );

            copiesLabel->setText(
                "Copies Available: "
                + QString::number(video.copies_available)
            );

            if (video.copies_available > 0)
            {
                availableLabel->setText("Availability: Available");
            }
            else
            {
                availableLabel->setText("Availability: Out of Stock");
            }

            statusLabel->setText("Movie Found");

            break;
        }
    }

    if (!found)
    {
        statusLabel->setText("Movie Not Found");

        titleLabel->setText("Title: ");
        genreLabel->setText("Genre: ");
        yearLabel->setText("Year: ");
        copiesLabel->setText("Copies Available: ");
        availableLabel->setText("Availability: ");
    }
}