QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = build/test
TEMPLATE = app

# Warnings if any feature of Qt has been marked as deprecated
# DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
  main.cpp \
  TwoVector.cpp \
  GenericBall.cpp

HEADERS += \
  TwoVector.h \
  GenericBall.h

#FORMS += \
#  ControlWindow.ui \
#  DisplayWindow.ui
