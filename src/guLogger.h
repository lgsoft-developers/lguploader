#ifndef GULOGGER_H
#define GULOGGER_H

#include <QObject>
#include <QFile>
#include <QString>
#include <QTextStream>

class guLogger : public QObject
{
    Q_OBJECT
public:
    guLogger(QString logFilePath);
    ~guLogger();

private:
    QFile logFile;
    QTextStream logOut;
public slots:
    void log(QString logString, int logType = 0);

};

#endif // GULOGGER_H
