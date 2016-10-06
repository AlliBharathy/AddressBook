#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include <QWidget>
#include <QSqlTableModel>

class StudentView : public QWidget
{
    Q_OBJECT
public:
    explicit StudentView(QWidget *parent = 0);

    void createView(QSqlTableModel *model);


signals:

public slots:
};

#endif // STUDENTVIEW_H
