#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSerialPort>
#include <QSerialPortInfo>

#include <QDebug>



/*
*  串口更新
*/

void MainWindow::initSeialPort()
{
     QObject::connect(&serial,SIGNAL(readyRead()),this,SLOT(serialRead()));	//连接槽
     QObject::connect(timer, SIGNAL(timeout()), this, SLOT(timeUpdate()));  //串口超时触发
//    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(on_comboBox_currentIndexChanged(QString)));
    QObject::connect(ui->pushButton_open_serial,SIGNAL(clicked()),this,SLOT(button_open_close())); //打开关闭串口
    QObject::connect(ui->pushButton_clear,SIGNAL(clicked()),this,SLOT(button_claen()));//清屏
    //get name for choose
    QList<QSerialPortInfo>  infos = QSerialPortInfo::availablePorts();
    //加入com条目
    if(infos.isEmpty())
    {
        ui->comboBox_com->addItem(QStringLiteral("无效"));
        return;
    }
    ui->comboBox_com->addItem(QStringLiteral("无"));
    foreach (QSerialPortInfo info, infos) {
        ui->comboBox_com->addItem(info.portName());
    }
    //加入波特率条目
    ui->comboBox_buad->addItem(QStringLiteral("9600"));
    ui->comboBox_buad->addItem(QStringLiteral("115200"));
//    ui->comboBox_buad->setEnabled(false);
    //加入数据位条目
    ui->comboBox_byte->addItem(QStringLiteral("7"));
    ui->comboBox_byte->addItem(QStringLiteral("8"));
    ui->comboBox_byte->setCurrentIndex(1);
    //加入校验条目
    ui->comboBox_check->addItem(QStringLiteral("None"));
    ui->comboBox_check->addItem(QStringLiteral("Even"));
    ui->comboBox_check->addItem(QStringLiteral("Odd"));
    //加入停止位
    ui->comboBox_stop->addItem(QStringLiteral("1"));
    ui->comboBox_stop->addItem(QStringLiteral("2"));
    ui->comboBox_stop->addItem(QStringLiteral("1.5"));



    ui->radioButton_ascii->setChecked(true);

    ui->textBrowser->document()->setMaximumBlockCount(1000);   //最大显示行数


}

/*
 * 打开串口按键动作
*/
void MainWindow::button_open_close()
{
    QString com,com_byte,com_baud,com_check,com_stop;
    static bool press;
    com = ui->comboBox_com->currentText();
    com_baud = ui->comboBox_buad->currentText();
    com_byte = ui->comboBox_byte->currentText();
    com_check = ui->comboBox_check->currentText();
    com_stop  = ui->comboBox_stop->currentText();
    qDebug() << QStringLiteral("获取当前值：");
    qDebug() << com;
    qDebug() << com_baud;
    qDebug() << com_byte;
    qDebug() << com_check;
    qDebug() << com_stop;

    if((ui->comboBox_com->currentIndex()==0)&&(ui->pushButton_open_serial->text()==QStringLiteral("打开串口")))
    {
       ui->textBrowser->append(QStringLiteral("串口无效"));
    }
    else if((ui->comboBox_com->currentIndex()!=0)&&(ui->pushButton_open_serial->text()==QStringLiteral("打开串口")))
    {
     MainWindow::on_comboBox_currentIndexChanged(com, com_baud,  com_byte,  com_check,  com_stop);
     ui->pushButton_open_serial->setText(QStringLiteral("关闭串口"));
        ui->comboBox_com->setEnabled(false);
        ui->comboBox_buad->setEnabled(false);
        ui->comboBox_byte->setEnabled(false);
        ui->comboBox_check->setEnabled(false);
        ui->comboBox_stop->setEnabled(false);

     press = true;
     }
    else if((ui->comboBox_com->currentIndex()!=0)&&(ui->pushButton_open_serial->text()==QStringLiteral("关闭串口")))
    {
        serial.close();
        ui->textBrowser->append(QStringLiteral("串口已关闭"));
        ui->pushButton_open_serial->setText(QStringLiteral("打开串口"));
        ui->comboBox_com->setEnabled(true);
        ui->comboBox_buad->setEnabled(true);
        ui->comboBox_byte->setEnabled(true);
        ui->comboBox_check->setEnabled(true);
        ui->comboBox_stop->setEnabled(true);
        press = false;
    }
}

