#-------------------------------------------------
#
# Project created by QtCreator 2014-06-11T10:32:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GestionRnC
TEMPLATE = app


SOURCES += main.cpp\
        inicio.cpp \
    socio.cpp \
    deuda.cpp \
    evento.cpp \
    dialog_newpartner.cpp \
    dialogdepartmentboss.cpp \
    dialogsearchpartner.cpp \
    cuenta.cpp

HEADERS  += inicio.h \
    socio.h \
    deuda.h \
    evento.h \
    dialog_newpartner.h \
    dialogdepartmentboss.h \
    dialogsearchpartner.h \
    cuenta.h

FORMS    += inicio.ui \
    dialog_newpartner.ui \
    dialogdepartmentboss.ui \
    dialogsearchpartner.ui
