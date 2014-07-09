#ifndef NURSERECORDDIALOG_H
#define NURSERECORDDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
#include "advicechoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class NurseRecordDialog;
}

class NurseRecordDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NurseRecordDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~NurseRecordDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_cardNo_clicked();
    void on_toolButton_adviceId_clicked();
    void doubleClickRecord(QString);
    void doubleClickAdvice(int);

private:
    void initView();
    Ui::NurseRecordDialog *ui;
    QSqlRelationalTableModel *model;
    ManageInfoChooseDialog *dialog;
    AdviceChooseDialog *dialogAdvice;
    bool isAdd;
    int index;
};

#endif // NURSERECORDDIALOG_H
