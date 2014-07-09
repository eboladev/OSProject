#ifndef EMPLOYEEVACATION_H
#define EMPLOYEEVACATION_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "employeevacationdialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class EmployeeVacation;
}

class EmployeeVacation : public QWidget
{
    Q_OBJECT
    
public:
    explicit EmployeeVacation(QWidget *parent = 0);
    ~EmployeeVacation();
signals:
    void closeEmployeeVacationPage();
    
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
    Ui::EmployeeVacation *ui;
    QSqlRelationalTableModel *model;
    EmployeeVacationDialog *dialog;
};

#endif // EMPLOYEEVACATION_H
