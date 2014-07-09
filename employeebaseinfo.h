#ifndef EMPLOYEEBASEINFO_H
#define EMPLOYEEBASEINFO_H

#include <QWidget>
#include<QSqlTableModel>
#include "employeebaseinfodialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class EmployeeBaseinfo;
}

class EmployeeBaseinfo : public QWidget
{
    Q_OBJECT
    
public:
    explicit EmployeeBaseinfo(QWidget *parent = 0);
    ~EmployeeBaseinfo();
signals:
    void closeEmployeeBaseInfoPage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_add_clicked();
    void on_btn_change_clicked();
    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void doubleClickRecord(QModelIndex);
    void refreshModel();

private:
    void initModel();
    void initView();
    Ui::EmployeeBaseinfo *ui;
    QSqlTableModel *model;
    EmployeeBaseInfoDialog *dialog;
};

#endif // EMPLOYEEBASEINFO_H
