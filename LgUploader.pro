# -------------------------------------------------
# Project created by QtCreator 2010-02-04T13:32:53
# -------------------------------------------------
QT += network \
    sql \
    webkit \
    xml \
    xmlpatterns
unix:MOC_DIR = ./tmp
win32:MOC_DIR = tmp
unix:OBJECTS_DIR = ./tmp
win32:OBJECTS_DIR = tmp
unix:RCC_DIR = .resources
win32:RCC_DIR = resources
unix:UI_DIR = ./ui
win32:UI_DIR = ui
CONFIG += qsqlmysql

LIBS += d:/Proj/LG/SVN/LGUploader/lib/libdjvulibre.lib \
    d:/Proj/LG/SVN/LGUploader/lib/libchmfile.lib \
    d:/Proj/LG/SVN/LGUploader/lib/ChmLib.lib \
    d:/Proj/LG/SVN/LGUploader/lib/libpoppler.lib \
    d:/Proj/LG/SVN/LGUploader/lib/libpoppler.lib \
    d:/Proj/LG/SVN/LGUploader/lib/libpoppler-qt4.lib
INCLUDEPATH += include
RC_FILE = resources/icon.rc

# unix:LIBS += -L/usr/local/lib -lmath
# win32:LIBS += c:/mylibs/math.lib
TARGET = LgUploader
TEMPLATE = app
SOURCES += src/main.cpp \
    src/guSettDialog.cpp \
    src/guMainWindow.cpp \
    src/guFolderInspector.cpp \
    src/guBookUploader.cpp \
    src/isbnMethods.cpp \
    src/guLogger.cpp \
    ui/guAboutDialog.cpp \
    src/guBookTreeItem.cpp \
    src/guFindBookFilesDialog.cpp
HEADERS += src/guSettDialog.h \
    src/guMainWindow.h \
    src/guFolderInspector.h \
    src/dataStructures.h \
    src/guBookUploader.h \
    src/isbnMethods.h \
    src/guLogger.h \
    ui/guAboutDialog.h \
    src/guBookTreeItem.h \
    src/guFindBookFilesDialog.h
FORMS += ui/guSettDialog.ui \
    ui/guMainWindow.ui \
    ui/guAboutDialog.ui \
    ui/guFindBookFilesDialog.ui
RESOURCES += resources/res.qrc
