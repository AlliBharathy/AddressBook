#include <QList>

#include "studentcontroller.h"
#include "student.h"
#include "studentlist.h"
#include "QDebug"

#include <string>


Studentlist::Studentlist(StudentModelInterface &model, QWidget *parent) :
    QListWidget(parent), dataSource(model)

{
    qDebug() << "in Studentlist Constructor";

    setSelectionMode(QAbstractItemView::SingleSelection);

    connect(this, SIGNAL(itemSelectionChanged()), this, SLOT(dispatchListItemStudentRollnum()));

    populateList();

    setCurrentRow(0, QItemSelectionModel::SelectCurrent);
}


void Studentlist::populateList(Student::RollNum selected)
{

    //Get all the students from the data store
    Student::StudentRecordSet allStudents;
    dataSource.getAllStudents(allStudents);

    Student::StudentRecordSet::const_iterator it;

    std::string listTitle = "";
    QListWidgetItem *newItem;
    QListWidgetItem *selectedItem;

    //Create new list items for each student
    for(it = allStudents.begin();it != allStudents.end();it++)
    {
        listTitle = it->Name.toStdString();
        newItem = new QListWidgetItem(tr(listTitle.c_str()), this);
        newItem->setData(Qt::UserRole, it->roll_Num);

        if(selected && (it->roll_Num == selected))
        {
            selectedItem = newItem;
            setCurrentItem(selectedItem, QItemSelectionModel::SelectCurrent);
        }

    }

}

void Studentlist::refreshStudentList()
{
    Student::RollNum selectionToRetain = getSelectedRollNum();

    clear();
    populateList(selectionToRetain);

}

void Studentlist::dispatchListItemStudentRollnum()
{
    Student::RollNum selectedItemId = getSelectedRollNum();
    qDebug() << "in dispatchListItemStudentRollnum()";
    qDebug() << (selectedItemId);

    emit studentSelected(selectedItemId);
}

Student::RollNum Studentlist::getSelectedRollNum()
{
    Student::RollNum selectedRollNum = Student::INVALID_ID;

    QListWidgetItem *selectedStudent = currentItem();

    if(selectedStudent)
    {
        //Take the first element of the list because we only allow single selection
        selectedRollNum = selectedStudent->data(Qt::UserRole).toUInt();
    }

    return selectedRollNum;
}

