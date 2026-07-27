#include "HomePage.h"
#include "../../model/Video.cpp"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QString>

HomePage::HomePage(QWidget *parent)
    : QWidget(parent)
{
    titleLabel = new QLabel("Video Rental System");
    welcomeLabel = new QLabel("Welcome!");

    addVideoButton = new QPushButton("Add Video");
    rentVideoButton = new QPushButton("Rent Video");
    returnVideoButton = new QPushButton("Return Video");

    // Create table
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);

    tableWidget->setHorizontalHeaderLabels({"Title",
                                            "Genre",
                                            "Year",
                                            "Copies"});

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    vector<VideoStruct> videos = Video::getVideos();
    // set size of table
    tableWidget->setRowCount(static_cast<int>(videos.size()));
    // dynamicly set data in table 
    for (int i = 0; i < static_cast<int>(videos.size()); i++)
    {
        tableWidget->setItem(
            i,
            0,
            new QTableWidgetItem(
                QString::fromStdString(videos[i].title)));

        tableWidget->setItem(
            i,
            1,
            new QTableWidgetItem(
                QString::fromStdString(videos[i].genre)));

        tableWidget->setItem(
            i,
            2,
            new QTableWidgetItem(
                QString::number(videos[i].year)));

        tableWidget->setItem(
            i,
            3,
            new QTableWidgetItem(
                QString::number(videos[i].copies_available)));

       
    }

    // Button row
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addVideoButton);
    buttonLayout->addWidget(rentVideoButton);
    buttonLayout->addWidget(returnVideoButton);
    buttonLayout->addStretch(); // Push buttons to the left

    // Main layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Adding Table above buttons
    layout->addWidget(tableWidget);

    layout->addWidget(titleLabel);
    layout->addWidget(welcomeLabel);
    layout->addLayout(buttonLayout);

    

    setLayout(layout);
}

//ADDED BY ALEXA
void HomePage::openSearchVideoPage()
{
    SearchVideoPage page(this);
    page.exec();

}
