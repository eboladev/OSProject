#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QWidget>
#include<QSqlRelationalTableModel>
#include "checkoutdialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class CheckOut;
}

class CheckOut : public QWidget
{
    Q_OBJECT
    
public:
    explicit CheckOut(QWidget *parent = 0);
    ~CheckOut();

signals:
    void closeCheckOutPage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_add_clicked();
//    void on_btn_change_clicked();
//    void on_btn_delete_clicked();
    void on_btn_close_clicked();
    void refreshModel();
    void doubleClickRecord(QModelIndex);

private:
    void initModel();
    void initView();
    Ui::CheckOut *ui;
    QSqlRelationalTableModel *model;
    CheckOutDialog *dialog;
};

#endif // CHECKOUT_H
