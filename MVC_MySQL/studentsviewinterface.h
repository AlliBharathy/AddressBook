#ifndef STUDENTSVIEWINTERFACE_H
#define STUDENTSVIEWINTERFACE_H

/***********************************************************************
    Class: StudensViewInterface

    Author: Phil Grohe

    Interface for the application's views to implement.

    This class is the View in our MVC architecture.  It is the Observer
    to StudentModel's Subject.
***********************************************************************/

class StudentsViewInterface
{
    public:

        virtual void showUI()=0;

        //Model has changed, update info in UI
        virtual void updateView() = 0;
        virtual ~StudentsViewInterface() {};

};

#endif // STUDENTSVIEWINTERFACE_H
