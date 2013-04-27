#include "guLogger.h"

guLogger::guLogger(QString logFilePath)
{
    if (QFile::exists(logFilePath));
    QFile::remove(logFilePath);
    logFile.setFileName(logFilePath);
         if (!logFile.open(QIODevice::WriteOnly | QIODevice::Text))
             return;

         logOut.setDevice(&logFile);
         logOut << "The magic number is: " << 49 << "\n";
         //logFile.flush();
         logOut.flush();
}
guLogger::~guLogger()
{
    logFile.close();
}

void guLogger::log(QString logString, int logType)
{
    logOut << logString;
    logOut.flush();
}
