#ifndef RECEDESETTLEDIALOG_H
#define RECEDESETTLEDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
#include<QButtonGroup>
extern QSqlDatabase globaldb;
namespace Ui {
class RecedeSettleDialog;
}

class RecedeSettleDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RecedeSettleDialog(QWidget *parent = 0,QStandardItemModel *pModel = 0,int index = -1);
    ~RecedeSettleDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    float getElderAccountByCardNo(QString);
    void btnJudge(int);

private:
    void initModel();
    void initView();
    int index;
    QButtonGroup *buttonGroup;
    QStandardItemModel *model;
    Ui::RecedeSettleDialog *ui;
    QStandardItemModel *modelBed;
    QStandardItemModel *modelNurse;
    QStandardItemModel *modelSpecial;
    QStandardItemModel *modelStage;
};

#endif // RECEDESETTLEDIALOG_H
