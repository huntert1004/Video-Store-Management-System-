#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class HomePage;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    HomePage *homePage;
};

#endif