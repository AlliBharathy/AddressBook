#ifndef STUDENTSMODELINTERFACE_H
#define STUDENTSMODELINTERFACE_H

#include "student.h"
#include "errordetail.h"
#include "studentsviewinterface.h"

/***********************************************************************
    Class: StudentModelInterface
{

    Author:

    Interface class for the data storage back end of the Student
    Provides services for basic retrieval and updating of the contact
    list.

    This our Model class in an MVC architecture.  As such
    it provides an interface to register/unregister/notify observers.

    Different types of backend storage solutions (flat file, SQL,
    , web based API etc...) for the address book must implement this
    interface.
***********************************************************************/




class StudentModelInterface
{
public:
    virtual void registerView(StudentsViewInterface *viewToRegister)=0;
    virtual ErrorDetail getAllStudents(Student::StudentRecordSet &srs) = 0;
    virtual ErrorDetail getStudent(Student::RollNum rollnum, Student& stud)=0;
    virtual ErrorDetail addStudent(const Student& stud) = 0;
    virtual ErrorDetail updateStudent(Student::RollNum rollnum, const Student& stud) = 0;
    virtual ErrorDetail deleteStudent(Student::RollNum) = 0;
};




#endif // STUDENTSMODELINTERFACE_H

