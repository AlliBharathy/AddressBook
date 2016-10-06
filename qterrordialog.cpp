#include "qterrordialog.h"
#include <QTwidgets/QVBoxLayout>
#include <QTwidgets/QHBoxLayout>
#include <QTwidgets/QPushButton>
#include <QTwidgets/QLabel>


QtErrorDialog::QtErrorDialog(std::string errMsg, QWidget *parent) :
                        QMessageBox(QMessageBox::Warning, "An error occured...",
                        errMsg.c_str(), QMessageBox::Ok, parent) {}
