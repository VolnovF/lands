QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        fixedpart.cpp \
        fraction.cpp \
        holder.cpp \
        land.cpp \
        main.cpp \
        part.cpp \
        shape.cpp \
        shapes/circle.cpp \
        shapes/rectangle.cpp \
        shapes/square.cpp \
        shapes/triangle.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    fixedpart.h \
    fraction.h \
    holder.h \
    land.h \
    part.h \
    shape.h \
    shapes/circle.h \
    shapes/rectangle.h \
    shapes/square.h \
    shapes/triangle.h
