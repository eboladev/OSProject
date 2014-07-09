#include "elderbirthday.h"
#include "ui_elderbirthday.h"
#include<QDate>
#include<QDir>
#include<QSqlQuery>
#include<QSqlError>
#include<QDebug>
#include "checkboxdelegate.h"
ElderBirthday::ElderBirthday(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ElderBirthday)
{
    ui->setupUi(this);
    initModel();
    initView();
}

ElderBirthday::~ElderBirthday()
{
    delete model;
    delete ui;
}

void ElderBirthday::initModel(){
    model = new QStandardItemModel(this);
    model->setColumnCount(9);
    model->setHeaderData(0,Qt::Horizontal,tr("卡号"));
    model->setHeaderData(1,Qt::Horizontal,tr("姓名"));
    model->setHeaderData(2,Qt::Horizontal,tr("性别"));
    model->setHeaderData(3,Qt::Horizontal,tr("楼宇名"));
    model->setHeaderData(4,Qt::Horizontal,tr("区号"));
    model->setHeaderData(5,Qt::Horizontal,tr("房间号"));
    model->setHeaderData(6,Qt::Horizontal,tr("床位"));
    model->setHeaderData(7,Qt::Horizontal,tr("阴历"));
    model->setHeaderData(8,Qt::Horizontal,tr("生日"));
    QSqlQuery query(globaldb);
    query.prepare("select a.cardNo,b.name,b.gender,a.buildingName,a.regionNo,a.roomNo,a.bedNo,"
                  "b.isLunar,b.lunarBirthday from manage_info a,elder_info b where a.elderId = b.eid");
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
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("MM-dd")));
        ++i;
    }
}

void ElderBirthday::initView(){
    calendar.InitConnection(QDir::currentPath());
    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();
    int days = QDate::currentDate().daysInMonth();
    ui->dateEdit_start->setDate(QDate(year,month,1));
    ui->dateEdit_end->setDate(QDate(year,month,days));
    ui->dateEdit_solarStart->setDate(QDate(year,month,1));
    ui->dateEdit_solarEnd->setDate(QDate(year,month,days));
    calendar.ctcl_solar_to_lunar(year,month,1,&cal);
    ui->dateEdit_lunarStart->setDate(QDate(year,cal.month,cal.day));
    calendar.ctcl_solar_to_lunar(year,month,days,&cal);
    ui->dateEdit_lunarEnd->setDate(QDate(year,cal.month,cal.day));
    ui->tableView->setModel(model);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->verticalHeader()->setDefaultSectionSize(20);
    ui->tableView->verticalHeader()->hide();
    ui->tableView->setAlternatingRowColors(true);
    ui->tableView->setStyleSheet("QTableView{alternate-background-color: lightgray;background:white;selection-background-color: rgb(23,165,230);}");
    ui->tableView->setItemDelegateForColumn(7,new CheckBoxDelegate(this));
}

void ElderBirthday::on_btn_clear_clicked()
{
    ui->lineEdit->setText(tr(""));
    int month = QDate::currentDate().month();
    int year = QDate::currentDate().year();
    int days = QDate::currentDate().daysInMonth();
    ui->dateEdit_start->setDate(QDate(year,month,1));
    ui->dateEdit_end->setDate(QDate(year,month,days));
}

void ElderBirthday::on_btn_search_clicked()
{
    QSqlQuery query(globaldb);
    QString sql = tr("select a.cardNo,b.name,b.gender,a.buildingName,a.regionNo,a.roomNo,a.bedNo,"
                     "b.isLunar,b.lunarBirthday from manage_info a,elder_info b where a.elderId = b.eid");
    sql.append(tr(" and ((b.isLunar = 1 and SUBSTRING(b.lunarBirthday,6,5) >= '%1' and SUBSTRING(b.lunarBirthday,6,5) <= '%2') or (b.isLunar = 0  and SUBSTRING(b.lunarBirthday,6,5) >= '%3' and SUBSTRING(b.lunarBirthday,6,5) <= '%4'))")
            .arg(ui->dateEdit_lunarStart->date().toString("MM-dd"))
            .arg(ui->dateEdit_lunarEnd->date().toString("MM-dd"))
            .arg(ui->dateEdit_solarStart->date().toString("MM-dd"))
            .arg(ui->dateEdit_solarEnd->date().toString("MM-dd")));
    if(ui->lineEdit->text().compare(tr("")) != 0)
        sql.append(tr(" and b.name = '%1'").arg(ui->lineEdit->text()));
    query.prepare(sql);
    qDebug()<<sql;
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
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
        model->setItem(i,8,new QStandardItem(query.value(8).toDate().toString("MM-dd")));
        ++i;
    }
}

void ElderBirthday::on_btn_close_clicked()
{
    emit closeElderBirthdayPage();
}

void ElderBirthday::on_dateEdit_start_dateChanged(const QDate &date)
{
    ui->dateEdit_solarStart->setDate(date);
    calendar.ctcl_solar_to_lunar(date.year(),date.month(),date.day(),&cal);
    ui->dateEdit_lunarStart->setDate(QDate(date.year(),cal.month,cal.day));
}

void ElderBirthday::on_dateEdit_end_dateChanged(const QDate &date)
{
    ui->dateEdit_solarEnd->setDate(date);
    calendar.ctcl_solar_to_lunar(date.year(),date.month(),date.day(),&cal);
    ui->dateEdit_lunarEnd->setDate(QDate(date.year(),cal.month,cal.day));
}
