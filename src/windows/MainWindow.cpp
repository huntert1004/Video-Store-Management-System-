#include "MainWindow.h"
#include "../pages/home_page/HomePage.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    homePage = new HomePage(this);

    setCentralWidget(homePage);

    setWindowTitle("Video Store Database");
    resize(1000, 700);
}