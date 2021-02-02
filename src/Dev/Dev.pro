QT += widgets

TEMPLATE = lib
win32:CONFIG(release, debug|release): DLLDESTDIR = ../../ElectricalCircuitBuildingSystem/release
else:win32:CONFIG(debug, debug|release): DLLDESTDIR = ../../ElectricalCircuitBuildingSystem/debug
else:unix: DLLDESTDIR = ../../ElectricalCircuitBuildingSystem

DEFINES += DEV_LIBRARY

CONFIG += c++1z

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ArrayCreatorByImage.cpp

HEADERS += \
    ArrayCreatorByImage.h \
    Dev_global.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

FORMS += \
    UI/ArrayCreatorByImage.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../GeneralAPI/release/ -lGeneralAPI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../GeneralAPI/debug/ -lGeneralAPI
else:unix: LIBS += -L$$OUT_PWD/../GeneralAPI/ -lGeneralAPI

INCLUDEPATH += $$PWD/../GeneralAPI
DEPENDPATH += $$PWD/../GeneralAPI
