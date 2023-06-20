QT       += core gui
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog_change.cpp \
    dialog_change2.cpp \
    dialog_tongji.cpp \
    main.cpp \
    mainwindow.cpp \
    management.cpp \
    student.cpp

HEADERS += \
    dialog_change.h \
    dialog_change2.h \
    dialog_tongji.h \
    mainwindow.h \
    management.h \
    student.h

FORMS += \
    dialog_change.ui \
    dialog_change2.ui \
    dialog_tongji.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
