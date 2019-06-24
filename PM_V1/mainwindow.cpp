#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

#include<QJsonObject>
#include<QJsonDocument>

#include <QVariant>

QButtonGroup *btnGroupFruits;

QHostAddress send_Ip; //发送端ip
quint16 send_Port; //发送端端口

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


   /***UDP_server****/
    qDebug() << QHostAddress(QHostAddress::AnyIPv4).toString();
    udpSocket = new QUdpSocket();
    QHostAddress multiAddr("224.0.0.71");//这里要选一个组播地址
    if(udpSocket->bind(QHostAddress(QHostAddress::AnyIPv4),7788,QAbstractSocket::ShareAddress)==false)//绑定读数据端口(监听端口)，允许其他服务绑定到此端口
    {

      qDebug() << ("Server socket bind faileds!");
//      return;
    }
 //   udpSocket->setSocketOption(QAbstractSocket::MulticastLoopbackOption,0); //设置缓冲区


    //加入组播组
    if(udpSocket->joinMulticastGroup(multiAddr)==true)
        {
        qDebug()<<QStringLiteral("加入组播成功！");
        }
    connect(udpSocket, SIGNAL(readyRead()),this,SLOT(UDP_Recv()));

    qDebug() << "UDP Server Running...";

    /*界面信号与槽*/


    /****edit初始化参数*****/
    ui->lineEdit_PM2l_5->setPlaceholderText("PM2.5");
    ui->lineEdit_PM10->setPlaceholderText("PM10");

    qDebug()<<(QStringLiteral(" 界面启动完成！"));
}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::UDP_Recv()
{
    QString recvStr;
    QByteArray datagram;
//    char *tmp;

    while (udpSocket->hasPendingDatagrams())
    {
        datagram.resize(udpSocket->pendingDatagramSize());//让datagram的大小为等待处理的数据报的大小
        udpSocket->readDatagram(datagram.data(), datagram.size(),&send_Ip, &send_Port);
        qDebug() << datagram;
        recvStr = QString(datagram);
    }
//    datagram.
//    tmp = datagram.data();// QByteArray转换成char

//    qDebug() << (QStringLiteral("<----------接收地址信息:")) << datagram << "-------->";
//    qDebug() << QString::number(datagram[0]);
//    ui->lineEdit_test->setText(QString::number(uchar(tmp[0])));

    MainWindow::json(datagram);

    QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("获取完成！"));

}

void MainWindow::json(QByteArray byteArray)
{
    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteArray, &jsonError);    // 转化为 JSON 文档
    if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (doucment.isObject()) {                                              // JSON 文档为对象
            QJsonObject object = doucment.object();                             // 转化为对象
            if (object.contains("Name")) {                                      // 包含指定的 key
                QJsonValue value = object.value("Name");                        // 获取指定 key 对应的 value
                if (value.isString()) {                                         // 判断 value 是否为字符串
                    QString strName = value.toString();                         // 将 value 转化为字符串
                    qDebug() << "Name : " << strName;
                }
            }
            if (object.contains("From")) {
                QJsonValue value = object.value("From");
                if (value.isDouble()) {
                    int nFrom = value.toVariant().toInt();
                    qDebug() << "From : " << nFrom;
                }
            }
            if (object.contains("Cross Platform")) {
                QJsonValue value = object.value("Cross Platform");
                if (value.isBool()) {
                    bool bCrossPlatform = value.toBool();
                    qDebug() << "CrossPlatform : " << bCrossPlatform;
                }
            }
        }
    }

}
