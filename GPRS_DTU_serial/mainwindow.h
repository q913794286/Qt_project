#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QSerialPort serial;
    QTimer *timer = new QTimer;
    QByteArray serial_cache;
    QByteArray serial_buf;
    bool       serial_RI;
    uint8_t       serial_res;
    QButtonGroup* radioGroup2 = new QButtonGroup();
    QButtonGroup* radioGroup1 = new QButtonGroup();
    //串口连接
    void initSeialPort();
    void serialportconfig(QString com, QString com_baud, QString com_byte, QString com_check, QString com_stop);

    void pushButton_open_serial();
    void on_comboBox_currentIndexChanged(QString com, QString com_baud, QString com_byte, QString com_check, QString com_stop);



    void module_config();

private slots:

    //
    void button_open_close();
//    void button_config();

    //串口配置
    void config_serial();
    void serialRead();
    void timeUpdate();   //串口超时
    //配置网络服务器
//    void config_ip_prot();
    //
    void key_port_config();
//    void pass_check();

    void check_version();
    void check_signal();
    void cherk_operator();
    void check_PIN();
    void check_CREG();
    void check_GREG();

    void in_config();
    void in_check();
    void out_comfig();
    void serial_send();

    void button_claen();
};

#endif // MAINWINDOW_H
