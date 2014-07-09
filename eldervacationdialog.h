#ifndef ELDERVACATIONDIALOG_H
#define ELDERVACATIONDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
#include "employeebaseinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class ElderVacationDialog;
}

class ElderVacationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ElderVacationDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~ElderVacationDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_cardNo_clicked();
    void on_toolButton_auditor_clicked();
    void doubleClickRecord(QString);
    void doubleClickEmployee(QString);

private:
    bool isAdd;
    int index;
    void initView();
    Ui::ElderVacationDialog *ui;
    QSqlRelationalTableModel *model;
    ManageInfoChooseDialog *dialog;
    EmployeeBaseInfoChooseDialog *dialogEmployee;
};

#endif // ELDERVACATIONDIALOG_H
