#ifndef STAGECOSTDIALOG_H
#define STAGECOSTDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class StageCostDialog;
}

class StageCostDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StageCostDialog(QWidget *parent = 0);
    ~StageCostDialog();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_ok_clicked();
    void on_btn_cancel_clicked();

private:
    void initModel();
    void initView();
    Ui::StageCostDialog *ui;
    QStandardItemModel *model;
};

#endif // STAGECOSTDIALOG_H
