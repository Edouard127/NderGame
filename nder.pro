TEMPLATE = app
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    NderBotBeta.cpp
HEADERS += \
QT += core \
    SDL_test_crc32.h \
    SDL_test_font.h \
    SDL_test_fuzzer.h \
    SDL_test_harness.h \
    SDL_test_images.h \
    SDL_test_log.h \
    SDL_test_md5.h \
    SDL_test_memory.h \
    SDL_test_random.h \
    SDL_thread.h \
    SDL_timer.h \
    SDL_touch.h \
    SDL_types.h \
    SDL_version.h \
    SDL_video.h \
    SDL_vulkan.h \
    graphic.h
CONFIG += console
QT += widgets
INCLUDEPATH += include
LIBS += -L$$PWD/lib -lmingw32 -mwindows -lSDL2main -lSDL2

CONFIG(debug, debug|release){
DESTDIR = $$PWD/debug
}
CONFIG(release, debug|release){
DESTDIR = $$PWD/release
}
win32{
WINDOWS_PWD = $$replace(PWD, /, \\)
WINDOWS_DESTDIR = $$replace(DESTDIR, /, \\)
QMAKE_POST_LINK += xcopy /Y $$WINDOWS_PWD\bin\SDL2.dll $$WINDOWS_PDW\
}

unix|win32: LIBS += -L$$PWD/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix|win32: LIBS += -L$$PWD/lib/ -llibSDL2_mixer.dll

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

unix|win32: LIBS += -L$$PWD/lib/ -lSDL2_mixer

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include




unix|win32: LIBS += -L$$PWD/debug/texte/lib/ -llibSDL2_ttf.dll

INCLUDEPATH += $$PWD/debug/texte/include
DEPENDPATH += $$PWD/debug/texte/include

unix|win32: LIBS += -L$$PWD/debug/texte/lib/ -lSDL2_ttf

INCLUDEPATH += $$PWD/debug/texte/include
DEPENDPATH += $$PWD/debug/texte/include

unix|win32: LIBS += -L$$PWD/debug/SDL_image/lib/ -llibSDL2_image.dll

INCLUDEPATH += $$PWD/debug/SDL_image/include
DEPENDPATH += $$PWD/debug/SDL_image/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/debug/SDL_image/lib/ -lSDL2_image
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/debug/SDL_image/lib/ -lSDL2_image
else:unix: LIBS += -L$$PWD/debug/SDL_image/lib/ -lSDL2_image

INCLUDEPATH += $$PWD/debug/SDL_image/include
DEPENDPATH += $$PWD/debug/SDL_image/include

unix|win32: LIBS += -L$$PWD/debug/SDL_Net/lib/ -llibSDL2_net.dll

INCLUDEPATH += $$PWD/debug/SDL_Net/include
DEPENDPATH += $$PWD/debug/SDL_Net/include

unix|win32: LIBS += -L$$PWD/debug/SDL_Net/lib/ -lSDL2_net

INCLUDEPATH += $$PWD/debug/SDL_Net/include
DEPENDPATH += $$PWD/debug/SDL_Net/include
