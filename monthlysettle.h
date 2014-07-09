#ifndef MONTHLYSETTLE_H
#define MONTHLYSETTLE_H

#include <QWidget>
#include<QStandardItemModel>
#include<QDate>
#include<QSqlDatabase>
#include "autosettle.h"
#include "manageinfochoosedialog.h"
#include "monthlysettledialog.h"
extern QSqlDatabase globaldb;
namespace Ui {
class MonthlySettle;
}

class MonthlySettle : public QWidget
{
    Q_OBJECT
    
public:
    explicit MonthlySettle(QWidget *parent = 0);
    ~MonthlySettle();

signals:
    void closeMonthlySettlePage();
    
private slots:    
    void on_btn_close_clicked();
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);
    void on_btn_auto_clicked();
    void on_toolButton_clicked();
    void doubleClickElder(QString);
    void on_btn_print_clicked();

private:
    void initModel();
    void initView();
    bool isSettled();
    AutoSettle *as;
    Ui::MonthlySettle *ui;
    QStandardItemModel *model;
    ManageInfoChooseDialog *chooseDialog;
    MonthlySettleDialog *dialog;
};

#endif // MONTHLYSETTLE_H
