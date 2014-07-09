#ifndef ELDERBASEINFOCHOOSEDIALOG_H
#define ELDERBASEINFOCHOOSEDIALOG_H

#include <QDialog>
#include<QSqlDatabase>
#include<QModelIndex>
extern QSqlDatabase globaldb;
namespace Ui {
class ElderBaseInfoChooseDialog;
}

class ElderBaseInfoChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ElderBaseInfoChooseDialog(QWidget *parent = 0,int pHealth = 0,int pReside = 0);
    ~ElderBaseInfoChooseDialog();
signals:
    void sendElderChoosed(int);
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initView();
    Ui::ElderBaseInfoChooseDialog *ui;
    int healthAssess;
    int resideRegister;
};

#endif // ELDERBASEINFOCHOOSEDIALOG_H
