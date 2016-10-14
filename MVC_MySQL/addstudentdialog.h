#ifndef ADDSTUDENTDIALOG_H
#define ADDSTUDENTDIALOG_H
#include <QDialog>
#include <QWidget>
#include "studentform.h"
#include "student.h"

/***********************************************************************
    Class: AddStudentDialog

    Author:

     Dialog presenting a form to add a new student.
***********************************************************************/


class addStudentDialog: public QDialog
{

    Q_OBJECT

public:
    addStudentDialog(Student &s, QWidget *parent=0, Qt::WindowFlags f=0);
public slots:
    void accept();
private:
    StudentForm *studentForm;
    Student &outStudent;

};

#endif
