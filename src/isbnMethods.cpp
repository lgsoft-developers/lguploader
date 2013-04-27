#include "isbnMethods.h"
#include <QDebug>

isbnMethods::isbnMethods()
{
}
bool isbnMethods::isbnOk(QString isbnToTest)
{
    QString checkSum;


    /* Clean up the ISBN */
    //isbnToTest = cleanIsbn(isbnToTest);

    /* If the size is equal to 10 do it */
    if (isbnToTest.length() == 10) {

            checkSum = genChkSum10(isbnToTest);
            qDebug() << "isbnToTest" << isbnToTest << "checksum " << checkSum << "and last" << isbnToTest.at(9) ;

            if (checkSum == "X" && isbnToTest.at(9) == 'X')
                    return true;
            if (checkSum  == isbnToTest.at(9) ) //- '0'
                    return true;

    }


    /* If the size is equal to 13 do it */
    if (isbnToTest.length() == 13) {
            if((isbnToTest.left(3) != "978") && (isbnToTest.left(3) != "979"))
                return false;

            checkSum = genChkSum13(isbnToTest);
            qDebug() << "isbnToTest" << isbnToTest << "checksum " << checkSum << "and last" << isbnToTest.at(12) ;

            if (checkSum == isbnToTest.at(12) )//- '0'
                    return true;

    }
    /* If everything fails => fail */
    return false;
}

QString isbnMethods::genChkSum10(QString isbnToCheck)
{
    /*The multiplyer */
    int multy = 10;

    int sum = 0;

    int checkSum = 0;

    for (int i = 0; i < 9; i++) {
            /* Because atio thinks it is a pointer to a array it will shoot off into
             memory. So if you want to convert a single char into a int don't use
             atoi. */
            int atoiIsGay = QString(isbnToCheck.at(i)).toInt();
            sum = sum + (atoiIsGay * multy);
            multy--;
    }

    checkSum = (11 - (sum % 11));

    if (checkSum == 10)
            return "X";

    if (checkSum == 11)
            return "0";

    return QString::number(checkSum);

}

QString isbnMethods::genChkSum13(QString isbnToCheck)
{
    /*The multiplyer */
    int multy = 10;

    int sumodd = 0;
    int sumeve = 0;

    int checkSum = 0;

    for (int i = 0; i <= 11; i=i+2) {
            /* Same as above */
        int atoiIsGay = QString(isbnToCheck.at(i)).toInt();
            int atoiIsGay2 = QString(isbnToCheck.at(i+1)).toInt();

            sumodd = sumodd + atoiIsGay;
            sumeve = sumeve + atoiIsGay2;
    }

    checkSum = (sumodd + (sumeve*3)) % multy;

    if (checkSum != 0)
            checkSum = multy - checkSum;

    return QString::number(checkSum);
}

QString isbnMethods::cleanIsbn(QString dirtyIsbn)
{
    QString cleanIsbn = dirtyIsbn.remove(" ");
    cleanIsbn = cleanIsbn.remove("-");
    return cleanIsbn;
}

QString isbnMethods::convertISBN(QString isbn)
{
    /* Clean up the ISBN */
    isbn = cleanIsbn(isbn);

    if (isbn.size() == 10 || isbn.size() == 13) {
            if (isbn.size() == 13) {
                    if (isbn.left(3) == "978") {
                            if (isbnOk(isbn)) {
                                    QString isbn2 = isbn.mid(3, 9);
                                    QString isbn10;
                                    if (genChkSum10(isbn2) == "X") {
                                            isbn10 = isbn2.append("X");
                                    } else {
                                            isbn10 = isbn2.append(genChkSum10(isbn2));
                                    }
                                    return isbn10;
                            } else {
                                    return "";
                            }
                    } else {
                            return ""; //"Only ISBN-13 numbers begining with 978 can be converted to ISBN-10."
                    }
            }

            if (isbn.size() == 10) {
                    if (isbnOk(isbn)) {
                            QString isbn2 = "978" + isbn.left(9);
                            QString isbn13 = isbn2.append(genChkSum13(isbn2));
                            return isbn13;
                    } else {
                            return "";
                    }
            }

    } else {
            return ""; //"The number you entered is not a valid ISBN";
    }

    return "";
}
/////////////////////////////
int isbnMethods::getISBNType(QString isbn)
{
    QString isbnTemp = cleanIsbn(isbn);
    return isbnTemp.count(); //return 10 or 13
};
void isbnMethods::findIsbns(QString text , QList<QString> &isbns)
{
    text = text.remove(" ");
    text = text.remove("-");
    text = text.remove("ISBN10");
    text = text.remove("ISBN13");
    //qDebug() << text;
    // "ISBN(?:-13)?:?\\x20*(?=.{17}$)97(?:8|9)([ -])\\d{1,5}\\1\\d{1,7}\\1\\d{1,6}\\1\\d$" ISBN-13: 978-1-4028-9462-6
    QRegExp rx("(\\d{9,12}[\\d|X])",Qt::CaseSensitive);
    QStringList list;
    int pos = 0;

    while ((pos = rx.indexIn(text, pos)) != -1) {
        //newEbook.i
        QString strToTest = rx.cap(1);
        if (isbnOk(strToTest))
        {
            qDebug() << "isbnOk";
             if(!isbns.contains(rx.cap(1)))
             {
                 isbns << rx.cap(1);
                 qDebug() <<"finded ISBN " << rx.cap(1);
             }
        }

        //qDebug() << rx.cap(1);
        pos += rx.matchedLength();
    }
}
