#include "student.h"
#include "addstudentdialog.h"
#include <QTwidgets/QDialog>
#include <QTwidgets/QWidget>
#include <QTwidgets/QHBoxLayout>
#include <QTwidgets/QVBoxLayout>
#include <QTwidgets/QPushButton>

addStudentDialog::addStudentDialog(Student &s, QWidget *parent, Qt::WindowFlags f)    :
               QDialog(parent, f), studentForm(new StudentForm()), outStudent(s)
   {
       QVBoxLayout *mainContainer = new QVBoxLayout();
       mainContainer->addLayout(studentForm);

       QHBoxLayout *buttonContainer = new QHBoxLayout();
       QPushButton *addButton = new QPushButton("Add");
       QPushButton *cancelButton = new QPushButton("Cancel");

       buttonContainer->addWidget(addButton);
       buttonContainer->addWidget(cancelButton);
       mainContainer->addLayout(buttonContainer);

       connect(addButton, SIGNAL(clicked()), this, SLOT(accept()));
       connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

       setLayout(mainContainer);
       setWindowTitle("New Student");
   }

   void addStudentDialog::accept()
   {
       outStudent.roll_Num = studentForm->rollNumField->text().toInt();
       outStudent.Name = studentForm->nameField->text();
     /*  outStudent.address = StudentForm->addressField->text().toStdString();
       outStudent.phoneNumber = StudentForm->phoneNumberField->text().toStdString();
       outStudent.email = StudentForm->emailField->text().toStdString();
   */
       QDialog::accept();
   }


