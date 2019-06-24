#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QMessageBox>

#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

#include <QVariant>

bool ok;
QHostAddress send_Ip;
quint16 send_Port;
bool OC;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_routeIP->setPlaceholderText("192.168.0.90");
    ui->lineEdit_routePort->setPlaceholderText("2000");
    ui->lineEdit_hostPort->setPlaceholderText("9090");
    ui->lineEdit_routeIP->setText("192.168.0.90");
    ui->lineEdit_routePort->setText("2000");
    ui->lineEdit_hostPort->setText("9090");
    ui->pushButton_Connet->setText("打开");
    OC = false;
    connect(ui->pushButton_Connet,SIGNAL(clicked(bool)),this,SLOT(button_connect()));
    connect(ui->pushButton_Send, SIGNAL(clicked(bool)),this,SLOT(button_send()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button_connect()
{
    QString Route_IP,Route_Port,Host_Port;

    Route_IP   = ui->lineEdit_routeIP->text();
    Route_Port = ui->lineEdit_routePort->text();
    Host_Port  = ui->lineEdit_hostPort->text();

    send_Ip   = QHostAddress(Route_IP);
    send_Port = Route_Port.toInt(&ok,10);

    if(ui->pushButton_Connet->text()==QString("关闭")){
       ui->pushButton_Connet->setText("打开");
       if(udpSocket != NULL)
       {
        //    udpSocket->close();

           disconnect(udpSocket, SIGNAL(readyRead()),this,SLOT(UDP_Recv()));
           udpSocket->disconnectFromHost(); //关闭souket
           //udpSocket->deleteLater();
       }

       return;

    }
    if(ui->pushButton_Connet->text()==QString("打开")){
        ui->pushButton_Connet->setText("关闭");
        udpSocket = new QUdpSocket();

        if(udpSocket->bind(QHostAddress(QHostAddress::AnyIPv4),Host_Port.toInt(&ok,10))==false)//绑定读数据端口(监听端口)，允许其他服务绑定到此端口
        {
          QMessageBox::information(this,  QStringLiteral("警告"),QStringLiteral("UDP建立链接失败！"));
          qDebug() << ("Server socket bind faileds!");
          //return;
         }else
        {
          qDebug() << ("Server socket bind secss!");
        }

        connect(udpSocket, SIGNAL(readyRead()),this,SLOT(UDP_Recv()));
        return;
    }


}
void MainWindow::button_send()
{
    QString str_text,str_tmp;
    QByteArray Send_buf;
    int *str_tmp1;
    str_text   = ui->lineEdit_send->text();
     qDebug() << str_text;
    for(int ii=0;ii<str_text.count();ii+=2)
    {
         str_tmp = str_text.mid(ii,2);
         Send_buf[ii/2]= str_tmp.toInt(&ok,16);

    }
    if(ui->pushButton_Connet->text()==QString("关闭"))
    {
    udpSocket->writeDatagram(Send_buf,Send_buf.size(),
                             send_Ip,send_Port);//向5000端口写数据
    qDebug() << QHostAddress(send_Ip);
    qDebug() << Send_buf;
    qDebug() << sizeof(str_tmp1)/sizeof(str_tmp1[0]);

    }
}

void MainWindow::UDP_Recv()
{
    QString recvStr;
    QByteArray datagram;
    char *tmp;

    while (udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());//让datagram的大小为等待处理的数据报的大小
        udpSocket->readDatagram(datagram.data(), datagram.size(),&send_Ip, &send_Port);
        qDebug() << datagram;
        recvStr = QString(datagram);
    }

    tmp = datagram.data();// QByteArray转换成char
    ui->textBrowser_Rec->setText(recvStr);
}
