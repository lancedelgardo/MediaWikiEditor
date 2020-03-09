#-------------------------------------------------
#
# Project created by QtCreator 2020-03-06T08:48:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WikiEdit
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        MainWindow.cpp \
    Widgets/InputWidget.cpp \
    Controller/WidgetsController.cpp \
    Widgets/AddTextFieldWidget.cpp \
    Dialogs/AddObjectDialog.cpp \
    Widgets/AddBoolWidget.cpp \
    Widgets/AddTableWidget.cpp \
    Widgets/TableWidget.cpp \
    Data/TableData.cpp \
    Dialogs/EditTableDialog.cpp \
    Data/TableRowData.cpp \
    Widgets/LayoutItem.cpp \
    Widgets/PushButton.cpp \
    Widgets/TextEdit.cpp \
    Widgets/CheckBox.cpp \
    Controller/OutputGenerator.cpp

HEADERS += \
        MainWindow.h \
    Widgets/InputWidget.h \
    Controller/WidgetsController.h \
    Widgets/AddTextFieldWidget.h \
    Dialogs/AddObjectDialog.h \
    Widgets/AddBoolWidget.h \
    Widgets/AddTableWidget.h \
    Widgets/TableWidget.h \
    Data/TableData.h \
    Dialogs/EditTableDialog.h \
    Data/TableRowData.h \
    Widgets/LayoutItem.h \
    Widgets/PushButton.h \
    Widgets/TextEdit.h \
    Widgets/CheckBox.h \
    Controller/OutputGenerator.h

FORMS += \
        MainWindow.ui
