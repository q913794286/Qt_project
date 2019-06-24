#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mythread.h"

#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>

#include <QVariant>
#include <QThread>
#include <QTime>


QButtonGroup *btnGroup;

QHostAddress send_Ip,send_Ip1; //发送端ip
quint16 send_Port,send_Port1; //发送端端口
QByteArray mac;

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

    QObject::connect(ui->radioButton_1, SIGNAL(clicked()), this, SLOT(onRadiobutton1()));
    QObject::connect(ui->radioButton_2, SIGNAL(clicked()), this, SLOT(onRadiobutton2()));

    /*线程初始化*/
    MyThread1 = new MyThread;
    connect(MyThread1,SIGNAL(finished()),this,SLOT(finish_Thread()));
//    QObject::connect(ui->comboBox,SIGNAL(activated(int)),this,SLOT(combox_dis()));
    /****edit初始化参数*****/
    ui->lineEdit_host_ip->setPlaceholderText("192.168.0.90");
    ui->lineEdit_mask->setPlaceholderText("255.255.255.0");
    ui->lineEdit_gateway->setPlaceholderText("192.168.0.1");
    ui->lineEdit_route_ip->setPlaceholderText("192.168.0.60");
    ui->lineEdit_mac->setText("0F:FF:FF:FF:FF:0F");
    ui->lineEdit_mac->setFocusPolicy(Qt::NoFocus); //设置mac地址框不可聚焦
    ui->lineEdit_mac->setEnabled(false);
    ui->comboBox->addItem(QString("设备"));

    btnGroup = new QButtonGroup(this);
    btnGroup->addButton(ui->radioButton_1,1);
    btnGroup->addButton(ui->radioButton_2,2);
    ui->radioButton_1->setChecked(1);
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
QString WString[4];
void MainWindow::button_write()
{
    if(ui->comboBox->currentText() == QString("设备")) //若没有获得目标ip
    {
        QMessageBox::information(this,  QStringLiteral("设置完成"),QStringLiteral("请选择设备！"));
    }
    else
    {
  /*****设置参数***************/

     WString[0]= ui->lineEdit_host_ip->text();
     WString[1]= ui->lineEdit_mask->text();
     WString[2]= ui->lineEdit_gateway->text();
     WString[3]= ui->lineEdit_route_ip->text();

    QByteArray cmd,h_ip,mk,gy,r_ip,mac;
    bool ok;

    cmd[0] = 0xD0;
//    cmd[1] = 0;
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
    combox_mac();
    udpSocket->writeDatagram(cmd[0]+h_ip+mk+gy+r_ip+mac,QByteArray(cmd[0]+h_ip+mk+gy+r_ip+mac).size(),send_Ip,send_Port);//向5000端口写数据
    qDebug()<< QStringLiteral(" 写数据！");
    qDebug()<< QStringLiteral("发送字节:")+QString::number((QByteArray(cmd[0]+h_ip+mk+gy+r_ip+mac).size()-1));

    MyThread1->start();

    }
 }

void MainWindow::button_read()
{
    if(ui->comboBox->currentText() == QString("设备")) //若没有获得目标ip
    {
      QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("请选择设备！"));
    }
    else
    {
    QByteArray cmd;
    cmd[0] = 0xD1;
    get_IP();
    combox_mac();
    udpSocket->writeDatagram(cmd+mac,cmd.size()+mac.size(),send_Ip,send_Port);//向5000端口写数据

    qDebug()<<(cmd+mac);
    qDebug()<<QString(QHostAddress::LocalHost);
    qDebug()<<(QStringLiteral("读数据！"));
    }
}

void MainWindow::raly1_send()
{
    QByteArray cmd1;
    cmd1[0] = 0xA1;
    cmd1[1] = 0x00;
    if(ui->lineEdit_test->text().isEmpty()) //若没有获得目标ip
    {
        QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("请填刷卡获取目标IP以及端口！"));
    }
    else
    {
        //raly1 activting
        get_IP();
        udpSocket->writeDatagram(cmd1,cmd1.size(),send_Ip1,send_Port1);//向5000端口写数据
        qDebug()<< "raly1 cmd:"+cmd1;
        qDebug()<< "raly1 byet:"+cmd1.size()-1;

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
        udpSocket->writeDatagram(cmd2,cmd2.size(),send_Ip1,send_Port1);//向目标端口写数据
        qDebug()<< "raly2 cmd:"+cmd2;
        qDebug()<< "raly2 byet:"+cmd2.size()-1;
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
        udpSocket->readDatagram(datagram.data(), datagram.size(),&send_Ip1, &send_Port1);
        qDebug() << datagram;
        recvStr = QString(datagram);
    }

    tmp = datagram.data();// QByteArray转换成char

    qDebug() << (QStringLiteral("<----------接收地址信息:")) << datagram << "-------->";
    qDebug() << QString::number(datagram[0]);
