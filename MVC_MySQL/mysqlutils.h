#ifndef MYSQLUTILS_H
#define MYSQLUTILS_H
#include <QSqlDatabase>
//#include "qsql_oci.h"
//#include <string>
//#include "sqlite3.h"
//#include <QSql>

class MySQLDBHandle
{

public:
    explicit MySQLDBHandle();
    ~MySQLDBHandle();
private:
    QSqlDatabase db;
};

#endif


// MYSQLUTILS_H

/*
 *
 * class SQLiteDBHandle
{
    public:
        explicit SQLiteDBHandle(std::string filename, int flags=SQLITE_OPEN_READWRITE);
        ~SQLiteDBHandle();
        sqlite3 *get();
    private:
        SQLiteDBHandle(const SQLiteDBHandle &);
        SQLiteDBHandle &operator=(const SQLiteDBHandle &);
        sqlite3 *db;

};

*/
