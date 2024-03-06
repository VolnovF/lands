QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        holder.cpp \
        land.cpp \
        landchamber.cpp \
        main.cpp \
        shapes/circle.cpp \
        shapes/rectangle.cpp \
        shapes/square.cpp \
        shapes/triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    holder.h \
    land.h \
    landchamber.h \
    shapes/circle.h \
    shapes/rectangle.h \
    shapes/square.h \
    shapes/triangle.h
