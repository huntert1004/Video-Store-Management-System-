#include "AddVideoPage.h"
#include "../../model/Video.cpp"
//^^ADDED BY ANGEL

#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

AddVideoPage::AddVideoPage(QWidget* parent)
    : QDialog(parent)
{
    // Window title
    titleLabel = new QLabel("Add Video");

    // Labels
    videoTitleLabel = new QLabel("Title:");
    genreLabel = new QLabel("Genre:");
    yearLabel = new QLabel("Year:");
    copiesLabel = new QLabel("Copies Available:");

    // Input fields
    titleEdit = new QLineEdit();
    genreEdit = new QLineEdit();

    yearBox = new QSpinBox();
    yearBox->setRange(1900, 2100);

    copiesBox = new QSpinBox();
    copiesBox->setRange(0, 100);

    // Buttons
    saveButton = new QPushButton("Save");
    //ADDED BY ANGEL for the add video
    connect(saveButton,
        &QPushButton::clicked,
        this,
        &AddVideoPage::saveVideo);
    cancelButton = new QPushButton("Cancel");
    //ADDED BY ANGEL for add video
    connect(cancelButton,
        &QPushButton::clicked,
        this,
        &QDialog::reject);

    // Layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    mainLayout->addWidget(titleLabel);

    mainLayout->addWidget(videoTitleLabel);
    mainLayout->addWidget(titleEdit);

    mainLayout->addWidget(genreLabel);
    mainLayout->addWidget(genreEdit);

    mainLayout->addWidget(yearLabel);
    mainLayout->addWidget(yearBox);

    mainLayout->addWidget(copiesLabel);
    mainLayout->addWidget(copiesBox);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveButton);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);

    setLayout(mainLayout);

    setWindowTitle("Add Video");
}

void AddVideoPage::saveVideo()
{
    Video video(
        titleEdit->text().toStdString(),
        genreEdit->text().toStdString(),
        yearBox->value(),
        copiesBox->value()
    );

    video.save();

    accept();
}