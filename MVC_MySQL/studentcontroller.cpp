#include "studentcontroller.h"
#include "studentgui.h"
#include "studentsviewinterface.h"
#include "studentsmodelinterface.h"
#include "errordetail.h"
#include "student.h"


#include <qDebug>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlDriver>



StudentController::StudentController(StudentModelInterface &d) : dataStore(d)

{
    qDebug() << "in StudentController constructor";
   //

     frontEnd = new StudentGui(*this, dataStore);
    qDebug() << "front end done well";
    dataStore.registerView(frontEnd);
    qDebug() << "in StudentController constructor after registerview";

}
StudentController::~StudentController()
{
    delete frontEnd;
}

void StudentController::start()
{
    frontEnd->showUI();
}
/*
 bool StudentController :: getconnection()
 {
     QSqlDatabase db;
     db= QSqlDatabase::addDatabase("QMYSQL");
     db.setDatabaseName("mp3db");
     db.setUserName("user1");
     db.setPassword("password");
     if (!db.open())
     {
             qDebug() << "Database error occurred";
             return false;
     }
     else
     {
         qDebug() << "Yyyesss  connected";

     }

     return true;
 }
*/

ErrorDetail StudentController::submitContact(const Student &stud)
{

    if(!stud.isValidToAdd())
    {
        return ErrorDetail(ERR_STUDENT_NOT_VALID,
                        "Invalid Contact. Make sure all required fields are filled.");
    }

    return dataStore.addStudent(stud);

}


ErrorDetail StudentController::editContact(const Student::RollNum roll_num, const Student &c)
{
    qDebug() << "in studentController editContact";
    if(!c.isValidToAdd())
    {
        return ErrorDetail(ERR_STUDENT_NOT_VALID,
                "Invalid Contact. Make sure all required fields are filled.");
    }
    qDebug() << "valid to add";
    qDebug() << (c.Name);
    return dataStore.updateStudent(roll_num, c);

}


ErrorDetail StudentController::deleteContact(const Student::RollNum rollNum)
{
    return dataStore.deleteStudent(rollNum);
}

/*
 void StudentController::start()
 {
     if(getconnection())
     {
         QSqlTableModel* model = new QSqlTableModel;
       model =  studModel.getFromModel();
        sview.createView( model);
     }
 }
*/
