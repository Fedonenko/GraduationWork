QT += gui widgets

TEMPLATE = lib
win32:CONFIG(release, debug|release): DLLDESTDIR = ../../ElectricalCircuitBuildingSystem/release
else:win32:CONFIG(debug, debug|release): DLLDESTDIR = ../../ElectricalCircuitBuildingSystem/debug
else:unix: DLLDESTDIR = ../../ElectricalCircuitBuildingSystem

DEFINES += CHART_LIBRARY

CONFIG += c++1z

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChartGraphicsScene.cpp \
    EComponentGItem.cpp \
    chartwidget.cpp

HEADERS += \
    ChartGraphicsScene.h \
    Chart_global.h \
    EComponentGItem.h \
    chartwidget.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
 DESDIR = E:\Diploma

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GeneralAPI/release/ -lGeneralAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GeneralAPI/debug/ -lGeneralAPI
else:unix: LIBS += -L$$OUT_PWD/../GeneralAPI/ -lGeneralAPI

INCLUDEPATH += $$PWD/../GeneralAPI
DEPENDPATH += $$PWD/../GeneralAPI

FORMS += \
    ChartWidget.ui
