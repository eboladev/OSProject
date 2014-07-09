#ifndef OPERATORDIALOG_H
#define OPERATORDIALOG_H

#include <QDialog>
#include<QSqlTableModel>
#include<QSqlRelationalTableModel>
extern QSqlDatabase globaldb;
namespace Ui {
class OperatorDialog;
}

class OperatorDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit OperatorDialog(QWidget *parent = 0);
    ~OperatorDialog();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void on_tableView_role_clicked(const QModelIndex &);

private:
    void initModel();
    void initView();
    QSqlTableModel *modelRole;
    QSqlRelationalTableModel *modelOperator;
    Ui::OperatorDialog *ui;
};

#endif // OPERATORDIALOG_H
