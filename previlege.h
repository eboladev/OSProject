#ifndef PREVILEGE_H
#define PREVILEGE_H

#include <QWidget>
#include<QSqlTableModel>
#include<QStandardItemModel>
extern QSqlDatabase globaldb;
namespace Ui {
class Previlege;
}

class Previlege : public QWidget
{
    Q_OBJECT
    
public:
    explicit Previlege(QWidget *parent = 0);
    ~Previlege();

signals:
    void closePrevilegePage();
    
private slots:
    void on_btn_save_clicked();
    void on_btn_close_clicked();
    void createModelPrevilege();
    QString getMenuTextNameById(int);
    QMap<int,QString> getBarInfo();
    QMap<int,QString> getMenuInfoByBarId(int);
    QMap<int,QString> getBtnInfoByMenuId(int);
    void on_tableView_clicked(const QModelIndex &);
    int getMenuIdByParentIdAndTextName(int,QString);//btn,menu
    int getMenuIdByBarName(QString);//bar
    void insertRoleAndMenu(int,QList<int>);
    QList<int> getMenuIdListByRoleId(int);
    void deelteMenuByRoleId(int);

private:
    void initModel();
    void initView();
    QSqlTableModel *modelRole;
    QStandardItemModel *modelPrevilege;
    Ui::Previlege *ui;
};

#endif // PREVILEGE_H
