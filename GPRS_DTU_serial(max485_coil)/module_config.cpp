#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QDebug>

//uint8_t KEY[16]= {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10};
//uint8_t IV[16] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0a,0x0b,0x0c,0x0d,0x0e,0x0f,0x10};
//uint8_t ID[8] = {0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08};
QString KEY= "01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10";
QString IV = "01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f 10";
QString ID = "01 02 03 04 05 06 07 08";



void MainWindow:: module_config()
{

    QObject::connect(ui->pushButton_in_config, SIGNAL(clicked(bool)),this,SLOT(in_config()));  //进入配置模式
    QObject::connect(ui->pushButton_in_check, SIGNAL(clicked(bool)),this,SLOT(in_check()));    //进入查询模式
    QObject::connect(ui->pushButton_out_config, SIGNAL(clicked(bool)),this,SLOT(out_comfig())); //退出

    QObject::connect(ui->pushButton_version, SIGNAL(clicked(bool)),this,SLOT(check_version())); //查询
    QObject::connect(ui->pushButton_signal, SIGNAL(clicked(bool)),this,SLOT(check_signal())); //查询
    QObject::connect(ui->pushButton_operator, SIGNAL(clicked(bool)),this,SLOT(cherk_operator())); //查询
    QObject::connect(ui->pushButton_pin, SIGNAL(clicked(bool)),this,SLOT(check_PIN())); //查询
    QObject::connect(ui->pushButton_creg, SIGNAL(clicked(bool)),this,SLOT(check_CREG())); //查询
    QObject::connect(ui->pushButton_greg, SIGNAL(clicked(bool)),this,SLOT(check_GREG())); //查询

    QObject::connect(ui->pushButton_config_serial, SIGNAL(clicked(bool)),this,SLOT(config_serial())); //串口配置
//    QObject::connect(ui->pushButton_pass_config, SIGNAL(clicked(bool)),this,SLOT(key_port_config()));  //模式及加密信息配置
    QObject::connect(ui->pushButton_send, SIGNAL(clicked(bool)),this,SLOT(serial_send()));         //发送模式配置

    //加入波特率条目
    ui->comboBox_baudw->addItem(QStringLiteral("9600"));
    ui->comboBox_baudw->addItem(QStringLiteral("115200"));
//    //加入数据位条目
//    ui->comboBox_bytew->addItem(QStringLiteral("7"));
//    ui->comboBox_bytew->addItem(QStringLiteral("8"));
//    //加入校验条目
//    ui->comboBox_checkw->addItem(QStringLiteral("None"));
//    ui->comboBox_checkw->addItem(QStringLiteral("Even"));
//    ui->comboBox_checkw->addItem(QStringLiteral("Odd"));
//    //加入停止位
//    ui->comboBox_stopw->addItem(QStringLiteral("1"));
//    ui->comboBox_stopw->addItem(QStringLiteral("2"));
////    ui->comboBox_stopw->addItem(QStringLiteral("1.5"));
    //网络连接类型
    ui->comboBox_connet->addItem(QStringLiteral("UDP"));
    ui->comboBox_connet->addItem(QStringLiteral("TCP"));


    radioGroup2->addButton(ui->radioButton_hex,1);
    radioGroup2->addButton(ui->radioButton_ascii,2);

}


//网络服务器地址配置 串口配置

