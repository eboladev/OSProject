#ifndef EMPLOYEEVACATIONDIALOG_H
#define EMPLOYEEVACATIONDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include<QButtonGroup>
#include "employeebaseinfochoosedialog.h"
namespace Ui {
class EmployeeVacationDialog;
}

class EmployeeVacationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EmployeeVacationDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~EmployeeVacationDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void doubleClickRecord(QString);
    void on_toolButton_clicked();
    void buttonJudge(int);

private:
    void initView();
    Ui::EmployeeVacationDialog *ui;
    QSqlRelationalTableModel *model;
    QButtonGroup *buttonGroup;
    EmployeeBaseInfoChooseDialog *dialog;
    bool isAdd;
    int index;
};

#endif // EMPLOYEEVACATIONDIALOG_H
