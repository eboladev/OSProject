#include "previlege.h"
#include "ui_previlege.h"
#include<QMessageBox>
#include<QSqlQuery>
#include<QDebug>
#include "dictionary.h"
extern QString operatorId;
Previlege::Previlege(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Previlege)
{
    ui->setupUi(this);
    initModel();
    initView();
}

Previlege::~Previlege()
{
    delete modelRole;
    delete modelPrevilege;
    delete ui;
}

void Previlege::initModel(){
    if(!globaldb.open())
    {
        QMessageBox::warning(0,"警告","数据库连接失败！","确定");
    }
    modelRole = new QSqlTableModel(this,globaldb);
    modelRole->setTable("role");
    modelRole->setHeaderData(modelRole->fieldIndex("name"),Qt::Horizontal,tr("角色名"));
     modelRole->setHeaderData(modelRole->fieldIndex("remark"),Qt::Horizontal,tr("备注"));
     modelRole->select();

     modelPrevilege = new QStandardItemModel(this);
     modelPrevilege->setColumnCount(7);
     modelPrevilege->setHeaderData(0,Qt::Horizontal,tr("功能模块"));
     modelPrevilege->setHeaderData(1,Qt::Horizontal,tr("查看权限"));
     modelPrevilege->setHeaderData(2,Qt::Horizontal,tr("添加权限"));
     modelPrevilege->setHeaderData(3,Qt::Horizontal,tr("修改权限"));
     modelPrevilege->setHeaderData(4,Qt::Horizontal,tr("删除权限"));
     modelPrevilege->setHeaderData(5,Qt::Horizontal,tr("导出权限"));
     modelPrevilege->setHeaderData(6,Qt::Horizontal,tr("打印权限"));
     createModelPrevilege();
}

