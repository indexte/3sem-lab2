#include "mainwindow.h"
#include "ui_mainwindow.h"

#define NOTE_HEIGHT 40


//if the user right-clicked on a note
void MainWindow::ProvideContextMenu(const QPoint &pos)
{
    QPoint item = ui->listNotes->mapToGlobal(pos);

    QMenu menu;
    menu.addAction("Delete");

    if (ui->listNotes->count() != 0){

        QAction *rightClick = menu.exec(item);
        if (rightClick && rightClick->text().contains("Delete")){
            QMessageBox::StandardButton msg = QMessageBox::question(this, "Delete",
                                                                    "Are you sure you want to delete '" + ui->listNotes->currentItem()->text() + "'?",
                                                                    QMessageBox::Yes | QMessageBox::No);

            if (msg == QMessageBox::Yes){
                mapListNotes.remove(ui->listNotes->currentItem()->text());
                delete ui->listNotes->currentItem();

                if (ui->listNotes->count() == 0){
                    ui->mainText->setText("");
                    mapListNotes.clear();

                    sData->Save(&mapListNotes);
                }
            }

        }


    }

}
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->listNotes->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listNotes, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(ProvideContextMenu(QPoint)));

    sData = new SaveData();
    lData = new LoadData();

    //load notes from the file
    if (lData->Load()){
        mapListNotes = lData->getListNotes();
        int count = mapListNotes.count();

        QString noteName = "";
        int badNote = 0; //if note is empty
        for (int i = 0; i < count; i++){
            noteName = mapListNotes.keys().at(i);
            if (!noteName.isEmpty()) //check if the note is empty
            {
                ui->listNotes->addItem(noteName);
            }
            else
                badNote++;
        }

        //note height
        for (int i = 0; i < count - badNote; i++){
            ui->listNotes->item(i)->setSizeHint(QSize(0, NOTE_HEIGHT));

            ui->listNotes->item(i)->setIcon(QIcon(NOTE_ICON));
        }
        //highlight the note
        ui->listNotes->setCurrentRow(0);

        //fill note
        ui->mainText->setText(mapListNotes.value(ui->listNotes->currentItem()->text()));

    }

}



MainWindow::~MainWindow()
{
    //save before exit
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(ui->listNotes->currentItem()->text(), ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    delete ui;
}



void MainWindow::on_btnCreateANote_clicked()
{
    //save note before create the new one
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(ui->listNotes->currentItem()->text(), ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    //call CreateNote window and get the note name
    crNote = new CreateNote();
    crNote->exec();

    QString noteName = crNote->getName();
    if (noteName.isEmpty())
        return;

    ui->listNotes->addItem(noteName); //add to QListWidget


    int lastAddedItem = ui->listNotes->count() - 1; //index of last element
    ui->listNotes->item(lastAddedItem)->setSizeHint(QSize(0, NOTE_HEIGHT)); //resize the element
    ui->listNotes->setCurrentRow(lastAddedItem); //highlight the element
    ui->listNotes->item(lastAddedItem)->setIcon(QIcon(NOTE_ICON));
    ui->mainText->setFocus();

    mapListNotes.insert(noteName, ""); //add note name to the QMap
    ui->mainText->setText("");

    lastNote = noteName;

    delete crNote;
}

void MainWindow::on_listNotes_itemClicked(QListWidgetItem *item)
{
    //save the current before select next note
    if (ui->listNotes->count() != 0){
        mapListNotes.insert(lastNote, ui->mainText->toHtml());
        sData->Save(&mapListNotes);
    }

    ui->mainText->setFocus();
    ui->mainText->setText(mapListNotes.value(item->text())); //Если это старая заметка, то загружаем текст из QMap

    lastNote = item->text();
}
