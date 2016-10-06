#include "mysqlutils.h"
#include <QDebug>
#include <QSql>
//#include <QSqlDriver>
#include <QSqlDatabase>

/*
 * QSqlDatabase QSqlDatabase::addDatabase(const QString &type, const QString &connectionName)
{
    QSqlDatabase db(type);
    QSqlDatabasePrivate::addDatabase(db, connectionName);
    return db;
}
*/

MySQLDBHandle::MySQLDBHandle()
{
    //QSqlDatabase db;
    db= QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("mp3db");
    db.setUserName("user1");
    db.setPassword("password");
    if (!db.open())
    {
            qDebug() << "Database error occurred";
           // return false;
    }
    qDebug() << "Database connected";
}


MySQLDBHandle::~MySQLDBHandle()
{
    db.close();
};
