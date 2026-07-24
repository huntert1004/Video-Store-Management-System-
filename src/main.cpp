#include <QApplication>
#include "windows/MainWindow.h"
// Delete This data for real application just an example data to fill the table we need to actually do this in a seperate window for add video
#include "model/Video.cpp"
//------------------------------
int main(int argc, char *argv[])
{
    // Delete this too this is actuall where im putting the data in
    Video s1("Fight Club","Psychological Thriller",1999,12);
    s1.save();
    Video s2("Jurrassic Park","Action",1999,25);
    s2.save();
    //---------------------------------------------------
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}