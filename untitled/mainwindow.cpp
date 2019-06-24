#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

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
    if(udpSocket->bind(QHostAddress(QHostAddress::AnyIPv4),9090)==false)//绑定读数据端口(监听端口)，允许其他服务绑定到此端口
    {
      QMessageBox::information(this,  QStringLiteral("警告"),QStringLiteral("UDP建立链接失败！"));
      qDebug() << ("Server socket bind faileds!");
      return;
     }
    connect(udpSocket, SIGNAL(readyRead()),this,SLOT(UDP_Recv()));
    qDebug() << "UDP Server Running...";
    /*界面信号与槽*/
    QObject::connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(button_write()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(button_read()));
    QObject::connect(ui->pushButton_raly1,SIGNAL(clicked()),this,SLOT(raly1_send()));
    QObject::connect(ui->pushButton_raly2,SIGNAL(clicked()),this,SLOT(raly2_send()));
    QObject::connect(ui->pushButton_scan,SIGNAL(clicked()),this,SLOT(Scan()));
    /****edit初始化参数*****/
    ui->lineEdit_host_ip->setPlaceholderText("192.168.0.90");
    ui->lineEdit_mask->setPlaceholderText("255.255.255.0");
    ui->lineEdit_gateway->setPlaceholderText("192.168.0.1");
    ui->lineEdit_route_ip->setPlaceholderText("192.168.0.60");
    ui->lineEdit_mac->setText("0F:FF:FF:FF:FF:0F");
    ui->lineEdit_mac->setFocusPolicy(Qt::NoFocus); //设置mac地址框不可聚焦
    ui->lineEdit_mac->setEnabled(false);
    /*允许输入格式*/
    QRegExp ipRegExp = QRegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){4}");
//    QRegExp ipRegExp = QRegExp("((2[0-4]\\d|25[0-5]|[01]?\\d\\d?)\\.){3}(2[0-4]\\d|25[0-4]|[01]?\\d\\d?)");
    QRegExpValidator *ipRegExpValidator = new QRegExpValidator(ipRegExp, this);
    ui->lineEdit_host_ip->setValidator(ipRegExpValidator);
    ui->lineEdit_mask->setValidator(ipRegExpValidator);
    ui->lineEdit_gateway->setValidator(ipRegExpValidator);
    ui->lineEdit_route_ip->setValidator(ipRegExpValidator);

    QRegExp macRegExp = QRegExp("([0-9A-F]{2}[:-]){5}([0-9A-F]{2})");
    QRegExpValidator *macRegExpValidator = new QRegExpValidator(macRegExp, this);
    ui->lineEdit_mac->setValidator(macRegExpValidator);

