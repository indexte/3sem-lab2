/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QPushButton *btnCreateANote;
    QTextEdit *mainText;
    QListWidget *listNotes;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        btnCreateANote = new QPushButton(centralWidget);
        btnCreateANote->setObjectName(QString::fromUtf8("btnCreateANote"));
        btnCreateANote->setMinimumSize(QSize(250, 30));
        btnCreateANote->setMaximumSize(QSize(250, 30));
        btnCreateANote->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid rgb(211, 215, 207);\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: #E6E6E6;\n"
"	border: 1px solid rgb(211, 215, 207);	\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #006EFF;\n"
"	color: white;\n"
"	border: 1px solid rgb(211, 215, 207);\n"
"	border-radius: 2px;\n"
"}\n"
""));

        gridLayout->addWidget(btnCreateANote, 1, 0, 1, 1);

        mainText = new QTextEdit(centralWidget);
        mainText->setObjectName(QString::fromUtf8("mainText"));
        mainText->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"	border: 1px solid lightgray;\n"
"	border-radius: 2px;\n"
"}"));

        gridLayout->addWidget(mainText, 2, 1, 1, 1);

        listNotes = new QListWidget(centralWidget);
        listNotes->setObjectName(QString::fromUtf8("listNotes"));
        listNotes->setMaximumSize(QSize(250, 16777215));
        listNotes->setStyleSheet(QString::fromUtf8("QListWidget{\n"
"	border: none;\n"
"	border: 1px solid lightgray;\n"
"	border-radius: 2px;\n"
"}\n"
"\n"
"QListWidget::item:selected{\n"
"	background-color: #006EFF;\n"
"}\n"
"\n"
"QListWidget::item:hover:!selected{\n"
"	background-color: #E6E6E6;\n"
"}"));

        gridLayout->addWidget(listNotes, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 26));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Notes", nullptr));
        btnCreateANote->setText(QCoreApplication::translate("MainWindow", "New note", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
