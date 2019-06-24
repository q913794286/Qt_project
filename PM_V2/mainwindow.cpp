#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>



#include <QSerialPort>
#include <QSerialPortInfo>

#include <QVariant>

QButtonGroup *btnGroupFruits;

QHostAddress send_Ip; //发送端ip
quint16 send_Port; //发送端端口

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSeialPort();
    ui->pushButton->setText(QStringLiteral("打开串口"));
   /***UDP_server****/
    qDebug() << QHostAddress(QHostAddress::AnyIPv4).toString();
    udpSocket = new QUdpSocket();
    QHostAddress multiAddr("224.0.0.71");//这里要选一个组播地址
    if(udpSocket->bind(QHostAddress("0.0.0.0"),7788,QAbstractSocket::ShareAddress)==false)//绑定读数据端口(监听端口)，允许其他服务绑定到此端口
    {

      qDebug() << ("Server socket bind faileds!");
//      return;
    }
//    udpSocket->setSocketOption(QAbstractSocket::MulticastLoopbackOption,0); //设置缓冲区
    //加入组播组
    if(udpSocket->joinMulticastGroup(multiAddr)==true)
        {
        qDebug()<<QStringLiteral("加入组播成功！");
        }

    QObject::connect(udpSocket, SIGNAL(readyRead()),this,SLOT(UDP_Recv()));
    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(button()));
    qDebug() << "UDP Server Running...";

    /*界面信号与槽*/


    /****edit初始化参数*****/
    ui->lineEdit_PM2_5->setPlaceholderText("PM2.5");
    ui->lineEdit_PM10->setPlaceholderText("PM10");
    ui->lineEdit_PM2_5_cf->setPlaceholderText("cf=1 PM2.5");
    ui->lineEdit_PM10_cf->setPlaceholderText("cf=1 PM10");

    ui->lineEdit_PM2_5->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_PM10->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_PM2_5_cf->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_PM10_cf->setFocusPolicy(Qt::NoFocus);

    qDebug()<<(QStringLiteral(" 界面启动完成！"));
}

MainWindow::~MainWindow()
{
    serial.close();
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
//    MainWindow::json(datagram);
    QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("获取完成！"));

}



void MainWindow::initSeialPort()
{

    connect(&serial,SIGNAL(readyRead()),this,SLOT(serialRead()));	//连接槽
//    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_currentIndexChanged(QString)));

    //get name for choose
    QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();

    if(infos.isEmpty())
    {
        ui->comboBox->addItem(QStringLiteral("无效"));
        return;
    }
    ui->comboBox->addItem(QStringLiteral("无"));
    foreach (QSerialPortInfo info, infos) {
        ui->comboBox->addItem(info.portName());
    }
}

void MainWindow::button()
{
    QString arg1;
    static bool press;
    arg1 = ui->comboBox->currentText();
    qDebug() << QStringLiteral("获取当前值：");
    qDebug() << arg1;
    MainWindow::on_comboBox_currentIndexChanged(arg1);
    if(!press&&(ui->comboBox->currentIndex()!=0))
    {
     ui->pushButton->setText(QStringLiteral("关闭串口"));
     press = true;
     }
    else
    {
        serial.close();
        ui->pushButton->setText(QStringLiteral("打开串口"));
        press = false;
    }
}

void MainWindow::on_comboBox_currentIndexChanged(QString &arg1)
{
    QSerialPortInfo info;

//  arg1 = ui->comboBox->currentText();
    qDebug() << QStringLiteral("获取当前值：");
    qDebug() << arg1;
    QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    int i = 0;
    foreach (info, infos) {
        if(info.portName() == arg1) break;
        i++;
    }
    if(i != infos.size ()){//can find
        serial.close();
        serial.setPort(info);
        serial.open(QIODevice::ReadWrite);         //读写打开
        serialportconfig(arg1);
    }
    else
    {
        serial.close();
    }

}

void MainWindow::serialportconfig(QString arg)
{
    QSerialPort *serial;
    serial = new QSerialPort(arg);       //串口号，一定要对应好，大写！！！串口号一般要修改。
    serial->open(QIODevice::ReadWrite);      //读写打开
    serial->setBaudRate(QSerialPort::Baud9600);  //波特率
    serial->setDataBits(QSerialPort::Data8); //数据位
    serial->setParity(QSerialPort::NoParity);    //无奇偶校验
    serial->setStopBits(QSerialPort::OneStop);   //无停止位
    serial->setFlowControl(QSerialPort::NoFlowControl);  //无控制
}

void MainWindow::serialRead()
{

    static QByteArray allData;         //静态变量！！在串口只得到一部分的时候用来累加数据
    QByteArray dataTemp;            	//本次接收的数据，可能是前半部分数据或者后半部分数据（甚至是被分割为多段数据的其中一部分数据），或者也可能是完整数据。
    while (!serial.atEnd()) {
         dataTemp = serial.readAll();                //因为串口是不稳定的，也许读到的是部分数据而已，但也可能是全部数据
        if( dataTemp.data()[dataTemp.length() - 1] == '\n'){     //当临时数据最后一位是'~'，代表一条数据读完了
//            allData += dataTemp;                                //总数据加上本次数据
//            allData.resize(allData.size() - 1);                 //删除结尾的~符号
//            qCritical() << allData;                             //这时候allData将是你要的数据
            if(allData.size()==11)
            {

                ser_buff = allData;
                qDebug() << (ser_buff);
                MainWindow::display();
            }
            qDebug() << allData.size();
            allData.clear();                                    //清除数据!!!!!
        }
        else
            {//当最后一位数据不是'\n'，即未读完
            allData += dataTemp;                               //每次累加这部分数据,因为还没发完
        }
    }


}

void MainWindow::display()
{
    QString PM = QString(ser_buff);

    ui->lineEdit_PM2_5->setText(PM.section(",",0,0));
    ui->lineEdit_PM10 ->setText(PM.section(",",1,1));
    ui->lineEdit_PM2_5_cf->setText(PM.section(",",2,2));
    ui->lineEdit_PM10_cf->setText(PM.section(",",3,3));
}
