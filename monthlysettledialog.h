#ifndef MONTHLYSETTLEDIALOG_H
#define MONTHLYSETTLEDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class MonthlySettleDialog;
}

class MonthlySettleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit MonthlySettleDialog(QWidget *parent = 0,QStandardItemModel *pModel = 0,int pIndex = -1);
    ~MonthlySettleDialog();
    
private slots:
    void on_btn_settle_clicked();
    float getElderAccountByCardNo(QString);

private:
    int index;
    void initModel();
    void initView();
    QStandardItemModel *model;
    Ui::MonthlySettleDialog *ui;
    QStandardItemModel *modelBed;
    QStandardItemModel *modelNurse;
    QStandardItemModel *modelSpecial;
    QStandardItemModel *modelStage;
};

#endif // MONTHLYSETTLEDIALOG_H
