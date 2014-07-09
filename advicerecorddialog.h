#ifndef ADVICERECORDDIALOG_H
#define ADVICERECORDDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
#include "employeebaseinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class AdviceRecordDialog;
}

class AdviceRecordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdviceRecordDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~AdviceRecordDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_cardNo_clicked();
    void on_toolButton_doctor_clicked();
    void doubleClickRecord(QString);
    void doubleClickEmployee(QString);

private:
    void initView();
    bool isAdd;
    int index;
    QSqlRelationalTableModel *model;
    Ui::AdviceRecordDialog *ui;
    ManageInfoChooseDialog *dialog;
    EmployeeBaseInfoChooseDialog *dialogEmployee;
};

#endif // ADVICERECORDDIALOG_H
