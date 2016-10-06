#ifndef STUDENTGUI_H
#define STUDENTGUI_H


#include "studentcontroller.h"
#include "studentsmodelinterface.h"
#include "studentsviewinterface.h"
#include "studentlist.h"
#include "studentdetailview.h"

#include <QMainWindow>
#include <QPushButton>


/***********************************************************************
    Class: StudentGui

    Author:

    Top level application window.  Instantiates sub widgets and connects
    their signals and slots.
***********************************************************************/




class StudentGui : public QMainWindow, public StudentsViewInterface
{
    Q_OBJECT
public:
     StudentGui(StudentController &controller,StudentModelInterface &model,
                QWidget *parent = 0, Qt::WindowFlags flags=0);

  //  StudentGui(StudentController &controller,
    //            QWidget *parent = 0, Qt::WindowFlags flags=0);


     //from studentsviewinterface
     virtual void updateView();
     virtual void showUI();
     virtual ~StudentGui();

signals:
    void pullDataFromModel();


private slots:
    void addStudent();
    void deleteStudent();
    void editStudent();
private:
    void createWidgets();

    Studentlist *list;
    StudentDetailView *detailView;

    QPushButton *newContactButton;
    QPushButton *editContactButton;
    QPushButton *deleteContactButton;


    StudentController& appController;
    StudentModelInterface& dataSource;






};

#endif // STUDENTGUI_H
