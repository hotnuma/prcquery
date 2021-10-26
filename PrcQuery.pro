TEMPLATE = app
TARGET = prcquery
CONFIG = c++11
DEFINES =
INCLUDEPATH =

HEADERS += \
    PrcEntry.h \
    PrcList.h \
    PrcQuery.h \

SOURCES += \
    0Temp.cpp \
    main.cpp \
    PrcEntry.cpp \
    PrcList.cpp \
    PrcQuery.cpp \

DISTFILES += \
    install.sh \
    meson.build \
    Readme.txt \


