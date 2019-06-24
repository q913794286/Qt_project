#include "mainwindow.h"
#include <QApplication>



/*****打包命令：windeployqt********/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
