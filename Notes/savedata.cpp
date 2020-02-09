#include "savedata.h"

#define FOLDER "/SNNotes"
#define NOTES_FILE "/notes_data.svk"

SaveData::SaveData()
{
    userName = QDir::homePath();
    QDir().mkdir(userName + FOLDER);
}

void SaveData::Save(QMap<QString, QString> *listNotes)
{
    //number of the elements
    int count = listNotes->count();

    //create file
    QFile fileNotes(userName + FOLDER + NOTES_FILE);

    //open file
    if (fileNotes.open(QIODevice::WriteOnly)){

        //open the binary file
        QDataStream binFile(&fileNotes);

        //write number of the elements
        binFile << count;

        QByteArray keyArr;
        QByteArray lavueArr;

        //write note data to the binary file
        for (int i = 0; i < count; i++){
            keyArr = listNotes->keys().at(i).toUtf8();
            lavueArr = listNotes->values().at(i).toUtf8();
            binFile << qCompress(keyArr) << qCompress(lavueArr);
        }



    }

    fileNotes.close();

}
