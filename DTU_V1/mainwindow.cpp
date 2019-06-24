#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QButtonGroup>
#include <QMessageBox>
#include <QDebug>




#include <QSerialPort>
#include <QSerialPortInfo>

#include <QVariant>

QButtonGroup *btnGroupFruits;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSeialPort();

    QRegExp regExp("[ a-fA-F0-9]+$"); //只允许输入16进制
    ui->lineEdit_key->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_iv->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit_id->setValidator(new QRegExpValidator(regExp, this));
    ui->pushButton->setText(QStringLiteral("打开串口"));


    QObject::connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(button()));
    QObject::connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(button_2()));
    qDebug() << "UDP Server Running...";

    /*界面信号与槽*/


    /****edit初始化参数*****/
    ui->lineEdit_key->setPlaceholderText("key");
    ui->lineEdit_iv->setPlaceholderText("iv");
    ui->lineEdit_id->setPlaceholderText("id");

    ui->lineEdit_key->setText("01 02 03 04 05 06 07 07 09 10 11 12 13 14 15 16");
    ui->lineEdit_iv->setText("01 02 03 04 05 06 07 07 09 10 11 12 13 14 15 16");
    ui->lineEdit_id->setText("01 02 03 04 05 06 07 07 09 10 11 12 13 14 15 16");

    ui->lineEdit_key->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_iv->setFocusPolicy(Qt::NoFocus);
    ui->lineEdit_id->setFocusPolicy(Qt::NoFocus);

    qDebug()<<(QStringLiteral(" 界面启动完成！"));
}

MainWindow::~MainWindow()
{
    serial.close();
    delete ui;
}


//=======串口

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

void MainWindow::serialRead()
{

    static QByteArray allData;         //静态变量！！在串口只得到一部分的时候用来累加数据
    QByteArray dataTemp;            	//本次接收的数据，可能是前半部分数据或者后半部分数据（甚至是被分割为多段数据的其中一部分数据），或者也可能是完整数据。
    while (!serial.atEnd()) {
         dataTemp = serial.readAll();                //因为串口是不稳定的，也许读到的是部分数据而已，但也可能是全部数据
        if( dataTemp.data()[dataTemp.length() - 1] == '\n')
        {     //当临时数据最后一位是'~'，代表一条数据读完了
            if(allData.size()==11)
            {
                ser_buff = allData;
                qDebug() << (ser_buff);
                if(ser_buff=="ok")
                {
                    //配置完成
                }
 //               MainWindow::display();
            }
            qDebug() << allData.size();
            allData.clear();                                    //清除数据!!!!!
        }
        else
        {   //当最后一位数据不是'\n'，即未读完
            allData += dataTemp;                               //每次累加这部分数据,因为还没发完
        }
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

void MainWindow::button_2()
{
   QString  all_string , s_key, s_iv, s_id;
   QByteArray  all_Array;

    s_key = ui->lineEdit_key->text();
    s_iv  = ui->lineEdit_iv->text();
    s_id  = ui->lineEdit_id->text();

    all_string.clear();
    all_string.append(s_key);
    all_string.append(s_iv);
    all_string.append(s_id);
    all_Array = QByteArray::fromHex(all_string.toLatin1().data());

    int len = (QByteArray::fromHex(s_key.toLatin1().data()).size())+\
              (QByteArray::fromHex(s_iv.toLatin1().data()).size())+\
              (QByteArray::fromHex(s_id.toLatin1().data()).size());
    qDebug() << all_Array;
    qDebug() << len;
 //   if(len<16) ui->label_2->setText("小于16字节");
    if(ui->pushButton->text()=="关闭串口")
    {
    serial.write(all_Array,len);
    qDebug() << QStringLiteral("发送完成");
    }
    else{
      QMessageBox::information(this,  QStringLiteral("提示"),QStringLiteral("串口没有打开！"));
    }
//    qDebug() << len;
//    if(len!=16) {qDebug() << "key != 16 \r\n"; }

}
