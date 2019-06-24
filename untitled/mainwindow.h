#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QUdpSocket>
//#define unsigned char  uchar
//#define unsigned int   uint
#define num_to_str(tmp) QString::number(uchar(tmp))

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
    void get_IP();
    void list_scan(QByteArray scan);
    void combox_dis();

private slots:
   void button_read();
   void button_write();
   void raly1_send();
   void raly2_send();
   void UDP_Recv();
   void Scan();


};


#endif // MAINWINDOW_H
