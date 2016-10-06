
#include "studentdetailview.h"
#include "studentform.h"
#include "qterrordialog.h"
#include "errordetail.h"
#include <QDebug>
//#include <QString>

#include <string>
#include <QTwidgets/QLineEdit>
#include <QTwidgets/QLabel>
#include <QTwidgets/QGroupBox>



StudentDetailView::StudentDetailView(StudentModelInterface &model,
                                     QWidget *parent):
                                     QGroupBox("student Details", parent),
                                     dataSource(model),
                                     studForm(new StudentForm())
{

    qDebug() << "instudentdetailview constructor";
    studForm->nameField->setReadOnly(true);
    studForm->rollNumField->setReadOnly(true);
    setLayout(studForm);
    setFlat(false);

}

/*
 *
 * void QtContactDetailView::displayContact(Contact::ContactId id)
{
    Contact c;

    ErrorInfo getContactErrorStatus = dataSource.getContact(id, c);

    if(getContactErrorStatus.code != ERR_OK)
    {
        //could not fetch the contact
        //simply clear the fields
        clear();
        return;
    }
    else
    {

        contactForm->firstNameField->setText(c.firstName.c_str());
        contactForm->lastNameField->setText(c.lastName.c_str());
        contactForm->addressField->setText(c.address.c_str());
        contactForm->phoneNumberField->setText(c.phoneNumber.c_str());
        contactForm->emailField->setText(c.email.c_str());
    }
}

 * */


void StudentDetailView::displayStudent(Student::RollNum roll_num)
{
    qDebug() << (roll_num);
  qDebug() << " in displayStudent of studentdetailview";
    Student student;
    ErrorDetail getStudentErrorStatus = dataSource.getStudent(roll_num,student);
    qDebug() << (roll_num);
  //  qDebug << (student.roll_Num);
  //  qDebug() << (getStudentErrorStatus);
    if(getStudentErrorStatus.code != ERR_OK)
    {

        //could not fetch the student
        //simply clear the fields
        clear();
        qDebug() << "not ERR_Ok";
        return;
    }
    else
    {
       // studForm->nameField->(student.Name);
        studForm->nameField->setText(student.Name);
        studForm->rollNumField->setText(QString::number(student.roll_Num));
        qDebug() << (student.Name);
        qDebug() << (student.roll_Num);
        qDebug() << "else condition met";

    }
}




 void StudentDetailView::clear()
 {
     qDebug() << "in studentdetailview clear()";
     studForm->clear();
 }
