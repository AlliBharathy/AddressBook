#ifndef QTERRORDIALOG_H
#define QTERRORDIALOG_H

#include <QTwidgets/QMessageBox>

/***********************************************************************
    Class: QtErrorDialog

    Author:

    Simple error dialog that will display an error message with an OK
    button.
***********************************************************************/


class QtErrorDialog : public QMessageBox
{
     Q_OBJECT
public:
    QtErrorDialog(std::string errMsg, QWidget *parent=0);
};

#endif // QTERRORDIALOG_H
