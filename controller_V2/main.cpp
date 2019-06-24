#include "mainwindow.h"
#include "mythread.h"
#include <QApplication>
#include <QThread>

/*****打包命令：windeployqt********/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
