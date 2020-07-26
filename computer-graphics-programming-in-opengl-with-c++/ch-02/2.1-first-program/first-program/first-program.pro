TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

win32 {
    INCLUDEPATH += "C:\Users\danil\Documents\Programacao\libs\include"
    LIBS += -lopengl32 -lglew32 -lglfw3
}

unix {
    LIBS += -lGL -lGLEW -lglfw
}


DISTFILES += \
    shaders/fragShader.frag \
    shaders/triangleVertShader.vert \
    shaders/vertShader.vert
