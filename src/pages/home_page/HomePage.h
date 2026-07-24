#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QWidget>

class QPushButton;
class QLabel;
class QVBoxLayout;
class QTableWidget;

class HomePage : public QWidget
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);

private:
    QLabel *titleLabel;
    QLabel *welcomeLabel;

    QPushButton *addVideoButton;
    QPushButton *rentVideoButton;
    QPushButton *returnVideoButton;
    QTableWidget *tableWidget;
};

#endif