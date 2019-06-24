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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_mask;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEdit_gateway;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLineEdit *lineEdit_mac;
    QLineEdit *lineEdit_route_ip;
    QLineEdit *lineEdit_host_ip;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_raly1;
    QPushButton *pushButton_raly2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_test;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(566, 347);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        MainWindow->setIconSize(QSize(24, 24));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lineEdit_mask = new QLineEdit(groupBox);
        lineEdit_mask->setObjectName(QStringLiteral("lineEdit_mask"));

        gridLayout->addWidget(lineEdit_mask, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_gateway = new QLineEdit(groupBox);
        lineEdit_gateway->setObjectName(QStringLiteral("lineEdit_gateway"));

        gridLayout->addWidget(lineEdit_gateway, 4, 2, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 8, 0, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setBaseSize(QSize(0, 2));
        label->setLineWidth(2);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_mac = new QLineEdit(groupBox);
        lineEdit_mac->setObjectName(QStringLiteral("lineEdit_mac"));
        lineEdit_mac->setReadOnly(false);

        gridLayout->addWidget(lineEdit_mac, 6, 2, 1, 1);

        lineEdit_route_ip = new QLineEdit(groupBox);
        lineEdit_route_ip->setObjectName(QStringLiteral("lineEdit_route_ip"));

        gridLayout->addWidget(lineEdit_route_ip, 8, 2, 1, 1);

        lineEdit_host_ip = new QLineEdit(groupBox);
        lineEdit_host_ip->setObjectName(QStringLiteral("lineEdit_host_ip"));

        gridLayout->addWidget(lineEdit_host_ip, 0, 2, 1, 1);


        verticalLayout_2->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton_raly1 = new QPushButton(centralWidget);
        pushButton_raly1->setObjectName(QStringLiteral("pushButton_raly1"));

        horizontalLayout->addWidget(pushButton_raly1);

        pushButton_raly2 = new QPushButton(centralWidget);
        pushButton_raly2->setObjectName(QStringLiteral("pushButton_raly2"));

        horizontalLayout->addWidget(pushButton_raly2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        pushButton_1 = new QPushButton(centralWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));

        horizontalLayout->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setCursor(QCursor(Qt::ArrowCursor));
        pushButton_2->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout_2->addLayout(horizontalLayout);

        lineEdit_test = new QLineEdit(centralWidget);
        lineEdit_test->setObjectName(QStringLiteral("lineEdit_test"));

        verticalLayout_2->addWidget(lineEdit_test);

        verticalLayout_2->setStretch(0, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 566, 23));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IP\351\205\215\347\275\256\345\267\245\345\205\267", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("MainWindow", "\345\255\220\347\275\221\346\216\251\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\347\275\221    \345\205\263", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "  MAC", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\346\234\254\346\234\272 IP", Q_NULLPTR));
        pushButton_raly1->setText(QApplication::translate("MainWindow", "\347\273\247\347\224\265\345\231\2501", Q_NULLPTR));
        pushButton_raly2->setText(QApplication::translate("MainWindow", "\347\273\247\347\224\265\345\231\2502", Q_NULLPTR));
        pushButton_1->setText(QApplication::translate("MainWindow", "\345\206\231\345\205\245", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\350\257\273\345\217\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
