QT += core
QT += gui
QT += sql

QT += widgets
CONFIG += c++11

TARGET = MVC_Student_mysql
#CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    studentcontroller.cpp \
    studentmodel.cpp \
    studentview.cpp \
    student.cpp \
    studentgui.cpp \
    studentlist.cpp \
    studentform.cpp \
    mysqlutils.cpp \
    sqldatasource.cpp \
    qterrordialog.cpp \
    studentdetailview.cpp \
    addstudentdialog.cpp \
    editstudentdialog.cpp

HEADERS += \
    studentcontroller.h \
    studentmodel.h \
    studentview.h \
    studentsviewinterface.h \
    studentsmodelinterface.h \
    errordetail.h \
    student.h \
    studentgui.h \
    studentlist.h \
    studentform.h \
    mysqlutils.h \
    sqldatasource.h \
    qterrordialog.h \
    studentdetailview.h \
    addstudentdialog.h \
    editstudentdialog.h
