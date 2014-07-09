#ifndef EMPLOYEEBASEINFODIALOG_H
#define EMPLOYEEBASEINFODIALOG_H

#include <QDialog>
#include<QSqlTableModel>
namespace Ui {
class EmployeeBaseInfoDialog;
}

class EmployeeBaseInfoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit EmployeeBaseInfoDialog(QWidget *parent = 0,QSqlTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~EmployeeBaseInfoDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    void initView();
    Ui::EmployeeBaseInfoDialog *ui;
    QSqlTableModel *model;
    bool isAdd;
    int index;
};

#endif // EMPLOYEEBASEINFODIALOG_H
