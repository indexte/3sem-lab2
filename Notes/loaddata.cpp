#include "loaddata.h"

#define FOLDER "/SNNotes"
#define NOTES_FILE "/notes_data.svk"

QMap<QString, QString> LoadData::getListNotes() const
{
    return listNotes;
}

LoadData::LoadData()
{
    //Узнаем имя пользователя
    userName = QDir::homePath();

}

bool LoadData::Load()
{

    //search file with saved notes
    QFile fileNotes(userName + FOLDER + NOTES_FILE);

    if (!fileNotes.open(QIODevice::ReadOnly)){
        qDebug() << "File '" << fileNotes.fileName() << "' is not found!";
        fileNotes.close();
        return false;
    }

    //if the file exists then open it
    QDataStream binFile(&fileNotes);

    //number of notes
    int count = 0;

    binFile >> count;

    //check notes
    if (count == 0){
        fileNotes.close();
        return false;
    }

    QString tNote = ""; //temporary variable for storing note name
    QString tText = ""; //temporary variable for storing note text

    QByteArray arrNote;
    QByteArray arrText;

    //read notes and text from the file, then write to a temporary container
    for (int i = 0; i < count; i++){
        binFile >> arrNote;
        binFile >> arrText;

        tNote = qUncompress(arrNote);
        tText = qUncompress(arrText);

        listNotes.insert(tNote, tText);
    }

    fileNotes.close();
    return true;

}
