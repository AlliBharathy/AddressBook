#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include "studentform.h"




void StudentForm::clear()
{
    nameField->setText("");
    rollNumField->setText("");

}


StudentForm::StudentForm(QWidget *parent) :
        QFormLayout(parent), nameField(new QLineEdit()),
        rollNumField (new QLineEdit())
{
    addRow("Roll Number", rollNumField);
    addRow("Name", nameField);

}
