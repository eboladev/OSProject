#ifndef CHECKINDIALOG_H
#define CHECKINDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "employeebaseinfochoosedialog.h"
namespace Ui {
class CheckInDialog;
}

class CheckInDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CheckInDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int index = -1);
    ~CheckInDialog();
    
private slots:
    void on_pushButton_save_clicked();
    void on_pushButton_cancel_clicked();
    void on_toolButton_clicked();
    void doubleClickRecord(QString);

private:
    void initView();
    Ui::CheckInDialog *ui;
    QSqlRelationalTableModel *model;
    EmployeeBaseInfoChooseDialog *dialog;
    bool isAdd;
    int index;
};

#endif // CHECKINDIALOG_H
