TEMPLATE = app
TARGET = prcquery
CONFIG = c++11
DEFINES =
INCLUDEPATH =

HEADERS += \
    Global.h \
    PrcQuery.h \
    PrcEntry.h \
    PrcList.h \

SOURCES += \
    0Temp.cpp \
    PrcQuery.cpp \
    main.cpp \
    PrcEntry.cpp \
    PrcList.cpp \

DISTFILES += \
    install.sh \
    meson.build \


