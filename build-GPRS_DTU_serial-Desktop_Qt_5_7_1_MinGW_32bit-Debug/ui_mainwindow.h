/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_serial;
    QComboBox *comboBox_com;
    QLabel *label_baud;
    QComboBox *comboBox_buad;
    QLabel *label_byte;
    QComboBox *comboBox_byte;
    QLabel *label_check;
    QComboBox *comboBox_check;
    QLabel *label_stop;
    QComboBox *comboBox_stop;
    QPushButton *pushButton_open_serial;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_connet;
    QComboBox *comboBox_connet;
    QLabel *label_IP_port;
    QLineEdit *lineEdit_ip;
    QLineEdit *lineEdit_port;
    QLabel *label;
    QComboBox *comboBox_baudw;
    QPushButton *pushButton_config_serial;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_version;
    QPushButton *pushButton_signal;
    QPushButton *pushButton_in_config;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_pin;
    QPushButton *pushButton_creg;
    QPushButton *pushButton_in_check;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_greg;
    QPushButton *pushButton_operator;
    QPushButton *pushButton_out_config;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *pushButton_clear;
    QRadioButton *radioButton_hex;
    QRadioButton *radioButton_ascii;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(688, 428);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_serial = new QLabel(groupBox);
        label_serial->setObjectName(QStringLiteral("label_serial"));

        horizontalLayout_3->addWidget(label_serial);

        comboBox_com = new QComboBox(groupBox);
        comboBox_com->setObjectName(QStringLiteral("comboBox_com"));

        horizontalLayout_3->addWidget(comboBox_com);

        label_baud = new QLabel(groupBox);
        label_baud->setObjectName(QStringLiteral("label_baud"));
        label_baud->setMouseTracking(false);

        horizontalLayout_3->addWidget(label_baud);

        comboBox_buad = new QComboBox(groupBox);
        comboBox_buad->setObjectName(QStringLiteral("comboBox_buad"));

        horizontalLayout_3->addWidget(comboBox_buad);

        label_byte = new QLabel(groupBox);
        label_byte->setObjectName(QStringLiteral("label_byte"));

        horizontalLayout_3->addWidget(label_byte);

        comboBox_byte = new QComboBox(groupBox);
        comboBox_byte->setObjectName(QStringLiteral("comboBox_byte"));

        horizontalLayout_3->addWidget(comboBox_byte);

        label_check = new QLabel(groupBox);
        label_check->setObjectName(QStringLiteral("label_check"));

        horizontalLayout_3->addWidget(label_check);

        comboBox_check = new QComboBox(groupBox);
        comboBox_check->setObjectName(QStringLiteral("comboBox_check"));

        horizontalLayout_3->addWidget(comboBox_check);

        label_stop = new QLabel(groupBox);
        label_stop->setObjectName(QStringLiteral("label_stop"));

        horizontalLayout_3->addWidget(label_stop);

        comboBox_stop = new QComboBox(groupBox);
        comboBox_stop->setObjectName(QStringLiteral("comboBox_stop"));

        horizontalLayout_3->addWidget(comboBox_stop);

        pushButton_open_serial = new QPushButton(groupBox);
        pushButton_open_serial->setObjectName(QStringLiteral("pushButton_open_serial"));

        horizontalLayout_3->addWidget(pushButton_open_serial);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_connet = new QLabel(groupBox_3);
        label_connet->setObjectName(QStringLiteral("label_connet"));

        horizontalLayout->addWidget(label_connet);

        comboBox_connet = new QComboBox(groupBox_3);
        comboBox_connet->setObjectName(QStringLiteral("comboBox_connet"));

        horizontalLayout->addWidget(comboBox_connet);

        label_IP_port = new QLabel(groupBox_3);
        label_IP_port->setObjectName(QStringLiteral("label_IP_port"));

        horizontalLayout->addWidget(label_IP_port);

        lineEdit_ip = new QLineEdit(groupBox_3);
        lineEdit_ip->setObjectName(QStringLiteral("lineEdit_ip"));

        horizontalLayout->addWidget(lineEdit_ip);

        lineEdit_port = new QLineEdit(groupBox_3);
        lineEdit_port->setObjectName(QStringLiteral("lineEdit_port"));
        lineEdit_port->setMinimumSize(QSize(50, 0));
        lineEdit_port->setMaximumSize(QSize(100, 16777215));

        horizontalLayout->addWidget(lineEdit_port);

        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        comboBox_baudw = new QComboBox(groupBox_3);
        comboBox_baudw->setObjectName(QStringLiteral("comboBox_baudw"));
        comboBox_baudw->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(comboBox_baudw);

        pushButton_config_serial = new QPushButton(groupBox_3);
        pushButton_config_serial->setObjectName(QStringLiteral("pushButton_config_serial"));

        horizontalLayout->addWidget(pushButton_config_serial);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_version = new QPushButton(groupBox_2);
        pushButton_version->setObjectName(QStringLiteral("pushButton_version"));

        horizontalLayout_2->addWidget(pushButton_version);

        pushButton_signal = new QPushButton(groupBox_2);
        pushButton_signal->setObjectName(QStringLiteral("pushButton_signal"));

        horizontalLayout_2->addWidget(pushButton_signal);

        pushButton_in_config = new QPushButton(groupBox_2);
        pushButton_in_config->setObjectName(QStringLiteral("pushButton_in_config"));

        horizontalLayout_2->addWidget(pushButton_in_config);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_pin = new QPushButton(groupBox_2);
        pushButton_pin->setObjectName(QStringLiteral("pushButton_pin"));

        horizontalLayout_5->addWidget(pushButton_pin);

        pushButton_creg = new QPushButton(groupBox_2);
        pushButton_creg->setObjectName(QStringLiteral("pushButton_creg"));

        horizontalLayout_5->addWidget(pushButton_creg);

        pushButton_in_check = new QPushButton(groupBox_2);
        pushButton_in_check->setObjectName(QStringLiteral("pushButton_in_check"));

        horizontalLayout_5->addWidget(pushButton_in_check);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_greg = new QPushButton(groupBox_2);
        pushButton_greg->setObjectName(QStringLiteral("pushButton_greg"));

        horizontalLayout_4->addWidget(pushButton_greg);

        pushButton_operator = new QPushButton(groupBox_2);
        pushButton_operator->setObjectName(QStringLiteral("pushButton_operator"));

        horizontalLayout_4->addWidget(pushButton_operator);

        pushButton_out_config = new QPushButton(groupBox_2);
        pushButton_out_config->setObjectName(QStringLiteral("pushButton_out_config"));

        horizontalLayout_4->addWidget(pushButton_out_config);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addWidget(groupBox_2);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        pushButton_clear = new QPushButton(centralWidget);
        pushButton_clear->setObjectName(QStringLiteral("pushButton_clear"));

        horizontalLayout_7->addWidget(pushButton_clear);

        radioButton_hex = new QRadioButton(centralWidget);
        radioButton_hex->setObjectName(QStringLiteral("radioButton_hex"));

        horizontalLayout_7->addWidget(radioButton_hex);

        radioButton_ascii = new QRadioButton(centralWidget);
        radioButton_ascii->setObjectName(QStringLiteral("radioButton_ascii"));

        horizontalLayout_7->addWidget(radioButton_ascii);

        lineEdit_send = new QLineEdit(centralWidget);
        lineEdit_send->setObjectName(QStringLiteral("lineEdit_send"));

        horizontalLayout_7->addWidget(lineEdit_send);

        pushButton_send = new QPushButton(centralWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        horizontalLayout_7->addWidget(pushButton_send);


        verticalLayout->addLayout(horizontalLayout_7);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 688, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "GPRS-485", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\277\236\346\216\245", Q_NULLPTR));
        label_serial->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", Q_NULLPTR));
        label_baud->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label_byte->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_check->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        label_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        pushButton_open_serial->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR));
        label_connet->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\347\261\273\345\236\213", Q_NULLPTR));
        label_IP_port->setText(QApplication::translate("MainWindow", "\345\234\260\345\235\200\344\270\216\347\253\257\345\217\243", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        pushButton_config_serial->setText(QApplication::translate("MainWindow", "\345\217\202\346\225\260\351\205\215\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_version->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\211\210\346\234\254", Q_NULLPTR));
        pushButton_signal->setText(QApplication::translate("MainWindow", "\346\237\245\344\277\241\345\217\267\345\274\272\345\272\246", Q_NULLPTR));
        pushButton_in_config->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_pin->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242PIN", Q_NULLPTR));
        pushButton_creg->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_in_check->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_greg->setText(QApplication::translate("MainWindow", "GPRS\347\212\266\346\200\201", Q_NULLPTR));
        pushButton_operator->setText(QApplication::translate("MainWindow", "\346\237\245\350\277\220\350\241\214\345\225\206", Q_NULLPTR));
        pushButton_out_config->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\351\205\215\347\275\256", Q_NULLPTR));
        pushButton_clear->setText(QApplication::translate("MainWindow", "\346\270\205\347\251\272\347\252\227\345\217\243", Q_NULLPTR));
        radioButton_hex->setText(QApplication::translate("MainWindow", "hex", Q_NULLPTR));
        radioButton_ascii->setText(QApplication::translate("MainWindow", "ASCII", Q_NULLPTR));
        pushButton_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
