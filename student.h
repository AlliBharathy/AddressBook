#ifndef STUDENT_H
#define STUDENT_H

/************************************************************
    Class: Student

    Author:

    Data structure to hold a single address book student's
    info.
************************************************************/

//#include <string>
#include <vector>
#include <QString>

class Student
{
public:
    typedef std::vector<Student> StudentRecordSet;
    typedef unsigned int RollNum;
    static const RollNum INVALID_ID = 0;

    RollNum roll_Num;
    QString Name;
    Student():roll_Num(0),Name() { }
    bool isValidToAdd() const;
  //  bool isEmpty() const;

};

#endif // STUDENT_H
