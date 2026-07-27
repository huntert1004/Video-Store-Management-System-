#ifndef RENTVIDEOPAGE_H
#define RENTVIDEOPAGE_H

#include <QDialog>

// Telling the compiler these classes exist so we do not
// have to include all of their headers in this file
class QLabel;
class QComboBox;
class QPushButton;
class QVBoxLayout;
class QHBoxLayout;

// The window that opens when the Rent Video button is clicked.
// QDialog means it opens on top of the home page.
class RentVideoPage : public QDialog
{
    Q_OBJECT

public:
    // parent is the window that opened this one
    explicit RentVideoPage(QWidget* parent = nullptr);

private slots:
    // Runs when the user clicks Rent
    void rentVideo();

private:
    // Labels
    QLabel* titleLabel;      // says "Rent Video" at the top
    QLabel* videoTitleLabel; // says "Title:" above the drop down
    QLabel* statusLabel;     // shows the message we get back

    // Input fields
    QComboBox* titleBox;     // drop down list of every video title

    // Buttons
    QPushButton* rentButton;
    QPushButton* closeButton;
};

#endif
