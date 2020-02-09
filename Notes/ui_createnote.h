/********************************************************************************
** Form generated from reading UI file 'createnote.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATENOTE_H
#define UI_CREATENOTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CreateNote
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btnCreate;

    void setupUi(QDialog *CreateNote)
    {
        if (CreateNote->objectName().isEmpty())
            CreateNote->setObjectName(QString::fromUtf8("CreateNote"));
        CreateNote->resize(283, 148);
        CreateNote->setMinimumSize(QSize(283, 148));
        CreateNote->setMaximumSize(QSize(283, 148));
        CreateNote->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(CreateNote);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 281, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(CreateNote);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 40, 261, 27));
        lineEdit->setMaxLength(24);
        btnCreate = new QPushButton(CreateNote);
        btnCreate->setObjectName(QString::fromUtf8("btnCreate"));
        btnCreate->setGeometry(QRect(10, 90, 261, 31));
        QFont font1;
        font1.setPointSize(10);
        btnCreate->setFont(font1);
        btnCreate->setCursor(QCursor(Qt::PointingHandCursor));
        btnCreate->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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

        retranslateUi(CreateNote);

        QMetaObject::connectSlotsByName(CreateNote);
    } // setupUi

    void retranslateUi(QDialog *CreateNote)
    {
        CreateNote->setWindowTitle(QCoreApplication::translate("CreateNote", "New note", nullptr));
        label->setText(QCoreApplication::translate("CreateNote", "Enter note name", nullptr));
        btnCreate->setText(QCoreApplication::translate("CreateNote", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateNote: public Ui_CreateNote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATENOTE_H
