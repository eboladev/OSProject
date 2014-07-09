#ifndef ACCIDENTRECORDDIALOG_H
#define ACCIDENTRECORDDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
#include "employeebaseinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class AccidentRecordDialog;
}

class AccidentRecordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AccidentRecordDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~AccidentRecordDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_cardNo_clicked();
    void on_toolButton_personInCharge_clicked();
    void doubleClickRecord(QString);
    void doubleClickEmployee(QString);

private:
    void initView();
    bool isAdd;
    int index;
    QSqlRelationalTableModel *model;
    ManageInfoChooseDialog *dialog;
    EmployeeBaseInfoChooseDialog *dialogEmployee;
    Ui::AccidentRecordDialog *ui;
};

#endif // ACCIDENTRECORDDIALOG_H
