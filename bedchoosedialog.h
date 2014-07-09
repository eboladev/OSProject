#ifndef BEDCHOOSEDIALOG_H
#define BEDCHOOSEDIALOG_H

#include <QDialog>
#include<QStandardItemModel>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class BedChooseDialog;
}

class BedChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BedChooseDialog(QWidget *parent = 0);
    ~BedChooseDialog();
    
private slots:
    void on_treeView_clicked(const QModelIndex &index);

private:
    void initView();
    void initModel();
    void createModel();
    QStandardItemModel* model;
    Ui::BedChooseDialog *ui;
};

#endif // BEDCHOOSEDIALOG_H
