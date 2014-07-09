#ifndef STORAGE_H
#define STORAGE_H

#include <QWidget>
#include<QSqlTableModel>
extern QSqlDatabase globaldb;
namespace Ui {
class Storage;
}

class Storage : public QWidget
{
    Q_OBJECT
    
public:
    explicit Storage(QWidget *parent = 0);
    ~Storage();
signals:
    void closeStoragePage();
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void on_btn_close_clicked();

private:
    void initModel();
    void initView();
    Ui::Storage *ui;
    QSqlTableModel *model;
};

#endif // STORAGE_H
