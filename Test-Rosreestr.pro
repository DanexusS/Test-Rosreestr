QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    VesselClasses/abstractvessel.cpp \
    decimallineedit.cpp \
    main.cpp \
    mainwidget.cpp \
    VesselClasses/CustomVesselClasses/opendeckvessel.cpp \
    VesselClasses/CustomVesselClasses/regularvessel.cpp \
    VesselClasses/CustomVesselClasses/technicalfleetvessel.cpp \
    VesselClasses/CustomVesselClasses/unusualdesignvessel.cpp \
    VesselClasses/CustomVesselClasses/unusualpurposevessel.cpp \
    vesselformlayout.cpp

HEADERS += \
    VesselClasses/abstractvessel.h \
    decimallineedit.h \
    mainwidget.h \
    VesselClasses/CustomVesselClasses/opendeckvessel.h \
    VesselClasses/CustomVesselClasses/regularvessel.h \
    VesselClasses/CustomVesselClasses/technicalfleetvessel.h \
    VesselClasses/CustomVesselClasses/unusualdesignvessel.h \
    VesselClasses/CustomVesselClasses/unusualpurposevessel.h \
    vesselformlayout.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
