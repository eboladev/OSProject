#ifndef SPECIALSERVICEDIALOG_H
#define SPECIALSERVICEDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
#include "employeebaseinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class SpecialServiceDialog;
}

class SpecialServiceDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SpecialServiceDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~SpecialServiceDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_elder_clicked();
    void on_toolButton_nurser_clicked();
    void doubleClickRecord(QString);
    void doubleClickEmployee(QString);
    void on_comboBox_currentIndexChanged(const QString &);

private:
    bool isAdd;
    int index;
    void initView();
    QSqlRelationalTableModel *model;
    Ui::SpecialServiceDialog *ui;
    ManageInfoChooseDialog *dialog;
    EmployeeBaseInfoChooseDialog *dialogEmployee;
};

#endif // SPECIALSERVICEDIALOG_H
