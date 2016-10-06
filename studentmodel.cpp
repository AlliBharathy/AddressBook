#include "studentmodel.h"
#include <QSqlTableModel>
#include <QDebug>

StudentModel::StudentModel()
{

}

QSqlTableModel *StudentModel::getFromModel()

{
    QSqlTableModel *mod = new QSqlTableModel();
    mod->setTable("student");
    mod->setEditStrategy(QSqlTableModel::OnFieldChange);
    mod->select();
    mod->setHeaderData(0, Qt::Horizontal, "Roll No.");
    mod->setHeaderData(1, Qt::Horizontal, "Name");
    qDebug() << "in GetFromModel()";
    return mod;

}