void Previlege::initView(){
    QStringList list = Dictionary::getBtnListByParentAndUser("previlege_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_save->setEnabled(false);
    ui->tableView->setModel(modelRole);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->hideColumn(modelRole->fieldIndex("id"));

    ui->treeView->setModel(modelPrevilege);
    ui->treeView->setColumnWidth(0,160);
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->treeView->expandAll();
}

void Previlege::createModelPrevilege(){
    QMap<int,QString> map = getBarInfo();
    QMapIterator<int,QString> iterator(map);
    unsigned char column = 1;
    while(iterator.hasNext()){
        iterator.next();
        QStandardItem *item = new QStandardItem(tr("%1").arg(iterator.value()));
        if(iterator.value().compare(tr("来访登记管理")) == 0){
            QMap<int,QString> btnMap = getBtnInfoByMenuId(iterator.key());
            QMapIterator<int,QString> btnMapIterator(btnMap);
            column = 1;
            while(btnMapIterator.hasNext()){
                btnMapIterator.next();
                if(btnMapIterator.value().compare(tr("查看")) == 0)
                    column = 1;
                else if(btnMapIterator.value().compare(tr("添加")) == 0)
                    column = 2;
                else if(btnMapIterator.value().compare(tr("修改")) == 0)
                    column = 3;
                else if(btnMapIterator.value().compare(tr("删除")) == 0)
                    column = 4;
                else if(btnMapIterator.value().compare(tr("导出")) == 0)
                    column = 5;
                else
                    column = 6;
                QStandardItem *btn = new QStandardItem;
                btn->setCheckable(true);
                item->setChild(0,column,btn);
                ++column;
            }
            modelPrevilege->appendRow(item);
        }
//        else if(iterator.value().compare(tr("报表管理")) == 0){
//            modelPrevilege->appendRow(item);
//            continue;
//        }
        else{
            QMap<int,QString> menuMap = getMenuInfoByBarId(iterator.key());
            QMapIterator<int,QString> menuIterator(menuMap);
            while(menuIterator.hasNext()){
                menuIterator.next();
                QStandardItem *menu = new QStandardItem(tr("%1").arg(menuIterator.value()));                
                QMap<int,QString> btnMap = getBtnInfoByMenuId(menuIterator.key());
                QMapIterator<int,QString> btnMapIterator(btnMap);
                column = 1;
                while(btnMapIterator.hasNext()){
                    btnMapIterator.next();
                    if(btnMapIterator.value().compare(tr("查看")) == 0)
                        column = 1;
                    else if(btnMapIterator.value().compare(tr("添加")) == 0)
                        column = 2;
                    else if(btnMapIterator.value().compare(tr("修改")) == 0)
                        column = 3;
                    else if(btnMapIterator.value().compare(tr("删除")) == 0)
                        column = 4;
                    else if(btnMapIterator.value().compare(tr("导出")) == 0)
                        column = 5;
                    else
                        column = 6;
                    QStandardItem *btn = new QStandardItem;
                    btn->setCheckable(true);
                    menu->setChild(0,column,btn);
                    ++column;
                }
                item->appendRow(menu);
            }
            modelPrevilege->appendRow(item);
        }
    }
    qDebug()<<modelPrevilege->rowCount();
}

void Previlege::on_btn_save_clicked()
{   
    int roleId = modelRole->data(modelRole->index(ui->tableView->currentIndex().row(),0)).toInt();    
    if(roleId == 0){
        QMessageBox::warning(0,"警告","请选择角色","确定");
        return;
    }
    deelteMenuByRoleId(roleId);
    QList<int> menuIdList;
    unsigned char i;
    unsigned char j;
    unsigned char column;
    int pId;
    int menuId;
    QString btnName;
    for(i = 0;i<modelPrevilege->rowCount();++i){
        QStandardItem *item = modelPrevilege->item(i);
        qDebug()<<item->text();
        pId = getMenuIdByBarName(item->text());
        if(i == 0){
            for(column=1;column<=6;++column){
                if(column == 1)
                    btnName = tr("查看");
                else if(column == 2)
                    btnName = tr("添加");
                else if(column == 3)
                    btnName = tr("修改");
                else if(column == 4)
                    btnName = tr("删除");
                else if(column == 5)
                    btnName = tr("导出");
                else
                    btnName = tr("打印");
                QStandardItem *btn = item->child(0,column);
                if(btn){
                    if(btn->checkState() ==Qt::Checked )
                        menuIdList.append(getMenuIdByParentIdAndTextName(pId,btnName));
                }
            }
        }
//        else if(i == 4){
//                continue;
//        }
        else{
            for(j=0;j<item->rowCount();++j){
                QStandardItem *menu = item->child(j);
                qDebug()<<menu->text();
                menuId = getMenuIdByParentIdAndTextName(pId,menu->text());
                for(column=1;column<=6;++column){
                    if(column == 1)
                        btnName = tr("查看");
                    else if(column == 2)
                        btnName = tr("添加");
                    else if(column == 3)
                        btnName = tr("修改");
                    else if(column == 4)
                        btnName = tr("删除");
                    else if(column == 5)
                        btnName = tr("导出");
                    else
                        btnName = tr("打印");
                    QStandardItem *btn = menu->child(0,column);
                    if(btn){
                        if(btn->checkState() ==Qt::Checked )
                            menuIdList.append(getMenuIdByParentIdAndTextName(menuId,btnName));
                    }
                }
            }
        }
    }
    insertRoleAndMenu(roleId,menuIdList);
    QMessageBox::information(0,"消息","设置成功","确定");
}

void Previlege::on_btn_close_clicked()
{
    emit closePrevilegePage();
}

QString Previlege::getMenuTextNameById(int id){
    QSqlQuery query(globaldb);
    query.prepare("select textName from menu where id = ?");
    query.addBindValue(id);
    query.exec();
    QString name;
    if(query.first())
        name = query.value(0).toString();
    query.finish();
    query.clear();
    return name;
}

QMap<int,QString> Previlege::getBarInfo(){
    QSqlQuery query(globaldb);
    query.prepare("select id,textName from menu where type = 1");
    query.exec();
    QMap<int,QString> map;
    while(query.next())
        map.insert(query.value(0).toInt(),query.value(1).toString());
    query.finish();
    query.clear();
    return map;
}

QMap<int,QString> Previlege::getMenuInfoByBarId(int id){
    QSqlQuery query(globaldb);
    query.prepare("select id,textName from menu where type = 2 and parentId = ?");
    query.addBindValue(id);
    query.exec();
    QMap<int,QString> map;
    while(query.next())
        map.insert(query.value(0).toInt(),query.value(1).toString());
    query.finish();
    query.clear();
    return map;
}

QMap<int,QString> Previlege::getBtnInfoByMenuId(int id){
    QSqlQuery query(globaldb);
    query.prepare("select id,textName from menu where type = 3 and parentId = ?");
    query.addBindValue(id);
    query.exec();
    QMap<int,QString> map;
    while(query.next())
        map.insert(query.value(0).toInt(),query.value(1).toString());
    query.finish();
    query.clear();
    return map;
}

void Previlege::on_tableView_clicked(const QModelIndex &index)
{
    modelPrevilege->removeRows(0,modelPrevilege->rowCount());
    int roleId = modelRole->data(modelRole->index(index.row(),0)).toInt();
    QList<int> menuIdList = getMenuIdListByRoleId(roleId);
    QMap<int,QString> map = getBarInfo();
    QMapIterator<int,QString> iterator(map);
    unsigned char column = 1;
    while(iterator.hasNext()){
        iterator.next();
        QStandardItem *item = new QStandardItem(tr("%1").arg(iterator.value()));
        if(iterator.value().compare(tr("来访登记管理")) == 0){
            QMap<int,QString> btnMap = getBtnInfoByMenuId(iterator.key());
            QMapIterator<int,QString> btnMapIterator(btnMap);
            column = 1;
            while(btnMapIterator.hasNext()){
                btnMapIterator.next();
                if(btnMapIterator.value().compare(tr("查看")) == 0)
                    column = 1;
                else if(btnMapIterator.value().compare(tr("添加")) == 0)
                    column = 2;
                else if(btnMapIterator.value().compare(tr("修改")) == 0)
                    column = 3;
                else if(btnMapIterator.value().compare(tr("删除")) == 0)
                    column = 4;
                else if(btnMapIterator.value().compare(tr("导出")) == 0)
                    column = 5;
                else
                    column = 6;
                QStandardItem *btn = new QStandardItem;
                btn->setCheckable(true);
                if(menuIdList.contains(btnMapIterator.key()))
                    btn->setCheckState(Qt::Checked);
                item->setChild(0,column,btn);
                ++column;
            }
            modelPrevilege->appendRow(item);
        }
//        else if(iterator.value().compare(tr("报表管理")) == 0){
//            modelPrevilege->appendRow(item);
//            continue;
//        }
        else{
            QMap<int,QString> menuMap = getMenuInfoByBarId(iterator.key());
            QMapIterator<int,QString> menuIterator(menuMap);
            while(menuIterator.hasNext()){
                menuIterator.next();
                QStandardItem *menu = new QStandardItem(tr("%1").arg(menuIterator.value()));
                QMap<int,QString> btnMap = getBtnInfoByMenuId(menuIterator.key());
                QMapIterator<int,QString> btnMapIterator(btnMap);
                column = 1;
                while(btnMapIterator.hasNext()){
                    btnMapIterator.next();
                    if(btnMapIterator.value().compare(tr("查看")) == 0)
                        column = 1;
                    else if(btnMapIterator.value().compare(tr("添加")) == 0)
                        column = 2;
                    else if(btnMapIterator.value().compare(tr("修改")) == 0)
                        column = 3;
                    else if(btnMapIterator.value().compare(tr("删除")) == 0)
                        column = 4;
                    else if(btnMapIterator.value().compare(tr("导出")) == 0)
                        column = 5;
                    else
                        column = 6;
                    QStandardItem *btn = new QStandardItem;
                    btn->setCheckable(true);
                    if(menuIdList.contains(btnMapIterator.key()))
                        btn->setCheckState(Qt::Checked);
                    menu->setChild(0,column,btn);
                    ++column;
                }
                item->appendRow(menu);
            }
            modelPrevilege->appendRow(item);
        }
    }
    qDebug()<<modelPrevilege->rowCount();
    ui->treeView->expandAll();
}

int Previlege::getMenuIdByParentIdAndTextName(int parentId, QString textName){
    QSqlQuery query(globaldb);
    query.prepare("select id from menu where parentId = ? and textName = ?");
    query.addBindValue(parentId);
    query.addBindValue(textName);
    query.exec();
    int id=0;
    if(query.first())
        id=query.value(0).toInt();
    query.finish();
    query.clear();
    return id;
}

int Previlege::getMenuIdByBarName(QString name){
    QSqlQuery query(globaldb);
    query.prepare("select id from menu where  textName = ?");
    query.addBindValue(name);
    query.exec();
    int id=0;
    if(query.first())
        id=query.value(0).toInt();
    query.finish();
    query.clear();
    return id;
}

void Previlege::insertRoleAndMenu(int roleId, QList<int> menuIdList){
    QSqlQuery query(globaldb);
    for(int i=0;i<menuIdList.size();++i){
        query.prepare("insert into role_menu values(NULL,?,?)");
        query.addBindValue(roleId);
        query.addBindValue(menuIdList.at(i));
        query.exec();
        query.finish();
    }
    query.clear();
}

QList<int> Previlege::getMenuIdListByRoleId(int roleId){
    QSqlQuery query(globaldb);
    query.prepare("select menuId from role_menu where roleId = ?");
    query.addBindValue(roleId);
    query.exec();
    QList<int> list;
    while(query.next())
        list.append(query.value(0).toInt());
    query.finish();
    query.clear();
    return list;
}

void Previlege::deelteMenuByRoleId(int roleId){
    QSqlQuery query(globaldb);
    query.prepare("delete from role_menu where roleId = ?");
    query.addBindValue(roleId);
    query.exec();
    query.finish();
    query.clear();
}
