#ifndef ADVICECHOOSEDIALOG_H
#define ADVICECHOOSEDIALOG_H

#include <QDialog>
#include<QModelIndex>
#include<QSqlDatabase>
extern QSqlDatabase globaldb;
namespace Ui {
class AdviceChooseDialog;
}

class AdviceChooseDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AdviceChooseDialog(QWidget *parent = 0);
    ~AdviceChooseDialog();
signals:
    void sendAdviceChoosed(int);
    
private slots:
    void on_btn_clear_clicked();
    void on_btn_search_clicked();
    void doubleClickRecord(QModelIndex);

private:
    void initView();
    Ui::AdviceChooseDialog *ui;
};

#endif // ADVICECHOOSEDIALOG_H
