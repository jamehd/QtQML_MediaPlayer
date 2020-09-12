QT += quick multimedia core
CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    ../HandGestureCpp/ShareGesture.h \
    player.h \
    playlistmodel.h \
    translation.h \
    GestureListener.h

SOURCES += \
        ../HandGestureCpp/ShareGesture.cpp \
        main.cpp \
        player.cpp \
        playlistmodel.cpp \
        translation.cpp \
        GestureListener.cpp

RESOURCES += qml.qrc

unix {
    LIBS += -ltag
    DBUS_ADAPTORS += gesture.xml
} else {
    LIBS += -LD:/3thparty/taglib/lib/ -llibtag.dll
    INCLUDEPATH += D:/3thparty/taglib/include
    DEPENDPATH += D:/3thparty/taglib/include
}

TRANSLATIONS = translator/string_vn.ts translator/string_us.ts

DISTFILES += \
    gesture.xml

