#ifndef SQLDATASOURCE_H
#define SQLDATASOURCE_H


#include "sqldatasource.h"
#include <algorithm>
#include <QSql>
#include <string>
#include <stdexcept>
#include <vector>
#include "studentsmodelinterface.h"
#include "studentsviewinterface.h"
#include "student.h"
#include "errordetail.h"
#include "mysqlutils.h"


/***********************************************************************
    Class: SQLDataSource

    Author:

    A MYSQL driven backend for the Student application. Implements the
    StudentModelInterface.
***********************************************************************/


class SQLDatasource :public StudentModelInterface
{
public:
    SQLDatasource();
    virtual void registerView(StudentsViewInterface *viewToRegister);
    virtual ErrorDetail getAllStudents(Student::StudentRecordSet &srs);
    virtual ErrorDetail getStudent(Student::RollNum rollnum, Student& stud);
    virtual ErrorDetail addStudent(const Student& stud);
    virtual void notifyViews();
    virtual ErrorDetail updateStudent(Student::RollNum rollnum, const Student& stud);
    virtual ErrorDetail deleteStudent(Student::RollNum rollNum);

    ~SQLDatasource();





private:
    void createTable();

   void fillStudentFromRow(QSqlRecord  *rec, Student &stud);
    bool isViewRegistered(StudentsViewInterface *viewToCheck);

   std::string dbFilename;
   MySQLDBHandle database;
   std::vector<StudentsViewInterface*> studList;


   

    /*
        void createTable();
        void fillContactFromRow(sqlite3_stmt *s, Contact &c);

        bool isViewRegistered(AddressBookView *viewToCheck);

        std::string dbFilename;
        SQLiteDBHandle database;
        std::vector<AddressBookView*> observerList;


*/
};

#endif // SQLDATASOURCE_H
