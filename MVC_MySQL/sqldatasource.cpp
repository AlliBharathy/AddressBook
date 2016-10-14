/*
#include "sqlitedatasource.h"

#include <algorithm>
#include <sqlite3.h>
#include <string>
#include <stdexcept>
#include <vector>
#include "addressbookview.h"
#include "contact.h"
#include "errorinfo.h"
#include "sqliteutils.h"


//Non Member Utility Functions

*/


#include "sqldatasource.h"
#include <algorithm>
#include <string>
#include <stdexcept>
#include <vector>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include "studentsviewinterface.h"
#include "student.h"
#include "errordetail.h"
#include "mysqlutils.h"
#include <QDebug>
#include <iostream>
using namespace std;


SQLDatasource::SQLDatasource()
{
    database;
    createTable();
}

SQLDatasource::~SQLDatasource()
{
   qDebug() << "SQLDatasource destructor called";
}

 void SQLDatasource ::createTable()
 {



     QSqlQuery query("CREATE TABLE IF NOT EXISTS Student"
                     "(roll_num INTEGER PRIMARY KEY,"
                     "name text);");
     if(!query.isActive())
     {
         qDebug() << "Error in Table Creation";
     }

  /*  if (!query.isActive())
    {
    QMessageBox::warning(this, tr("Database Error"),
     query.lastError().text());
    }
*/

 }


void SQLDatasource::registerView(StudentsViewInterface *viewToRegister)
{
    if(viewToRegister && !isViewRegistered(viewToRegister))
    {
        qDebug() << " going to studList.push_back(viewToRegister)";
        studList.push_back(viewToRegister);
    }

}


