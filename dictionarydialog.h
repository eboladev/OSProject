#ifndef DICTIONARYDIALOG_H
#define DICTIONARYDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class DictionaryDialog;
}

class DictionaryDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit DictionaryDialog(QWidget *parent = 0);
    ~DictionaryDialog();
    
private slots:
    void on_btn_ok_clicked();
    void on_btn_cancel_clicked();
    void attributeClicked(QModelIndex);
    void on_btn_add_clicked();
    void on_btn_delete_clicked();

private:
    void initModel();
    void initView();
    QStandardItemModel *model_attribute;
    QStandardItemModel *model_value;
    Ui::DictionaryDialog *ui;
};

#endif // DICTIONARYDIALOG_H
