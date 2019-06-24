#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUdpSocket>
//#define unsigned char  uchar
//#define unsigned int   uint
//#define num_to_str(tmp) QString::number(uchar(tmp))

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

//    QByteArray QString2Hex(QString str);
private:
    Ui::MainWindow *ui;
    QUdpSocket  *udpSocket;

private slots:
   void UDP_Recv();
   void json(QByteArray byteArray);

};


#endif // MAINWINDOW_H
