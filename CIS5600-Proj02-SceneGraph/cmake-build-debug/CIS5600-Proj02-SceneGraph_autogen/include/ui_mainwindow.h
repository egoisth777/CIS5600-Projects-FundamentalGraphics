/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>
#include "mygl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QWidget *centralWidget;
    MyGL *mygl;
    QTreeWidget *treeWidget;
    QDoubleSpinBox *txSpinBox;
    QDoubleSpinBox *tySpinBox;
    QDoubleSpinBox *rSpinBox;
    QLabel *txLabel;
    QLabel *tyLabel;
    QLabel *rLabel;
    QDoubleSpinBox *sxSpinBox;
    QLabel *sxLabel;
    QDoubleSpinBox *sySpinBox;
    QLabel *syLabel;
    QPushButton *geomSetButton;
    QPushButton *tNodeAddButton;
    QPushButton *rNodeAddButton;
    QPushButton *sNodeAddButton;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(921, 640);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        mygl = new MyGL(centralWidget);
        mygl->setObjectName(QString::fromUtf8("mygl"));
        mygl->setGeometry(QRect(11, 11, 618, 592));
        treeWidget = new QTreeWidget(centralWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(640, 10, 256, 381));
        txSpinBox = new QDoubleSpinBox(centralWidget);
        txSpinBox->setObjectName(QString::fromUtf8("txSpinBox"));
        txSpinBox->setGeometry(QRect(650, 430, 62, 22));
        txSpinBox->setSingleStep(0.500000000000000);
        tySpinBox = new QDoubleSpinBox(centralWidget);
        tySpinBox->setObjectName(QString::fromUtf8("tySpinBox"));
        tySpinBox->setGeometry(QRect(720, 430, 62, 22));
        tySpinBox->setSingleStep(0.500000000000000);
        rSpinBox = new QDoubleSpinBox(centralWidget);
        rSpinBox->setObjectName(QString::fromUtf8("rSpinBox"));
        rSpinBox->setGeometry(QRect(650, 480, 62, 22));
        rSpinBox->setSingleStep(0.500000000000000);
        txLabel = new QLabel(centralWidget);
        txLabel->setObjectName(QString::fromUtf8("txLabel"));
        txLabel->setGeometry(QRect(650, 410, 61, 16));
        tyLabel = new QLabel(centralWidget);
        tyLabel->setObjectName(QString::fromUtf8("tyLabel"));
        tyLabel->setGeometry(QRect(720, 410, 61, 16));
        rLabel = new QLabel(centralWidget);
        rLabel->setObjectName(QString::fromUtf8("rLabel"));
        rLabel->setGeometry(QRect(650, 460, 61, 16));
        sxSpinBox = new QDoubleSpinBox(centralWidget);
        sxSpinBox->setObjectName(QString::fromUtf8("sxSpinBox"));
        sxSpinBox->setGeometry(QRect(650, 530, 62, 22));
        sxSpinBox->setSingleStep(0.500000000000000);
        sxLabel = new QLabel(centralWidget);
        sxLabel->setObjectName(QString::fromUtf8("sxLabel"));
        sxLabel->setGeometry(QRect(650, 510, 61, 16));
        sySpinBox = new QDoubleSpinBox(centralWidget);
        sySpinBox->setObjectName(QString::fromUtf8("sySpinBox"));
        sySpinBox->setGeometry(QRect(720, 530, 62, 22));
        sySpinBox->setSingleStep(0.500000000000000);
        syLabel = new QLabel(centralWidget);
        syLabel->setObjectName(QString::fromUtf8("syLabel"));
        syLabel->setGeometry(QRect(720, 510, 61, 16));
        geomSetButton = new QPushButton(centralWidget);
        geomSetButton->setObjectName(QString::fromUtf8("geomSetButton"));
        geomSetButton->setGeometry(QRect(800, 580, 111, 21));
        tNodeAddButton = new QPushButton(centralWidget);
        tNodeAddButton->setObjectName(QString::fromUtf8("tNodeAddButton"));
        tNodeAddButton->setGeometry(QRect(800, 430, 111, 21));
        rNodeAddButton = new QPushButton(centralWidget);
        rNodeAddButton->setObjectName(QString::fromUtf8("rNodeAddButton"));
        rNodeAddButton->setGeometry(QRect(800, 480, 111, 21));
        sNodeAddButton = new QPushButton(centralWidget);
        sNodeAddButton->setObjectName(QString::fromUtf8("sNodeAddButton"));
        sNodeAddButton->setGeometry(QRect(800, 530, 111, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 921, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Scene Graph", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        txLabel->setText(QCoreApplication::translate("MainWindow", "Translate X", nullptr));
        tyLabel->setText(QCoreApplication::translate("MainWindow", "Translate Y", nullptr));
        rLabel->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        sxLabel->setText(QCoreApplication::translate("MainWindow", "Scale X", nullptr));
        syLabel->setText(QCoreApplication::translate("MainWindow", "Scale Y", nullptr));
        geomSetButton->setText(QCoreApplication::translate("MainWindow", "Set Geometry", nullptr));
        tNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Translate Node", nullptr));
        rNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Rotate Node", nullptr));
        sNodeAddButton->setText(QCoreApplication::translate("MainWindow", "Add Scale Node", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
