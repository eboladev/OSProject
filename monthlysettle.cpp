#include "monthlysettle.h"
#include "ui_monthlysettle.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QDate>
#include<QMessageBox>
#include "settlestatusdelegate.h"
#include "dictionary.h"
#include "print.h"
extern QString operatorId;
MonthlySettle::MonthlySettle(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonthlySettle)
{
    ui->setupUi(this);
    initModel();
    initView();
}

MonthlySettle::~MonthlySettle()
{
    delete as;
    delete model;
    delete ui;
}

void MonthlySettle::initModel(){
    ui->dateEdit->setDate(QDate::currentDate().addMonths(-1));
    as = new AutoSettle;
    model = new QStandardItemModel(this);
    model->setColumnCount(12);
    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("状态"));
    model->setHeaderData(3,Qt::Horizontal,tr("床位费"));
    model->setHeaderData(4,Qt::Horizontal,tr("护理费"));
    model->setHeaderData(5,Qt::Horizontal,tr("特殊服务费"));
    model->setHeaderData(6,Qt::Horizontal,tr("阶段性费用"));
    model->setHeaderData(7,Qt::Horizontal,tr("月总费用"));
    model->setHeaderData(8,Qt::Horizontal,tr("对应月份"));
    model->setHeaderData(9,Qt::Horizontal,tr("结算日期"));
    model->setHeaderData(10,Qt::Horizontal,tr("操作员"));
    model->setHeaderData(11,Qt::Horizontal,tr("操作时间"));
    QSqlQuery query(globaldb);
    query.prepare("select a.cardNo,b.name,a.isSettled,a.bedCost,a.nurseCost,a.specialCost,a.stageCost,"
                  "a.monthlyCost,a.mapMonth,a.settleDate,a.operator,a.operationTime from settle_account a,manage_info b "
                  "where a.cardNo = b.cardNo and SUBSTRING(a.mapMonth,1,7) = ?");
    query.addBindValue(ui->dateEdit->date().toString("yyyy-MM"));
    query.exec();
    int i=0;
    while(query.next()){
        model->setItem(i,0,new QStandardItem(query.value(0).toString()));
        model->setItem(i,1,new QStandardItem(query.value(1).toString()));
        model->setItem(i,2,new QStandardItem(query.value(2).toString()));
        model->setItem(i,3,new QStandardItem(query.value(3).toString()));
        model->setItem(i,4,new QStandardItem(query.value(4).toString()));
        model->setItem(i,5,new QStandardItem(query.value(5).toString()));
        model->setItem(i,6,new QStandardItem(query.value(6).toString()));
        model->setItem(i,7,new QStandardItem(query.value(7).toString()));
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("yyyy-MM")));
        model->setItem(i,9,new QStandardItem(query.value(9).toString()));
        model->setItem(i,10,new QStandardItem(query.value(10).toString()));
        model->setItem(i,11,new QStandardItem(query.value(11).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
        ++i;
    }
}

void MonthlySettle::initView(){    
    if(isSettled())
        ui->btn_auto->setEnabled(false);
    QStringList list = Dictionary::getBtnListByParentAndUser("monthly_settle_toolbutton",operatorId);
    if(!list.contains(tr("添加")))
        ui->btn_auto->setEnabled(false);
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setColumnWidth(2,45);
//    ui->tableView->setColumnWidth(1,80);
//    ui->tableView->setColumnWidth(5,150);
//    ui->tableView->setColumnWidth(6,150);
//    ui->tableView->setColumnWidth(7,150);
//    ui->tableView->setColumnWidth(9,150);
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(doubleClickRecord(QModelIndex)));
    ui->tableView->setItemDelegateForColumn(2,new SettleStatusDelegate(this));
}

bool MonthlySettle::isSettled(){
    QSqlQuery query(globaldb);
    query.prepare("select count(*) from settle_log where settleMonth = ?");
    query.addBindValue(QObject::tr("%1-%2").arg(QDate::currentDate().addMonths(-1).year()).arg(QDate::currentDate().addMonths(-1).month()));
    query.exec();
    if(query.first()){
        return query.value(0).toInt();
    }
    return false;
}

void MonthlySettle::on_btn_close_clicked()
{
    emit closeMonthlySettlePage();
}

void MonthlySettle::on_btn_clear_clicked()
{
    ui->lineEdit_cardNo->setText(tr(""));
    ui->lineEdit_name->setText(tr(""));
    ui->comboBox->setCurrentIndex(ui->comboBox->findText(tr("全部")));
    ui->dateEdit->setDate(QDate::currentDate().addMonths(-1));
}

