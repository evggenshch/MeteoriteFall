#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T13:30:31
#
#-------------------------------------------------

QT       += core gui
QT       += opengl
#QT       += lGL
LIBS += -lGLU
LIBS += -lX11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Meteorite
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    wopengl.cpp \
    model.cpp \
    aerodynamics.cpp \
    theormech.cpp \
    meteorite.cpp \
    point.cpp \
    planet.cpp \
    atm_layer.cpp \
    atmosphere.cpp \
    gl_font.cpp \
    atm_table_edit_dialog.cpp

HEADERS  += mainwindow.h \
    wopengl.h \
    model.h \
    aerodynamics.h \
    theormech.h \
    meteorite.h \
    point.h \
    planet.h \
    atm_layer.h \
    atmosphere.h \
    gl_font.h \
    atm_table_edit_dialog.h

FORMS    += mainwindow.ui \
    atm_table_edit_dialog.ui
