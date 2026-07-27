#include "ReturnVideoPage.h"
#include "../../model/Video.cpp"
//^^ADDED BY ETHAN

#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

// Builds the window. Everything here runs once, when the window opens.
ReturnVideoPage::ReturnVideoPage(QWidget* parent)
    : QDialog(parent)
{
    // Window title
    titleLabel = new QLabel("Return Video");

    // Labels
    videoTitleLabel = new QLabel("Title:");

    // Starts empty, we fill it in after the user clicks Return
    statusLabel = new QLabel("");

    // Input fields
    titleBox = new QComboBox();

    // Ask the model for every video in the database.
    // A vector is used because we do not know how many there will be.
    vector<VideoStruct> videos = Video::getVideos();

    // Put each title into the drop down.
    // Using a drop down instead of a text box means the user cannot
    // misspell a title and get a "not found" error.
    for (int i = 0; i < static_cast<int>(videos.size()); i++)
    {
        titleBox->addItem(QString::fromStdString(videos[i].title));
    }

    // Buttons
    returnButton = new QPushButton("Return");
    // connect tells Qt to run returnVideo() whenever this button is clicked
    //ADDED BY ETHAN for the return video
    connect(returnButton,
        &QPushButton::clicked,
        this,
        &ReturnVideoPage::returnVideo);
    closeButton = new QPushButton("Close");
    // reject() is built into QDialog and just closes the window
    //ADDED BY ETHAN for return video
    connect(closeButton,
        &QPushButton::clicked,
        this,
        &QDialog::reject);

    // Layout
    // QVBoxLayout stacks things top to bottom
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(titleLabel);

    mainLayout->addWidget(videoTitleLabel);
    mainLayout->addWidget(titleBox);

    mainLayout->addWidget(statusLabel);

    // QHBoxLayout puts things side by side, so the buttons sit in a row
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(returnButton);
    buttonLayout->addWidget(closeButton);

    // Add that row of buttons underneath everything else
    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    setWindowTitle("Return Video");
}

// This runs every time the user clicks the Return button
void ReturnVideoPage::returnVideo()
{
    // If the drop down is empty then the database had no videos in it
    if (titleBox->count() == 0)
    {
        statusLabel->setText("No videos in the database");
        return;
    }

    // currentText() is whichever title is showing in the drop down.
    // toStdString() converts it from a Qt string to a normal C++ string.
    string title = titleBox->currentText().toStdString();

    // The model does the real work and hands back a message
    string result = Video::returnVideo(title);

    // Show that message in the window so the user can see what happened
    statusLabel->setText(QString::fromStdString(result));
}