bool SQLDatasource::isViewRegistered(StudentsViewInterface *viewToCheck)
{
    qDebug() << "in ViewRegistered";
    std::vector<StudentsViewInterface*>::const_iterator it;
    it = std::find(studList.begin(), studList.end(), viewToCheck);
    qDebug() << "in viewRegistered befor if";
  // cout << it;
    if(it == studList.end())
    {
        return false;
        qDebug() << "false from StudList";
    }
    else
    {
        return true;
        qDebug() << "true from studList";
    }
    qDebug() <<"after if ";
}


 ErrorDetail SQLDatasource::getStudent(Student::RollNum rollnum, Student& stud)
 {
     qDebug() << "from getStudent and rollnum is";
     qDebug() << (rollnum);
     Student::RollNum rnum;
     rnum=rollnum;
     qDebug() << "rnum is ";
     qDebug() << rnum;
    // QSqlTableModel model;

     //model.setTable("student");

     /*
      * QString query_string = "SELECT * FROM cars WHERE carID = "
+ QString::number(car_id);
      */
     QString query_string = "SELECT * FROM STUDENT WHERE ROLL_NUM = " + QString::number(rnum);
     // QSqlQuery query(query_string);
     qDebug() << "content of query_string";
     qDebug() << query_string;
     QSqlQuery query(query_string);
         //query.prepare("SELECT roll_num, Name from student WHERE roll_num  = ?");//,rnum );//+ rnum);
        // query.addBindValue(rnum);
         query.exec();
//     model.setFilter("student.roll_num = "+rnum);
  //   model.select();
    // qDebug() << "rowcount is ";
     //qDebug() << (model.rowCount());
    // QSqlRecord record = model.record(0);
     qDebug() <<" it works";
     //qDebug() << (record.value(0).toInt());
     //qDebug() << (record.value(1).toString());
     if(query.first())
     {
     qDebug() << (query.value(0));
     qDebug() << "captured content";
     stud.roll_Num = query.value(0).toInt();
     stud.Name = query.value(1).toString();
     qDebug() << (stud.Name);
     qDebug() << (stud.roll_Num);
     }
     /*fillStudentFromRow(record, stud);*/
     return ErrorDetail(ERR_OK,"OK");
 }



 ErrorDetail SQLDatasource::getAllStudents(Student::StudentRecordSet &srs)
{      Student::StudentRecordSet rows;
       Student temp;
      QSqlTableModel model;
      model.setTable("student");
      model.setSort(1,Qt::AscendingOrder);
      model.select();
        qDebug() << "in getAllSTudents";
        qDebug() << (model.rowCount());
      for (int i = 0; i < model.rowCount(); ++i) {
           // Student tempstud;
            QSqlRecord record = model.record(i);
     //         fillStudentFromRow(record, tempstud);
            temp.roll_Num = record.value(0).toInt();
            temp.Name = record.value(1).toString();

              rows.push_back(temp);
        }
        srs=rows;
        return ErrorDetail(ERR_OK,"OK");

}
/*
void SQLDatasource::fillStudentFromRow(QSqlRecord &rec, Student &studen)
{
    studen.rollNum = rec.value(0).toInt();
    studen.Name = rec.value(1).toString();
}
*/

 ErrorDetail  SQLDatasource::addStudent(const Student& stud)
 {
     qDebug() << "adding student in SQLDatasouce.cpp" ;
     QSqlTableModel model;
     model.setTable("student");
     model.setEditStrategy(QSqlTableModel::OnFieldChange);
     model.select();
     //model.insertRecord();
     /*qDebug() << model.rowCount();
     qDebug() << stud.roll_Num;
     qDebug() << stud.Name;*/
     QSqlRecord record=model.record();
     /*record.value(0)=stud.roll_Num;
     record.value(1)=stud.Name;*/
     record.setValue("roll_num",QVariant(stud.roll_Num));
     record.setValue("name",QVariant(stud.Name));
     /*
      * QSqlRecord rec = record();
    rec.setGenerated("id", true);
    rec.setValue("name", QVariant(name));
    rec.setValue("surname", QVariant(surname));
    rec.setValue("birthday", QVariant(birthday));
      */
     qDebug() << record;
     qDebug() << record.indexOf("Name");
     qDebug() << record.indexOf("roll_num");
     qDebug() << record.value(0);
     qDebug() << record.value(1);
     if(model.insertRecord(model.rowCount()-1,record))
     qDebug() << "inserted";
     notifyViews();

      return ErrorDetail(ERR_OK, "OK");
 }

 void SQLDatasource::notifyViews()
 {
     std::vector<StudentsViewInterface*>::iterator it;

     for(it = studList.begin(); it != studList.end(); it++)
     {
         (*it)->updateView();
     }
}


 ErrorDetail SQLDatasource::updateStudent(Student::RollNum rollnum, const Student& stud)
{
     /*qDebug() << " in sqldataSource updateStudent";
     qDebug() << (rollnum);
     qDebug() << (stud.Name);*/
    //  notifyViews();
   /*  QSqlTableModel model;
     model.setTable("student");
     model.setEditStrategy(QSqlTableModel::OnFieldChange);
     //QString  filer = "stud.Roll_num = " + QString::number(rollnum);
     //qDebug() << filer;
     // model.setFilter("student.roll_num = "+rnum);
   //  model.setFilter(filer);
     model.select();*/
     /*qDebug() << "row count on filter";
     qDebug() << (model.rowCount());*/
    // QString updateQuery_string =  "update student SET "
      //                       "NAME='"+stud.Name + "' WHERE roll_num =" +QString::number(rollnum);
     QString query_string = "SELECT * FROM STUDENT WHERE ROLL_NUM = " + QString::number(rollnum);
     //QSqlQuery query(query_string);
     qDebug() << "content of query_string";
     qDebug() << query_string;
     //QSqlQuery query(query_string);
     /*
      * "UPDATE Contacts SET "
                         "firstname=?, lastname=?,"
                         "phonenum=?, address=?,"
                         "email=? WHERE id=?;";
      */
   //  QString query_string = "UPDATE STUDENT SET "
    // "NAME = ? WHERE ROLL_NUM =" + QString::number(rollnum);
  /*   QSqlQuery query(query_string);
           //query.prepare("SELECT roll_num, Name from student WHERE roll_num  = ?");//,rnum );//+ rnum);
          // query.addBindValue(rnum);
     query.exec();
     qDebug() << (query.size());
     while(query.next())
     {
         qDebug()<< "in while query.next";
     qDebug() << (query.value(0));
     qDebug() << (query.value(1));
     qDebug() << (stud.Name);
     }*/ //no need to select all the records
   //  query.value(1)=stud.Name;
     QString updateQuery_string =  "update student SET "
                              "NAME='"+stud.Name + "' WHERE roll_num =" +QString::number(rollnum);
    QSqlQuery updateQuery(updateQuery_string);
    updateQuery.exec();


    // QSqlRecord record =model.record();
   //  qDebug() << (record.value("Name"));
    // query.bindValue(1,stud.Name);
    //record.setValue("Name",stud.Name);
    //QVariant val = stud.Name;
 //model.setData(1,val);
//    QModelIndex index = model.index(1)
 //    qDebug() << "after";
     //  qDebug() << (record.value("Name"));
       /*
        * query.prepare("UPDATE clients SET "
"ClientName=:name, ClientCity=:city, ClientAddress=:address, ClientMol=:mol, "
"ClientEik=:eik, ClientVat=:vat, ClientTel=:tel, ClientMail=:mail WHERE id=:id");
query.bindValue(":name", "Z");
        */
   //  model.setRecord(1,record);
    /*query.prepare("UPDATE clients SET "
                   "Name = :name where Roll_num = :rnum");
     query.bindValue(":name",stud.Name);
     query.bindValue(":rnum",rollnum);
     query.exec();
     if (query.first())
         qDebug() << "done";
     model.database().commit();
     qDebug() << (query.value(1));
*/
     notifyViews();
     return ErrorDetail(ERR_OK, "OK");
}

 ErrorDetail SQLDatasource::deleteStudent(Student::RollNum rollNum)
 {
     QString deleteString = "DELETE FROM Student WHERE ROLL_NUM = " + QString::number(rollNum);
     QSqlQuery delQuery(deleteString);
     delQuery.exec();
     notifyViews();

     return ErrorDetail(ERR_OK, "OK");
 }
