#include "studentcontroller.h"
#include <QApplication>
#include <QDebug>
#include <mysqlutils.h>
#include "sqldatasource.h"
#include <QSql>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLDatasource DB;
    StudentController stud_contlr(DB);
    stud_contlr.start();
    return a.exec();
}
