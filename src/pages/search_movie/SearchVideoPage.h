#ifndef SEARCHVIDEOPAGE_H
#define SEARCHVIDEOPAGE_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;

//defining search video class that inherits from QDialog
class SearchVideoPage : public QDialog
{
    Q_OBJECT

public:
    explicit SearchVideoPage(QWidget *parent = nullptr);

private slots:
    void searchVideo(); //this runs when the search button is clicked

private:
    //input
    QLineEdit* titleEdit; //where user enters the movie title to search

    //output labels
    QLabel* titleLabel;//movie title label
    QLabel* genreLabel;//movie genre label
    QLabel* yearLabel; //movie year label
    QLabel* copiesLabel;//movie copies label
    QLabel* availableLabel;//available label
    QLabel* statusLabel; //out of stock label

    //buttons
    QPushButton* searchButton; 

};

#endif