void MonthlySettle::on_btn_search_clicked()
{
    QSqlQuery query(globaldb);
    QString sql = tr("select a.cardNo,b.name,a.isSettled,a.bedCost,a.nurseCost,a.specialCost,a.stageCost,"
                     "a.monthlyCost,a.mapMonth,a.settleDate,a.operator,a.operationTime from settle_account a,manage_info b "
                     "where a.cardNo = b.cardNo and SUBSTRING(a.mapMonth,1,7) = '%1'").arg(ui->dateEdit->date().toString("yyyy-MM"));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and b.name = '%1'").arg(ui->lineEdit_name->text()));
    if(ui->comboBox->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox->currentText().compare("已结算"))
            sql.append(tr(" and a.isSettled = 1"));
        else
            sql.append(tr(" and a.isSettled = 0"));
    }
    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    model->removeRows(0,model->rowCount());
    int i=0;
    while(query.next()){
        model->setItem(i,0,new QStandardItem(query.value(0).toString()));
        model->setItem(i,1,new QStandardItem(query.value(1).toString()));
        model->setItem(i,2,new QStandardItem(query.value(2).toString()));
        model->setItem(i,3,new QStandardItem(query.value(3).toString()));
        model->setItem(i,4,new QStandardItem(query.value(4).toString()));
        model->setItem(i,5,new QStandardItem(query.value(5).toString()));
        model->setItem(i,6,new QStandardItem(query.value(6).toString()));
        model->setItem(i,7,new QStandardItem(query.value(7).toString()));
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("yyyy-MM")));
        model->setItem(i,9,new QStandardItem(query.value(9).toString()));
        model->setItem(i,10,new QStandardItem(query.value(10).toString()));
        model->setItem(i,11,new QStandardItem(query.value(11).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
        ++i;
    }
}

void MonthlySettle::doubleClickRecord(QModelIndex index){
    dialog = new MonthlySettleDialog(this,model,index.row());
    connect(dialog,SIGNAL(accepted()),this,SLOT(on_btn_search_clicked()));
    dialog->exec();
}

void MonthlySettle::on_btn_auto_clicked()
{
    int result = QMessageBox::question(this,tr("警告"),tr("该功能每月仅可使用一次，确定进行月费用结算吗？"),QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    if(result == QMessageBox::Ok){
        qDebug()<<tr("自动结算开始");
        as->expenseSettle();
        qDebug()<<tr("自动结算结束");
        ui->btn_auto->setEnabled(false);
    }    
    on_btn_search_clicked();
}

void MonthlySettle::on_toolButton_clicked()
{
    chooseDialog = new ManageInfoChooseDialog(this);
    connect(chooseDialog,SIGNAL(sendManageInfoChoosed(QString)),this,SLOT(doubleClickElder(QString)));
    chooseDialog->exec();
}

void MonthlySettle::doubleClickElder(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select name from manage_info where cardNo = ? ");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    if( query.first()){
        ui->lineEdit_cardNo->setText(cardNo);
        ui->lineEdit_name->setText(query.value(0).toString());
    }
    query.clear();
    query.finish();
}

void MonthlySettle::on_btn_print_clicked()
{
    QSqlQuery query(globaldb);
    QString sql = tr("select a.cardNo,b.name,a.isSettled,a.bedCost,a.nurseCost,a.specialCost,a.stageCost,"
                     "a.monthlyCost,a.mapMonth,a.settleDate,a.operator,a.operationTime from settle_account a,manage_info b "
                     "where a.cardNo = b.cardNo and SUBSTRING(a.mapMonth,1,7) = '%1'").arg(ui->dateEdit->date().toString("yyyy-MM"));
    if(ui->lineEdit_cardNo->text().compare(tr("")) != 0)
        sql.append(tr(" and a.cardNo = '%1'").arg(ui->lineEdit_cardNo->text()));
    if(ui->lineEdit_name->text().compare(tr("")) != 0)
        sql.append(tr(" and b.name = '%1'").arg(ui->lineEdit_name->text()));
    if(ui->comboBox->currentText().compare(tr("全部")) != 0){
        if(ui->comboBox->currentText().compare("已结算"))
            sql.append(tr(" and a.isSettled = 1"));
        else
            sql.append(tr(" and a.isSettled = 0"));
    }
    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QString html = tr(" <table width=\"100%\" border=1 bordercolor=\"#000000\" cellspacing=0> <tr> <th>卡号</th><th>姓名</th> <th>状态</th>"
              "<th>床位费</th><th>护理费</th> <th>特殊服务费</th><th>阶段性费用</th>"
              "<th>月总费用</th><th>对应月份</th><th>结算日期</th><th>操作员</th> <th>操作时间</th></tr>");

    while(query.next()){
        html.append(tr("<tr><td>%1</td><td>%2</td><td>%3</td><td>%4</td><td>%5</td><td>%6</td><td>%7</td>"
          "<td>%8</td><td>%9</td><td>%10</td><td>%11</td><td>%12</td></tr>").arg(query.value(0).toString()).arg(query.value(1).toString())
          .arg(query.value(2).toInt()? tr("已结算"):tr("未结算")).arg(query.value(3).toString()).arg(query.value(4).toString()).arg(query.value(5).toString())
                    .arg(query.value(6).toString()).arg(query.value(7).toString()).arg(query.value(8).toDate().toString("yyyy-MM")).arg(query.value(9).toString())
                    .arg(query.value(10).toString()).arg(query.value(11).toDateTime().toString("yyyy-MM-dd H:mm:ss")));
    }
    html.append(tr("</table>"));
    Print::printHtml(html);
}
