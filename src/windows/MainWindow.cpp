#include "MainWindow.h"
#include "../pages/home_page/HomePage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    homePage = new HomePage(this);
    this->setStyleSheet(
        "QDialog {"
        "    background-color: #39528B;"
        "}"
        "QMainWindow {"
        "    background-color: #000000ff;"
        "}");

    setCentralWidget(homePage);

    setWindowTitle("Video Store Database");
    resize(1000, 700);
}