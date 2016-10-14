#ifndef STUDENTFORM_H
#define STUDENTFORM_H
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

/***********************************************************************
    Class: StudentForm

    Author:

    Qt FormLayout subclass that contains all the labels & line edits
    for displaying / entering a contact.

    Encapsulate the actual form fields themselves so they can easily
    all be instantiated without repeating boilerplate code.

    As this is a FormLayout subclass it is simply added to it's parent
    class like any other Qt Layout

    The actual line edit objects for the student info are public so
    as to be accessible.  Think of this as a kind of struct that just
    groups all the Student form elements in one place
***********************************************************************/



class StudentForm : public QFormLayout
{
    Q_OBJECT

public:
    StudentForm(QWidget *parent=0);
    void clear();

    QLineEdit *nameField;
    QLineEdit *rollNumField;

};

#endif // STUDENTFORM_H
