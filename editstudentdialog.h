#ifndef EDITSTUDENTDIALOG_H
#define EDITSTUDENTDIALOG_H
#include <QTwidgets/QDialog>
#include <QTwidgets/QWidget>
#include "studentform.h"
#include "student.h"

/***********************************************************************
    Class: editStudentDialog

    Author:

    Qt Dialog presenting a form to edit an existing student
***********************************************************************/




class editStudentDialog : public QDialog
{
        Q_OBJECT
        public:
            editStudentDialog(Student &c, QWidget *parent=0, Qt::WindowFlags f=0);

        public slots:
            void accept();

        private:
            void fillForm();

            StudentForm *studentForm;
            Student &studentToEdit;

};

#endif // EDITSTUDENTDIALOG_H
