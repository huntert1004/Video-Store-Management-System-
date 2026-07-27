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
    titleLabel = new QLabel("Blockbuster Rental System");
    titleLabel->setAlignment(Qt::AlignCenter);
    welcomeLabel = new QLabel("Welcome Our Valued Employee!");
    welcomeLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setObjectName("title");
    addVideoButton = new QPushButton("Add Video");
    rentVideoButton = new QPushButton("Rent Video");
    returnVideoButton = new QPushButton("Return Video");
    searchVideoButton = new QPushButton("Search Titles");
    connect(addVideoButton,
        &QPushButton::clicked,
        this,
        &HomePage::openAddVideoPage);

    //ADDED BY ETHAN for the rent video
    connect(rentVideoButton,
        &QPushButton::clicked,
        this,
        &HomePage::openRentVideoPage);

    //ADDED BY ETHAN for the return video
    connect(returnVideoButton,
        &QPushButton::clicked,
        this,
        &HomePage::openReturnVideoPage);

    connect(searchVideoButton,
        &QPushButton::clicked,
        this,
        &HomePage::openSearchVideoPage);
    // Create table
    tableWidget = new QTableWidget(this);
    tableWidget->setColumnCount(4);

    tableWidget->setHorizontalHeaderLabels({"Title",
                                            "Genre",
                                            "Year",
                                            "Copies"});

    tableWidget
        ->horizontalHeader()
        ->setSectionResizeMode(QHeaderView::Stretch);

    tableWidget->setEditTriggers(
        QAbstractItemView::NoEditTriggers
    );

    tableWidget->setSelectionBehavior(
        QAbstractItemView::SelectRows
    );

    refreshTable();
    this->setStyleSheet(
        "QLabel {"
        "    color: #FEA902;"
        "    font-size: 14px;"
        "}"
        "QPushButton {"
        "    background-color: #0C3EA8;"
        "    color: #FEA902;"
        "}"
        "QPushButton:hover {"
        "    background-color: #39528B;"
        "}"
        "QTableWidget{"
        "    background: #0C3EA8;"
        "    selection-background-color: #39528B;"
        "    color: #FEA902;"
        "}"
        "QLabel#title {"
        "    font-size: 20px;"
        "    padding: 5px;"
        "}"
    
    );
    // Button row
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(addVideoButton);
    buttonLayout->addWidget(rentVideoButton);
    buttonLayout->addWidget(returnVideoButton);
    buttonLayout->addWidget(searchVideoButton);
    buttonLayout->addSpacing(10); // Push buttons to the left
    

    // Main layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Adding Table above buttons
    layout->addWidget(titleLabel);
    layout->addWidget(welcomeLabel);
    layout->addWidget(tableWidget);
    layout->addLayout(buttonLayout);

    

    

    setLayout(layout);
}

//ADDED BY ALEXA
void HomePage::openSearchVideoPage()
{
    SearchVideoPage page(this);
    page.exec();
}
void HomePage::refreshTable()
{
    std::vector<VideoStruct> videos = Video::getVideos();

    tableWidget->clearContents();

    tableWidget->setRowCount(
        static_cast<int>(videos.size())
    );

    for (int i = 0; i < static_cast<int>(videos.size()); i++)
    {
        tableWidget->setItem(
            i,
            0,
            new QTableWidgetItem(
                QString::fromStdString(videos[i].title)
            )
        );

        tableWidget->setItem(
            i,
            1,
            new QTableWidgetItem(
                QString::fromStdString(videos[i].genre)
            )
        );

        tableWidget->setItem(
            i,
            2,
            new QTableWidgetItem(
                QString::number(videos[i].year)
            )
        );

        tableWidget->setItem(
            i,
            3,
            new QTableWidgetItem(
                QString::number(videos[i].copies_available)
            )
        );
    }
}

//ADDED BY ANGEL
void HomePage::openAddVideoPage()
{
    AddVideoPage page(this);
    page.exec();
    //page executes user program waits for window to close then runs refresh

    refreshTable();
}

//ADDED BY ETHAN
void HomePage::openRentVideoPage()
{
    RentVideoPage page(this);
    page.exec();
    //page executes user program waits for window to close then runs refresh

    refreshTable();
}

//ADDED BY ETHAN
void HomePage::openReturnVideoPage()
{
    ReturnVideoPage page(this);
    page.exec();
    //page executes user program waits for window to close then runs refresh

    refreshTable();
}
