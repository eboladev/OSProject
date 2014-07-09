#ifndef ROLEDIALOG_H
#define ROLEDIALOG_H

#include <QDialog>
//#include<QStandardItemModel>
//#include<QSqlDatabase>
#include<QSqlTableModel>
extern QSqlDatabase globaldb;
namespace Ui {
class RoleDialog;
}

class RoleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RoleDialog(QWidget *parent = 0);
    ~RoleDialog();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();

private:
    void initModel();
    void initView();
    QSqlTableModel *model;
    Ui::RoleDialog *ui;
};

#endif // ROLEDIALOG_H
