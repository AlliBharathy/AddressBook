#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFrame>
#include <QDebug>

#include "studentsviewinterface.h"
#include "studentcontroller.h"
#include "studentsmodelinterface.h"
#include "studentgui.h"
#include "addstudentdialog.h"
#include "studentlist.h"
//#include "qtcontactdetailview.h"
#include "editstudentdialog.h"
#include "errordetail.h"
#include "student.h"
#include "studentgui.h"
#include "qterrordialog.h"

/*
QtAddressBookGUI::QtAddressBookGUI(AddressBookController &controller, AddressBookModel &model,
    QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags),
    appController(controller), dataSource(model)

*/

StudentGui::StudentGui(StudentController&  controller, StudentModelInterface &model,
      QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags),
    appController(controller), dataSource(model)
{

    createWidgets();
    setMinimumSize(440,280);
}

/*
StudentGui::StudentGui(StudentController&  controller,
      QWidget *parent, Qt::WindowFlags flags) : QMainWindow(parent, flags),
    appController(controller)// dataSource(model)
{
    createWidgets();
    setMinimumSize(640,480);
}

*/

StudentGui::~StudentGui()
{

}

void StudentGui::updateView()
{
    emit pullDataFromModel();
}





void StudentGui::createWidgets()
{

    qDebug() << "in createWidgets";
  // checl  detailView = new QtContactDetailView(dataSource);
    detailView = new StudentDetailView(dataSource);

    list = new Studentlist(dataSource);
    list->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    newContactButton = new QPushButton("New Contact");
    newContactButton->setDefault(true);
    newContactButton->setAutoDefault(true);

    editContactButton = new QPushButton("Edit");
    editContactButton->setDefault(false);
    editContactButton->setAutoDefault(true);

    qDebug() << "New and Edit done";

    deleteContactButton = new QPushButton("Delete");
    deleteContactButton->setDefault(false);
    deleteContactButton->setAutoDefault(true);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(newContactButton);
    buttonLayout->addWidget(editContactButton);
    buttonLayout->addWidget(deleteContactButton);

    QVBoxLayout *rightSideLayout = new QVBoxLayout();
    qDebug() << "before addWidget(detailView)  line 80";
    rightSideLayout->addWidget(detailView);
    rightSideLayout->addLayout(buttonLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(list);
    mainLayout->addLayout(rightSideLayout);
    qDebug() << "after QHBOxLayout";
/*  void studentSelected(Student::RollNum  selectedrollnum);
    //Connect student list to the detail form
    connect(list,
            SIGNAL(contactSelected(Contact::ContactId)),
            detailView,
            SLOT(displayContact(Contact::ContactId)));*/

    connect(list,
            SIGNAL(studentSelected(Student::RollNum)),
            detailView,
            SLOT(displayStudent(Student::RollNum)));



    connect(newContactButton, SIGNAL(clicked()),
            this, SLOT(addStudent()));

     connect(deleteContactButton, SIGNAL(clicked()),
            this, SLOT(deleteStudent()));

   connect(editContactButton, SIGNAL(clicked()),
            this, SLOT(editStudent()));

    //tell the sub-widgets to refresh their data from
    //
    //Will be emitted when the view is notified by
    //the model that the data has changed
    connect(this, SIGNAL(pullDataFromModel()), list,
            SLOT(refreshStudentList()));

    QFrame *mainWidget = new QFrame();
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);

    //Needed to get the detail view form to display
    //the initial selection at startup.
    //When the list object is first created the signals / slots
    //arent yet connected so the initial selection isn't shown
    //This manual call will cause it to update

    list->refreshStudentList();


}
/*
 * void QtAddressBookGUI::addContact()
{
    Contact newContact;
    QtAddContactDialog *addDialog = new QtAddContactDialog(newContact, this);
    QtErrorDialog *errDialog = new QtErrorDialog("", this);

    while(addDialog->exec())
    {
        ErrorInfo e = appController.submitContact(newContact);

        if(e.code == ERR_OK)
        {
            break;
        }

        //display error dialog
        errDialog->setText(e.msg.c_str());
        errDialog->exec();

    }

    //Delete the dialog objects
    //Qt only deletes them when the parent is deleted
    //If I don't delete them manually here, new ones will be made
    //every time this function is called and only deleted when the
    //program is exited.
    delete addDialog;
    delete errDialog;
}
 *
 */
 void StudentGui:: addStudent()
 {
     //qDebug() << "addStudent activated";
     Student newStudent;
     addStudentDialog *addDialog = new addStudentDialog(newStudent, this);
     QtErrorDialog *errDialog = new QtErrorDialog("", this);

     while(addDialog->exec())
     {
         ErrorDetail e = appController.submitContact(newStudent);\
         if(e.code == ERR_OK)
         {
             break;
         }

         //display error dialog
         errDialog->setText(e.msg.c_str());
         errDialog->exec();

     }

     //Delete the dialog objects
     //Qt only deletes them when the parent is deleted
     //If I don't delete them manually here, new ones will be made
     //every time this function is called and only deleted when the
     //program is exited.
     delete addDialog;
     delete errDialog;
 }


 void StudentGui::editStudent()
 {
      qDebug() << "editStudent activated";
      Student::RollNum rollNumToEdit = list->getSelectedRollNum();
      Student editingStudent;
      ErrorDetail getStudentErrorStatus = dataSource.getStudent(rollNumToEdit, editingStudent);
        qDebug() << (editingStudent.Name);
      QtErrorDialog *errDialog = new QtErrorDialog("", this);
      qDebug() <<"returned from dataSource.getStudent";
      if(getStudentErrorStatus.code != ERR_OK)
      {
          qDebug() << "no ERR_OK";
          //The id of the Contact user wants to edit doesn't exist
          //Should never happen since they are selecting it from a list
          //of existing id
          //display error dialog
          errDialog->setText(getStudentErrorStatus.msg.c_str());
          errDialog->exec();

          //Qt only automagically deletes child objects when parent is destroyed
          //If I don't delete this here more and more dialogs will build up everytime
          //this function is called, only being destroyed when the parent window
          //(i.e. the application) is terminated.
          delete errDialog;
          return;
      }
      editStudentDialog *editDialog = new editStudentDialog(editingStudent, this);

      while(editDialog->exec())
      {
          ErrorDetail editErrorStatus = appController.editContact(rollNumToEdit, editingStudent);

          if(editErrorStatus.code == ERR_OK)
          {
              qDebug() << "editErrorStatus is ERR_OK it seems";
              break;
          }

          //display error dialog
          errDialog->setText(editErrorStatus.msg.c_str());
          errDialog->exec();
      }

      //see comment above about manually deleting dialogs after each run
      delete errDialog;
      delete editDialog;

 }