//    ui->lineEdit_test->setText(QString::number(uchar(tmp[0])));

    QString h_ip,mk,gy,r_ip,mac_h;
    QString send_Ip_Port;

    if((tmp[0]&0xFF)==0xA0)  //刷卡获取信息
    {
        qDebug() << send_Ip;
        qDebug() << send_Port;
        send_Ip_Port.append(QStringLiteral("目标IP:"));
        send_Ip_Port.append(send_Ip.toString());
        send_Ip_Port.append(":");
        send_Ip_Port.append(QString::number(uint(send_Port)));
        ui->lineEdit_test->setText(send_Ip_Port);
    }

    if(((tmp[0]&0xFF)==0xb1)||((tmp[0]&0xFF)==0xD1)){
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

    mac_h.append("00");
    mac_h.append(":");
    mac_h.append("33");
    mac_h.append(":");
    mac_h.append("35");
    mac_h.append(":");
    mac_h.append(num_to_str(datagram[17]));
    mac_h.append(":");
    mac_h.append(num_to_str(datagram[18]));
    mac_h.append(":");
    mac_h.append(num_to_str(datagram[19]));

    ui->lineEdit_host_ip->setText(h_ip);
    ui->lineEdit_mask->setText(mk);
    ui->lineEdit_gateway->setText(gy);
    ui->lineEdit_route_ip->setText(r_ip);
    ui->lineEdit_mac->setText(mac_h);
    QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("获取完成！"));
    }
    if((tmp[0]&0xFF)==0xC1)
    {
        list_scan(datagram);
    }
    qDebug() << "rec data:"+datagram;
    if((tmp[0]&0xFF)==0xC2)
    {
        if(datagram[1]==mac[0]&&
           datagram[2]==mac[1]&&
           datagram[3]==mac[2])
        {
            send_finish=true;
        }
    }
}

void MainWindow:: get_IP()
{
//    qDebug() << btnGroup->checkedId();
//    if(btnGroup->checkedId()==1){
        QString     test_ip;
        bool ok;

        test_ip=ui->lineEdit_test->text().section(":",0,0);
        send_Ip=QHostAddress(test_ip);
        qDebug()<< send_Ip;
        send_Port = ui->lineEdit_test->text().section(":",1,1).toInt(&ok,10);
//    }

}
QList<QString>lists;

void MainWindow::Scan()
{
    QByteArray cmd_scan;
    cmd_scan[0] = 0xC1;
    lists.clear();
    ui->comboBox->clear();
    ui->comboBox->insertItem(0,"设备");
    get_IP();
    udpSocket->writeDatagram(cmd_scan,1,send_Ip,send_Port);//向5000端口写数据
 //   list_scan(NULL);
    qDebug()<< "scan cmd:"+cmd_scan;
}

void MainWindow::list_scan(QByteArray scan)
{
    QString str;
    qDebug()<< "list_scan data:"+scan;
        str.append(num_to_str(scan[1]));
        str.append(":");
        str.append(num_to_str(scan[2]));
        str.append(":");
        str.append(num_to_str(scan[3]));
    qDebug() << str;
     if((scan[0]&0xff)==0xc1)
     {
         lists.insert(0,"设备");
        foreach(QString list, lists)
        {
            if(str==list) //查询lists是否有相同的mac
            {
                goto combox_into;
            }
            else if(lists.isEmpty())
            {
                lists.append(str);
            }
            else
            {
                lists.append(str);
            } //如果没有向lists插入mac
        }
combox_into:
        ui->comboBox->clear();  //清空内容
//        ui->comboBox->addItem(QString("设备"));
        foreach (QString list, lists) {
        ui->comboBox->addItem(list);  //将lists的之后写入到combox
        }
   }

}

void MainWindow::combox_mac()
{
    bool ok;
    qDebug() << "comboox_dis";
    QString get_comboxText;
    get_comboxText = ui->comboBox->currentText();
    mac[0] = get_comboxText.section(":",0,0).toInt(&ok,10);
    mac[1] = get_comboxText.section(":",1,1).toInt(&ok,10);
    mac[2] = get_comboxText.section(":",2,2).toInt(&ok,10);
    qDebug()<< "combox_mac value:"+mac;

}

void MainWindow::onRadiobutton1()
{
  ui->lineEdit_test->setText("192.168.0.90:2000");
}

void MainWindow::onRadiobutton2()
{
  ui->lineEdit_test->setText("192.168.0.255:2000");
}

void MainWindow::finish_Thread()
{
   if(send_finish==true)
   {
       QMessageBox::information(this,  QStringLiteral("设置已发送"),
             QStringLiteral("本机地址：")+WString[0]+"\r\n"+
             QStringLiteral("子网掩码：")+WString[1]+"\r\n"+
             QStringLiteral("网   关：")+WString[2]+"\r\n"+
             QStringLiteral("服务器IP：")+WString[3]+"\r\n" );
       send_finish = false;
       /*关闭多线程*/
        MyThread1->wait();
        return;
   }

   QTime _Timer = QTime::currentTime().addMSecs(500);
   while(QTime::currentTime()<_Timer)
   {
      MyThread1->wait();
      QMessageBox::warning(NULL, "warning", QStringLiteral("设置失败"), QMessageBox::Yes, QMessageBox::Yes);
   }

}
