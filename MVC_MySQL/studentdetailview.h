#ifndef STUDENTDETAILVIEW_H
#define STUDENTDETAILVIEW_H


#include <QTwidgets/QGroupBox>
#include <QTwidgets/QLabel>
#include <QTwidgets/QLineEdit>
#include "student.h"
#include "studentsmodelinterface.h"
#include "studentform.h"

/***********************************************************************
Class: QtContactDetailView

Author: Phil Grohe

Qt widget for displaying all the fields of a Student.

Slot displayStudent(Studentt::ROLL_NUM rollnum) receives the student info to
be displayed
***********************************************************************/


class StudentDetailView :public QGroupBox
{
    Q_OBJECT
public:
    StudentDetailView(StudentModelInterface &model, QWidget *parent=0);
    void clear();


private slots:
        void displayStudent(Student::RollNum roll_num);


private:
        StudentModelInterface &dataSource;
        StudentForm* studForm;

};

#endif // STUDENTDETAILVIEW_H
