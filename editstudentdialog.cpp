#include "editstudentdialog.h"
#include <QDialog>
#include <QWidget>
#include "studentform.h"
#include "student.h"
#include <QTwidgets/QPushButton>
#include <QTwidgets/QVBoxLayout>
#include <QTwidgets/QHBoxLayout>

/***********************************************************************
    Class: editStudentDialog

    Author:

    Qt Dialog presenting a form to edit an existing student
***********************************************************************/



editStudentDialog::editStudentDialog(Student &s,
                                       QWidget *parent,
                                       Qt::WindowFlags f) :
                                       QDialog(parent, f),
                                       studentForm(new StudentForm()),
                                       studentToEdit(s)
{

    QVBoxLayout *mainContainer = new QVBoxLayout();
    mainContainer->addLayout(studentForm);
     studentForm->rollNumField->setReadOnly(true);
     studentForm->nameField->setCursorPosition(2);



    QHBoxLayout *buttonContainer = new QHBoxLayout();
    QPushButton *okButton = new QPushButton("OK");
    QPushButton *cancelButton = new QPushButton("Cancel");
    buttonContainer->addWidget(okButton);
    buttonContainer->addWidget(cancelButton);
    mainContainer->addLayout(buttonContainer);

    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    fillForm();
    setLayout(mainContainer);
    setWindowTitle("Edit Student");

}

 void editStudentDialog::fillForm()
{
    studentForm->rollNumField->setText(QString::number(studentToEdit.roll_Num));
    studentForm->nameField->setText(studentToEdit.Name);
   /* contactForm->addressField->setText(contactToEdit.address.c_str());
    contactForm->phoneNumberField->setText(contactToEdit.phoneNumber.c_str());
    contactForm->emailField->setText(contactToEdit.email.c_str());*/

}



void editStudentDialog::accept()
{
    studentToEdit.roll_Num = studentForm->rollNumField->text().toInt();
    studentToEdit.Name = studentForm->nameField->text();
  /*  outStudent.address = StudentForm->addressField->text().toStdString();
    outStudent.phoneNumber = StudentForm->phoneNumberField->text().toStdString();
    outStudent.email = StudentForm->emailField->text().toStdString();
*/
    QDialog::accept();
}
