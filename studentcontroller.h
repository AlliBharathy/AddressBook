#ifndef STUDENTCONTROLLER_H
#define STUDENTCONTROLLER_H
#include "studentsmodelinterface.h"
#include "studentsviewinterface.h"
#include "errordetail.h"
#include "student.h"


class StudentController
{
public:

    //Interface to UI module
    ErrorDetail submitContact(const Student &stud);
    ErrorDetail deleteContact(const Student::RollNum rollNum);
    ErrorDetail editContact(const Student::RollNum id, const Student &stud);

    //Stores reference to StudentsModelinterface  abstract base class
    //allowing for different kinds of back end data storage
    //provided it implements the StudentModel interface

    explicit StudentController(StudentModelInterface &d);
    ~StudentController();
   // bool getconnection();
    void start();
private:
    StudentModelInterface &dataStore;
    StudentsViewInterface *frontEnd;

};

#endif // STUDENTCONTROLLER_H
