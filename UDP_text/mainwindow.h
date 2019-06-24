#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QUdpSocket>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     QUdpSocket  *udpSocket;

private:
    Ui::MainWindow *ui;

private slots:
   void button_send();
   void button_connect();
   void UDP_Recv();
};

#endif // MAINWINDOW_H
