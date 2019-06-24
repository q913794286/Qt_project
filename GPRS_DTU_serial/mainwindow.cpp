#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initSeialPort();
    module_config();
//    QObject::connect(ui->pushButton_config, SIGNAL(clicked(bool)),this,SLOT(button_config()));

}

MainWindow::~MainWindow()
{
    delete ui;
}