void MainWindow::config_serial()
{
    QString udp_tcp, IPaddress,port;
    QByteArray server;

   QString com_baud; //,com_byte,com_check,com_stop;
//   QByteArray serial;
   if(serial_res)
   {
       ui->textBrowser->append(QStringLiteral("请打开串口"));
       return;
   }
   com_baud = ui->comboBox_baudw->currentText();
//   com_byte = ui->comboBox_bytew->currentText();
//   com_check= ui->comboBox_checkw->currentText();
//   com_stop = ui->comboBox_stopw->currentText();
   IPaddress=ui->lineEdit_ip->text();
   port    = ui->lineEdit_port->text();

   udp_tcp.clear();
   udp_tcp.append(com_baud.toLatin1().data());//发送波特率
   udp_tcp.append(";");
   udp_tcp.append("\"");
   udp_tcp.append(ui->comboBox_connet->currentText()); //服务类型
   udp_tcp.append("\"");

   udp_tcp.append(",\"");
   udp_tcp.append(IPaddress);   //IP地址或域名
   udp_tcp.append("\",");
   udp_tcp.append(port);  //端口
   server = udp_tcp.toLatin1();

   serial.write("G*");                 //发送存储命令
   serial.write(server);               //网络服务器配置
   ui->textBrowser->append(server);
   qDebug()<< sizeof(com_baud.toLatin1().data())/sizeof(char) ;
   qDebug()<< strlen(com_baud.toLatin1());
   qDebug()<< server;
//   serial.write(com_byte.toLatin1());  //发送字节长度
//   serial.write(com_check.toLatin1()); //发送校验位
//   serial.write(com_stop.toLatin1());  //发送停止位

}
#if 0
/*
 * 加密  传输模式设置
*/
void MainWindow::key_port_config()
{
    QString  all_string ;
    QByteArray  all_Array,mode ;
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    all_Array.clear();
    all_string.append(KEY);
    all_string.append(IV);
    all_string.append(ID);
    all_Array = QByteArray::fromHex(all_string.toLatin1().data());
    if(radioGroup1->checkedId()==1)
        mode="1";
    if(radioGroup1->checkedId()== 2)
        mode="2";
    serial.write("S+");
    serial.write(QByteArray::fromHex(mode.data()));
    serial.write(all_Array);
    ui->textBrowser->append(mode);
    ui->textBrowser->append(all_string);
    qDebug()<< QByteArray::fromHex(mode.data());
    qDebug()<<all_Array;
}
#endif
/*
 *查询版本
*/
void MainWindow:: check_version()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+CGMR\r");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询版本号："));
}

/*
 *查询信号
*/
void MainWindow::check_signal()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+CSQ\r");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询信号强度："));
}

/*
 *查询运行商
*/
void MainWindow::cherk_operator()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+COPS?\r");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询运行商："));
}

/*
 *查询pin
*/
void MainWindow::check_PIN()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+CPIN?\r");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询pin："));
}

/*
 *查询注册状态
*/
void MainWindow::check_CREG()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+CREG?");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询注册状态："));
}

/*
 *查询GPRS状态
*/
void MainWindow::check_GREG()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("AT+CGREG?\r");
    ui->textBrowser->insertPlainText(QStringLiteral("\r查询GPRS状态："));
}
//进入配置模式
void MainWindow::in_config()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("MU");

    ui->textBrowser->append("MU");
    qDebug() << "in_config 0k";
}

void MainWindow::in_check()
{
    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }
    serial.write("C#");
    ui->textBrowser->append("C#");
     qDebug() << "in_check 0k";

}

//退出配置模式
void MainWindow::out_comfig()
{
    serial.write("Q!");
    ui->textBrowser->append("Q!");
    qDebug() << "out_comfig 0k";
}

//发送操作
void MainWindow::serial_send()
{
    QString qstr;
    QByteArray qbyte;

    if(serial_res)
    {
        ui->textBrowser->append(QStringLiteral("请打开串口"));
        return;
    }

    qstr = ui->lineEdit_send->text();
    if(radioGroup2->checkedId() == 1){
        qbyte = QByteArray::fromHex(qstr.toLatin1().data());
        ui->textBrowser->append(qstr);
    }
    if(radioGroup2->checkedId() == 2){
        qbyte = qstr.toLatin1();
       // qbyte = QByteArray::fromStdString(qstr.toLatin1());
        ui->textBrowser->append(qstr);
    }
//    ui->textBrowser->append(qstr.data());
    serial.write(qbyte);
    serial.write("\r\n");
//    qDebug() << "发送：";
//    qDebug() << radioGroup1->checkedId();
    qDebug() << qbyte;
}


