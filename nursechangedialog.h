#ifndef NURSECHANGEDIALOG_H
#define NURSECHANGEDIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include "manageinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class NurseChangeDialog;
}

class NurseChangeDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit NurseChangeDialog(QWidget *parent = 0,QSqlRelationalTableModel *pModel = 0,bool pIsAdd = false,int pIndex = -1);
    ~NurseChangeDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_toolButton_cardNo_clicked();
    void on_toolButton_building_clicked();
    void doubleClickRecord(QString);
    void on_comboBox_latterBedLevel_currentIndexChanged(const QString &);
    void on_comboBox_latterNurseLevel_currentIndexChanged(const QString &);
    void updateManageInfo(QString,float,float);

private:
    void initView();
    bool isAdd;
    int index;
    Ui::NurseChangeDialog *ui;
    QSqlRelationalTableModel *model;
    ManageInfoChooseDialog *dialog;
};

#endif // NURSECHANGEDIALOG_H