//    ui->lineEdit_host_ip->setInputMask("000.000.000.000");
//    ui->lineEdit_mask->setInputMask("000.000.000.000");
//    ui->lineEdit_gateway->setInputMask("000.000.000.000");
//    ui->lineEdit_route_ip->setInputMask("000.000.000.000");
//    ui->lineEdit_mac->setInputMask("AA:AA:AA:AA:AA:AA");

    ui->lineEdit_test->setPlaceholderText(QStringLiteral("请刷卡获取IP+port！"));
    ui->lineEdit_test->setText("192.168.0.90:2000");
    qDebug()<<(QStringLiteral(" 界面启动完成！"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::button_quit()
//{
// qApp->exit(0);//退出app
//}

void MainWindow::button_write()
{
    if(ui->lineEdit_test->text().isEmpty()) //若没有获得目标ip
    {
        QMessageBox::information(this,  QStringLiteral("设置完成"),QStringLiteral("请手动填写或填刷卡获取目标IP以及端口！"));
    }
    else
    {
  /*****设置参数***************/
     QString WString[4];
     WString[0]= ui->lineEdit_host_ip->text();
     WString[1]= ui->lineEdit_mask->text();
     WString[2]= ui->lineEdit_gateway->text();
     WString[3]= ui->lineEdit_route_ip->text();

    QByteArray cmd,h_ip,mk,gy,r_ip;
    bool ok;

    cmd[0] = 0xb0;
    cmd[1] = 0;
    /*ip*/
    h_ip[0] = WString[0].section(".",0,0).toInt(&ok,10);
    h_ip[1] = WString[0].section(".",1,1).toInt(&ok,10);
    h_ip[2] = WString[0].section(".",2,2).toInt(&ok,10);
    h_ip[3] = WString[0].section(".",3,3).toInt(&ok,10);

    mk[0] = WString[1].section(".",0,0).toInt(&ok,10);
    mk[1] = WString[1].section(".",1,1).toInt(&ok,10);
    mk[2] = WString[1].section(".",2,2).toInt(&ok,10);
    mk[3] = WString[1].section(".",3,3).toInt(&ok,10);

    gy[0] = WString[2].section(".",0,0).toInt(&ok,10);
    gy[1] = WString[2].section(".",1,1).toInt(&ok,10);
    gy[2] = WString[2].section(".",2,2).toInt(&ok,10);
    gy[3] = WString[2].section(".",3,3).toInt(&ok,10);

    r_ip[0] = WString[3].section(".",0,0).toInt(&ok,10);
    r_ip[1] = WString[3].section(".",1,1).toInt(&ok,10);
    r_ip[2] = WString[3].section(".",2,2).toInt(&ok,10);
    r_ip[3] = WString[3].section(".",3,3).toInt(&ok,10);
    get_IP();
    udpSocket->writeDatagram(cmd[0]+h_ip+mk+gy+r_ip,17,send_Ip,send_Port);//向5000端口写数据
    qDebug()<<(QStringLiteral(" 写数据！"));

    QMessageBox::information(this,  QStringLiteral("设置完成"),
         QStringLiteral("本机地址：")+WString[0]+"\r\n"+
         QStringLiteral("子网掩码：")+WString[1]+"\r\n"+
         QStringLiteral("网   关：")+WString[2]+"\r\n"+
         QStringLiteral("服务器IP：")+WString[3]+"\r\n" );
    }
 }

void MainWindow::button_read()
{
    if(ui->lineEdit_test->text().isEmpty()) //若没有获得目标ip
    {
      QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("请填刷卡获取目标IP以及端口！"));
    }
    else
    {
    QByteArray cmd;
    cmd[0] = 0xb1;
    cmd[1] = 0;
    get_IP();
//    QHostAddress serverip;
//    serverip.setAddress(QString("192.168.0.7"));//这是人为指定ip地址的方法
//    Server_udpSocket->writeDatagram(QVariant(ui->textEdit_write->toPlainText()).toByteArray(),QHostAddress::LocalHost,5000);//向5000端口写数据
    udpSocket->writeDatagram(cmd,cmd.size(),send_Ip,send_Port);//向5000端口写数据

    qDebug()<<(cmd);
    qDebug()<<QString(QHostAddress::LocalHost);
    qDebug()<<(QStringLiteral("读数据！"));
    }
}

void MainWindow::raly1_send()
{
    QByteArray cmd1;
    cmd1[0] = 0xA1;
    cmd1[2] = 0x00;
    if(ui->lineEdit_test->text().isEmpty()) //若没有获得目标ip
    {
        QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("请填刷卡获取目标IP以及端口！"));
    }
    else
    {
        //raly1 activting
        get_IP();
        udpSocket->writeDatagram(cmd1,cmd1.size(),send_Ip,send_Port);//向5000端口写数据
        qDebug()<< cmd1;
        qDebug()<< cmd1.size();

    }
}
void MainWindow::raly2_send()
{
    QByteArray cmd2;
    cmd2[0] = 0xA1;
    cmd2[1] = 0x01;

    if(ui->lineEdit_test->text().isEmpty()) //若没有获得目标ip
    {
        QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("请填刷卡获取目标IP以及端口！"));
    }
    else
    {
        //raly2 activting
        get_IP();
        udpSocket->writeDatagram(cmd2,cmd2.size(),send_Ip,send_Port);//向目标端口写数据
        qDebug()<< cmd2;
        qDebug()<< cmd2.size()-1;
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

    qDebug() << (QStringLiteral("<----------接收地址信息:")) << datagram << "-------->";
    qDebug() << QString::number(datagram[0]);
//    ui->lineEdit_test->setText(QString::number(uchar(tmp[0])));

    QString h_ip,mk,gy,r_ip,mac;
    QString send_Ip_Port;

    if((tmp[0]&0xFF)==0xA0)
    {
        qDebug() << send_Ip;
        qDebug() << send_Port;
        send_Ip_Port.append(QStringLiteral("目标IP:"));
        send_Ip_Port.append(send_Ip.toString());
        send_Ip_Port.append(":");
        send_Ip_Port.append(QString::number(uint(send_Port)));
        ui->lineEdit_test->setText(send_Ip_Port);
    }
    if((tmp[0]&0xFF)==0xB1){
    h_ip.append(num_to_str(datagram[1]));
    h_ip.append(".");
    h_ip.append(num_to_str(datagram[2]));
    h_ip.append(".");
    h_ip.append(num_to_str(datagram[3]));
    h_ip.append(".");
    h_ip.append(num_to_str(datagram[4]));

    mk.append(num_to_str(datagram[5]));
    mk.append(".");
    mk.append(num_to_str(datagram[6]));
    mk.append(".");
    mk.append(num_to_str(datagram[7]));
    mk.append(".");
    mk.append(num_to_str(datagram[8]));

    gy.append(num_to_str(datagram[9]));
    gy.append(".");
    gy.append(num_to_str(datagram[10]));
    gy.append(".");
    gy.append(num_to_str(datagram[11]));
    gy.append(".");
    gy.append(num_to_str(datagram[12]));

    r_ip.append(num_to_str(datagram[13]));
    r_ip.append(".");
    r_ip.append(num_to_str(datagram[14]));
    r_ip.append(".");
    r_ip.append(num_to_str(datagram[15]));
    r_ip.append(".");
    r_ip.append(num_to_str(datagram[16]));

    mac.append(num_to_str(datagram[17]));
    mac.append(".");
    mac.append(num_to_str(datagram[18]));
    mac.append(".");
    mac.append(num_to_str(datagram[19]));
    mac.append(".");
    mac.append(num_to_str(datagram[20]));

    ui->lineEdit_host_ip->setText(h_ip);
    ui->lineEdit_mask->setText(mk);
    ui->lineEdit_gateway->setText(gy);
    ui->lineEdit_route_ip->setText(r_ip);
    ui->lineEdit_mac->setText(mac);
    QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("获取完成！"));
    }
}



