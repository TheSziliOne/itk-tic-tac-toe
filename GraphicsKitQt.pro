TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        application.cpp \
        button.cpp \
        cell.cpp \
        list.cpp \
        main.cpp \
        graphics/graphics.cpp \
        szamlalo.cpp \
        widgets.cpp


INCLUDEPATH += $$PWD/.
DEPENDPATH += $$PWD/.

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2.dll

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/./ -llibSDL2_ttf.dll
else:unix: LIBS += -L$$PWD/./ -llibSDL2_ttf.dll


INCLUDEPATH += $$PWD/SDL2
DEPENDPATH += $$PWD/SDL2

HEADERS += \
    application.hpp \
    button.hpp \
    cell.hpp \
    list.hpp \
    szamlalo.hpp \
    widgets.hpp