/*
 *void QtAddressBookGUI::deleteContact()
{
    Contact::ContactId idToDelete = list->getSelectedContactId();

    bool firstRow  = list->currentRow() == 0;
    bool onlyRowLeft = list->count() == 1;

    if(!onlyRowLeft)
    {
        if(firstRow)
        {
            list->setCurrentRow(list->currentRow()+1,QItemSelectionModel::SelectCurrent);
        }
        else
        {
            //It is NOT the only row left AND it is not the first row.
            //So in this case, selection moves to the previous row.
            list->setCurrentRow(list->currentRow()-1,QItemSelectionModel::SelectCurrent);
        }
    }

    ErrorInfo deleteErrorStatus = appController.deleteContact(idToDelete);
    if(deleteErrorStatus.code != ERR_OK)
    {
        //display error dialog
        QtErrorDialog *errDialog = new QtErrorDialog(deleteErrorStatus.msg, this);
        errDialog->exec();
        delete errDialog;
        return;
    }
}


 */
 void StudentGui::deleteStudent()
     {
      qDebug() << " remove Student activated";
      Student::RollNum rollNumToDelete = list->getSelectedRollNum();

      bool firstRow  = list->currentRow() == 0;
      bool onlyRowLeft = list->count() == 1;

      if(!onlyRowLeft)
      {
          if(firstRow)
          {
              list->setCurrentRow(list->currentRow()+1,QItemSelectionModel::SelectCurrent);
          }
          else
          {
              //It is NOT the only row left AND it is not the first row.
              //So in this case, selection moves to the previous row.
              list->setCurrentRow(list->currentRow()-1,QItemSelectionModel::SelectCurrent);
          }
      }
      ErrorDetail deleteErrorStatus = appController.deleteContact(rollNumToDelete);
      if(deleteErrorStatus.code != ERR_OK)
      {
          //display error dialog
          QtErrorDialog *errDialog = new QtErrorDialog(deleteErrorStatus.msg, this);
          errDialog->exec();
          delete errDialog;
          return;
      }

 }

 void StudentGui::showUI()
 {

      QMainWindow::show();
 }
