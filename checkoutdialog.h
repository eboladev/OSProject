#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "storagechoosedialog.h"
#include "employeebaseinfochoosedialog.h"
namespace Ui {
class CheckOutDialog;
}

class CheckOutDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit CheckOutDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int index = -1);
    ~CheckOutDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void doubleClickRecord(QString);
    void on_toolButton_clicked();
    void on_toolButton_storage_clicked();
    void doubleClickStorage(int);

private:
    void initView();
    Ui::CheckOutDialog *ui;
    EmployeeBaseInfoChooseDialog *dialog;
    StorageChooseDialog *storageDialog;
    QSqlRelationalTableModel *model;
    bool isAdd;
    int index;
};

#endif // CHECKOUTDIALOG_H
