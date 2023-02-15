QT       += core gui
LIBS += -lopengl32
greaterThan(QT_MAJOR_VERSION, 4): QT += openglwidgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cpp \
    model/facade.cpp \
    model/filereader.cpp \
    view/glview.cpp \
    main.cpp \
    view/mainwindow.cpp \
    view/settings.cpp

HEADERS += \
    controller/controller.h \
    model/facade.h \
    model/filereader.h \
    view/glview.h \
    view/mainwindow.h \
    view/settings.h

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

ICON = pic.png
