#ifndef ACCOUNTPAYDIALOG_H
#define ACCOUNTPAYDIALOG_H

#include <QDialog>
#include<QSqlDatabase>
#include<QButtonGroup>
#include<QSqlTableModel>
extern QSqlDatabase globaldb;
namespace Ui {
class AccountPayDialog;
}

class AccountPayDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AccountPayDialog(QWidget *parent = 0,QSqlTableModel *pModel = 0,int pIndex = -1);
    ~AccountPayDialog();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_cancel_clicked();
    void buttonJudge(int);

private:
    void initView();
    QButtonGroup *buttonGroup;
    Ui::AccountPayDialog *ui;
    QSqlTableModel *model;
    int index;
};

#endif // ACCOUNTPAYDIALOG_H
