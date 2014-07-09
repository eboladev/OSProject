#ifndef ACCOUNTPAY_H
#define ACCOUNTPAY_H

#include <QWidget>
#include<QSqlTableModel>
#include "accountpaydialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class AccountPay;
}

class AccountPay : public QWidget
{
    Q_OBJECT
    
public:
    explicit AccountPay(QWidget *parent = 0);
    ~AccountPay();

signals:
    void closeAccountPayPage();
    
private slots:
    void on_btn_accountPay_clicked();
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::AccountPay *ui;
    QSqlTableModel *model;
    AccountPayDialog *dialog;
};

#endif // ACCOUNTPAY_H
