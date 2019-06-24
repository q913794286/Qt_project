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
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_pass_mode;
    QRadioButton *radioButton_pass;
    QRadioButton *radioButton_aes128;
    QPushButton *pushButton_pass_check;
    QPushButton *pushButton_pass_config;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_in_config;
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
        MainWindow->resize(718, 628);
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

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_pass_mode = new QLabel(groupBox_4);
        label_pass_mode->setObjectName(QStringLiteral("label_pass_mode"));

        horizontalLayout_8->addWidget(label_pass_mode);

        radioButton_pass = new QRadioButton(groupBox_4);
        radioButton_pass->setObjectName(QStringLiteral("radioButton_pass"));

        horizontalLayout_8->addWidget(radioButton_pass);

        radioButton_aes128 = new QRadioButton(groupBox_4);
        radioButton_aes128->setObjectName(QStringLiteral("radioButton_aes128"));

        horizontalLayout_8->addWidget(radioButton_aes128);

        pushButton_pass_check = new QPushButton(groupBox_4);
        pushButton_pass_check->setObjectName(QStringLiteral("pushButton_pass_check"));

        horizontalLayout_8->addWidget(pushButton_pass_check);

        pushButton_pass_config = new QPushButton(groupBox_4);
        pushButton_pass_config->setObjectName(QStringLiteral("pushButton_pass_config"));

        horizontalLayout_8->addWidget(pushButton_pass_config);


        verticalLayout_5->addLayout(horizontalLayout_8);


        verticalLayout->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));

        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_in_config = new QPushButton(groupBox_2);
        pushButton_in_config->setObjectName(QStringLiteral("pushButton_in_config"));

        horizontalLayout_4->addWidget(pushButton_in_config);

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
        menuBar->setGeometry(QRect(0, 0, 718, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\344\270\262\345\217\243\350\277\236\346\216\245", Q_NULLPTR));
        label_serial->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243", Q_NULLPTR));
        label_baud->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label_byte->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_check->setText(QApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        label_stop->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        pushButton_open_serial->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "\346\250\241\345\274\217", Q_NULLPTR));
        label_pass_mode->setText(QApplication::translate("MainWindow", "\344\274\240\350\276\223\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_pass->setText(QApplication::translate("MainWindow", "\351\200\217\344\274\240\346\250\241\345\274\217", Q_NULLPTR));
        radioButton_aes128->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\250\241\345\274\217", Q_NULLPTR));
        pushButton_pass_check->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_pass_config->setText(QApplication::translate("MainWindow", "\346\250\241\345\274\217\351\205\215\347\275\256", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
        pushButton_in_config->setText(QApplication::translate("MainWindow", "\350\277\233\345\205\245\351\205\215\347\275\256", Q_NULLPTR));
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
