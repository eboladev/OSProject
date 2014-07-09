#ifndef STORAGECHOOSEDIALOG_H
#define STORAGECHOOSEDIALOG_H

#include <QDialog>
#include<QModelIndex>
namespace Ui {
class StorageChooseDialog;
}

class StorageChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StorageChooseDialog(QWidget *parent = 0);
    ~StorageChooseDialog();
signals:
    void sendStorageChoosed(int);
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initView();
    Ui::StorageChooseDialog *ui;
};

#endif // STORAGECHOOSEDIALOG_H
