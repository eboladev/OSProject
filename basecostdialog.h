#ifndef BASECOSTDIALOG_H
#define BASECOSTDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class BaseCostDialog;
}

class BaseCostDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BaseCostDialog(QWidget *parent = 0);
    ~BaseCostDialog();
    
private slots:
    void on_btn_add_clicked();
    void on_btn_delete_clicked();
    void on_btn_ok_clicked();
    void on_btn_cancel_clicked();
    void attributeClicked(QModelIndex);

private:
    void initModel();
    void initView();
    QStandardItemModel *model_attribute;
    QStandardItemModel *model_value;
    Ui::BaseCostDialog *ui;
};

#endif // BASECOSTDIALOG_H
