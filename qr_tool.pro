QT += widgets gui printsupport 

CONFIG  -= flat

debug {
    TARGET      = QRToold
    DESTDIR     = ./bin/debug
    OBJECTS_DIR = ./tmp/debug
    MOC_DIR     = ./tmp/debug
    LIBS += ./libqrencode\bin\libqrencoded.lib
}
release {
    TARGET      = QRTool
    DESTDIR     = ./bin/release
    OBJECTS_DIR = ./tmp/release
    MOC_DIR     = ./tmp/release
    LIBS += ./libqrencode\bin\libqrencode.lib
}

INCLUDEPATH += . \
               ./libqrencode\inc

HEADERS        =    src/stdafx.h \
                    src/KMainWindow.h \
                    src/KConfigFileManager.h \
                    src/KPrintPreview.h \
                    src/KListWidget.h \
                
                
SOURCES         =   src/main.cpp \
                    src/KMainWindow.cpp \
                    src/KConfigFileManager.cpp \
                    src/KPrintPreview.cpp \
                    src/KListWidget.cpp \

