#ifndef MANAGEINFOCHOOSEDIALOG_H
#define MANAGEINFOCHOOSEDIALOG_H

#include <QDialog>
#include<QModelIndex>
namespace Ui {
class ManageInfoChooseDialog;
}

class ManageInfoChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ManageInfoChooseDialog(QWidget *parent = 0);
    ~ManageInfoChooseDialog();

signals:
    void sendManageInfoChoosed(QString);
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initView();
    Ui::ManageInfoChooseDialog *ui;
};

#endif // MANAGEINFOCHOOSEDIALOG_H
