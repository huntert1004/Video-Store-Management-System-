#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>
#include "../add_video/AddVideoPage.h"
#include "../rent_video/RentVideoPage.h"
#include "../return_video/ReturnVideoPage.h"

class QPushButton;
class QLabel;
class QVBoxLayout;
class QTableWidget;

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

private slots:
    void openAddVideoPage();
    void openRentVideoPage();
    void openReturnVideoPage();

private:
    QLabel *titleLabel;
    QLabel *welcomeLabel;
    
    void loadVideos();
    void refreshTable();

    QPushButton *addVideoButton;
    QPushButton *rentVideoButton;
    QPushButton *returnVideoButton;
    QTableWidget *tableWidget;
    
};

#endif