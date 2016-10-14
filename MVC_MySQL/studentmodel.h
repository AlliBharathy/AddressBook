#ifndef STUDENTMODEL_H
#define STUDENTMODEL_H
#include <QsqlTableModel>


class StudentModel
{
public:
    StudentModel();
    QSqlTableModel* getFromModel();
    virtual ~StudentModel(){}


};

#endif // STUDENTMODEL_H
