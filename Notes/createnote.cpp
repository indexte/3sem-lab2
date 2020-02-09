#include "createnote.h"
#include "ui_createnote.h"

#define MAX_NOTE_LEN 24

QString CreateNote::getName() const
{
    return name;
}

void CreateNote::ShowMessage(QString str)
{
    QMessageBox msg;
    msg.setText(str);
    msg.exec();
}

CreateNote::CreateNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateNote)
{
    ui->setupUi(this);
}

CreateNote::~CreateNote()
{
    delete ui;
}

void CreateNote::on_btnCreate_clicked()
{
    //check name
    if (ui->lineEdit->text().isEmpty())
        ShowMessage("Error. Please enter the name");
    else {
        name = ui->lineEdit->text();
        close();
    }
}
