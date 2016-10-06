#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include <QListWidget>

//#include "addressbookmodel.h"
#include "studentsmodelinterface.h"

//#include "contact.h"
#include "student.h"

/***********************************************************************
    Class: QtStudentList

    Author:

    List widget that displays the full contact book. Selecting a widget

    When a student is selected will emit the contactSelected signal
    with the id of the contact.  The widget where the contact details
    will be displayed should have this signal connected to one if it's
    slots.
***********************************************************************/


/*
If a student is added or deleted from the addressbook, what happens?
    List must be refreshed to reflect the state of the student list
        List interface should provide a way to update the list from a new recordset

*/


class Studentlist : public QListWidget
{
        Q_OBJECT
public:
    Studentlist(StudentModelInterface& model, QWidget *parent=0);
    Student::RollNum getSelectedRollNum();

public slots:
    void refreshStudentList();

signals:
   void studentSelected(Student::RollNum  selectedrollnum);
    /*void contactSelected(Student::RollNum selectedId);
  */


private slots:
    void dispatchListItemStudentRollnum();

private:
        void populateList(Student::RollNum selected=0);
        StudentModelInterface& dataSource;
};

#endif // STUDENTLIST_H
