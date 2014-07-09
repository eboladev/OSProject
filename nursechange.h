#ifndef NURSECHANGE_H
#define NURSECHANGE_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "nursechangedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class NurseChange;
}

class NurseChange : public QWidget
{
    Q_OBJECT
    
public:
    explicit NurseChange(QWidget *parent = 0);
    ~NurseChange();

signals:
    void closeNurseChangePage();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_change_clicked();
    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);    

private:
    void initModel();
    void initView();
    Ui::NurseChange *ui;
    QSqlRelationalTableModel *model;
    NurseChangeDialog *dialog;
};

#endif // NURSECHANGE_H
