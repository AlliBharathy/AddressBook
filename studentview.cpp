#include "studentview.h"
#include <QWidget>
#include <QSqlTableModel>
#include <QTableView>


StudentView::StudentView(QWidget *parent) : QWidget(parent)
{

}
void StudentView::createView(QSqlTableModel *model)
{
    QTableView *view = new QTableView;
    view->setModel(model);
    view->setWindowTitle("Student details");
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    view->setSelectionMode(QTableView::SingleSelection);
  /*  view->setVisible(true);*/
    view->show();
}