/*
 *打开或关闭串口配置操作
*/
void MainWindow::on_comboBox_currentIndexChanged(QString com, QString com_baud, QString com_byte, QString com_check, QString com_stop)
{
    QSerialPortInfo info;

//  arg1 = ui->comboBox->currentText();
    qDebug() << QStringLiteral("获取当前值：");
    qDebug() << com;
    qDebug() << com_baud;
    qDebug() << com_byte;
    qDebug() << com_check;
    qDebug() << com_stop;

    /*串口配置操作*/
    QList<QSerialPortInfo> infos = QSerialPortInfo::availablePorts();
    int i = 0;
    foreach (info, infos) {
        if(info.portName() == com) break;
        i++;
    }
    if(i != infos.size ()){//can find
        serial.close();
        serial.setPort(info);
        serial.open(QIODevice::ReadWrite);         //读写打开
        serialportconfig(com, com_baud,  com_byte,  com_check,  com_stop);                     //参数配置
    }
    else
    {
        serial.close();
    }

}

void MainWindow::serialportconfig(QString com, QString com_baud, QString com_byte, QString com_check, QString com_stop)
{
    QSerialPort *serial;
    serial = new QSerialPort(com);       //串口号，一定要对应好，大写！！！串口号一般要修改。
    serial_res = serial->open(QIODevice::ReadWrite);      //读写打开
    qDebug()<< serial_res;
    if(serial_res) ui->textBrowser->append(QStringLiteral("打开串口失败!"));
    if(serial_res==0) ui->textBrowser->append(QStringLiteral("打开串口成功!"));
    if(com_baud == QStringLiteral("9600"))
        serial->setBaudRate(QSerialPort::Baud9600);  //波特率
    if(com_baud == QStringLiteral("115200"))
        serial->setBaudRate(QSerialPort::Baud115200);  //波特率

    if(com_byte == QStringLiteral("Data7"))
        serial->setDataBits(QSerialPort::Data7); //数据位7
    if(com_byte == QStringLiteral("Data8"))
        serial->setDataBits(QSerialPort::Data8); //数据位8

    if(com_check == QStringLiteral("None"))
        serial->setParity(QSerialPort::NoParity);    //无奇偶校验
    if(com_check == QStringLiteral("Even"))
        serial->setParity(QSerialPort::EvenParity);    //奇校验
    if(com_check == QStringLiteral("Odd"))
        serial->setParity(QSerialPort::OddParity);    //偶校验

    if(com_stop == QStringLiteral("1"))
        serial->setStopBits(QSerialPort::OneStop);   //无停止位
    if(com_stop == QStringLiteral("2"))
        serial->setStopBits(QSerialPort::TwoStop);   //停止位2
    if(com_stop == QStringLiteral("1.5"))
        serial->setStopBits(QSerialPort::OneAndHalfStop);   //停止位2

    serial->setFlowControl(QSerialPort::NoFlowControl);  //无控制
}

void MainWindow::serialRead()
{
    timer->start(10);
    serial_buf.append(serial.readAll());

}

void MainWindow::timeUpdate()
{
    serial_RI = 0;
    timer->stop();
    if(serial_buf.length()!=0)
    {
        qDebug()<< "Rec—data:\n";
        qDebug()<< (serial_buf);
        qDebug()<< "\n";

        if(radioGroup2->checkedId()==1) //显示hex
        {
            QString strDisplay;
            QString str =serial_buf.toHex().data();
            str = str.toUpper();
            for(int i=0;i<str.length();i+=2)
            {
                QString st = str.mid(i,2);
                strDisplay += st;
                strDisplay += " ";
            }
              ui->textBrowser->insertPlainText(strDisplay);
        }
        else if(radioGroup2->checkedId()==2)
        {
             ui->textBrowser->insertPlainText(QString::fromLocal8Bit (serial_buf)); //解决中文乱码

        }
        ui->textBrowser->moveCursor(QTextCursor::End); //移到最后一行
        serial_buf.clear();
    }
}

void MainWindow::button_claen(){
     ui->textBrowser->setText("");
}
