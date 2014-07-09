#ifndef RECEDESETTLE_H
#define RECEDESETTLE_H

#include <QWidget>
#include<QStandardItemModel>
#include "recedesettledialog.h"
#include<QSqlDatabase>
#include "manageinfochoosedialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class RecedeSettle;
}

class RecedeSettle : public QWidget
{
    Q_OBJECT
    
public:
    explicit RecedeSettle(QWidget *parent = 0);
    ~RecedeSettle();
signals:
    void closeRecedeSettlePage();
    
private slots:
    void on_btn_settle_clicked();
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);
    void on_toolButton_clicked();
    void doubleClickRecord(QString);


private:
    void initModel();
    void initView();
    Ui::RecedeSettle *ui;
    QStandardItemModel *model;
    RecedeSettleDialog *dialog;
    ManageInfoChooseDialog *chooseDialog;
};

#endif // RECEDESETTLE_H
