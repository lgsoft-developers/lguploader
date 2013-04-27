#ifndef ISBNMETHODS_H
#define ISBNMETHODS_H
#include <QString>
#include <QStringList>
#include <QList>

class isbnMethods
{
public:
    isbnMethods();
    bool isbnOk(QString isbnToTest);
    QString genChkSum10(QString isbnToCheck);
    QString genChkSum13(QString isbnToCheck);
    QString cleanIsbn(QString dirtyIsbn);
    QString convertISBN(QString isbn);

    int getISBNType(QString isbn);
    void  findIsbns(QString text, QList<QString> &isbns);
};

#endif // ISBNMETHODS_H