void MainWindow:: get_IP()
{
//    QByteArrayList datas;
    QString     test_ip;
//    QByteArray  test_port;
    bool ok;

    test_ip=ui->lineEdit_test->text().section(":",0,0);
    send_Ip=QHostAddress(test_ip);
    qDebug()<< send_Ip;

    send_Port = ui->lineEdit_test->text().section(":",1,1).toInt(&ok,10);
}

void MainWindow::Scan()
{
    QByteArray cmd_scan;
    cmd_scan[0] = 0xb2;
    udpSocket->writeDatagram(cmd_scan,cmd_scan.size(),QHostAddress("255.255.255.255"),2000);//向5000端口写数据
    list_scan(cmd_scan.data());
}

void MainWindow::list_scan(char *scan)
{
 //   QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
    QList<QByteArray>lists;
//    if((scan[0]==0x00)&&(scan[1]==0x33)&&(scan[2]==0x35))
     {
        lists.append(QByteArray("设备"));
        foreach(QByteArray list, lists)
        {
            if(scan==list){return;}  //查询lists是否有相同的mac
            else{lists.append(scan);} //如果没有向lists插入mac

        }

        ui->comboBox->clear();  //清空内容
        foreach (QByteArray list, lists) {
        ui->comboBox->addItem(list);  //将lists的之后写入到combox
        }
   }

}

