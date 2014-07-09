#include "autosettle.h"
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>
#include<QSqlDatabase>
#include<QDateTime>
extern QSqlDatabase globaldb;
AutoSettle::AutoSettle(QObject *parent) :
    QObject(parent)
{
}

void AutoSettle::expenseSettle(){
    if(QSqlDatabase::database().transaction()){
        QSqlQuery query(globaldb);
        query.prepare("select count(*) from settle_log where settleMonth = ?");
        query.addBindValue(QObject::tr("%1-%2").arg(QDate::currentDate().addMonths(-1).year()).arg(QDate::currentDate().addMonths(-1).month()));
        query.exec();       
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        if(query.first()){            
            if(query.value(0).toInt() == 0){
                query.prepare("insert into settle_log values (NULL,?)");
                query.addBindValue(QObject::tr("%1-%2").arg(QDate::currentDate().addMonths(-1).year()).arg(QDate::currentDate().addMonths(-1).month()));
                query.exec();
                query.finish();
                query.clear();
                if(query.lastError().isValid())
                    qDebug()<<query.lastError();
                QStringList list = getElderCardNoList();
                for(int i = 0;i<list.size();++i){
                    query.prepare("insert into settle_account values (NULL,?,?,?,?,?,?,?,?,?,?,?)");
                    query.addBindValue(list.at(i));
                    float account = getElderAccountByCardNo(list.at(i));
                    float bedCost = getElderBedCostByCardNo(list.at(i));
                    float nurseCost = getElderNurseCostByCardNo(list.at(i));
                    float specialCost = getElderSpecialServiceCostByCardNo(list.at(i));
                    float stageCost = getElderStageCost(list.at(i));
                    updateLevelChangedByCardNo(list.at(i));
                    float totalCost = bedCost+nurseCost+specialCost+stageCost;
                    if(account>totalCost){
                        query.addBindValue(1);
                        updateAccountByCardNoAndCost(list.at(i),totalCost);
                    }
                    else
                        query.addBindValue(0);
                    query.addBindValue(bedCost);
                    query.addBindValue(nurseCost);
                    query.addBindValue(specialCost);
                    query.addBindValue(stageCost);
                    query.addBindValue(totalCost);
                    query.addBindValue(QDate::currentDate().addMonths(-1));
                    if(account>totalCost)
                        query.addBindValue(QDate::currentDate());
                    else
                        query.addBindValue(NULL);
                    query.addBindValue(tr("system"));
                    query.addBindValue(QDateTime::currentDateTime());
                    query.exec();
                    if(query.lastError().isValid())
                        qDebug()<<query.lastError();
                }
            }
        }
        if(!QSqlDatabase::database().commit()){
            qDebug()<<QSqlDatabase::database().lastError();
            if(!QSqlDatabase::database().rollback())
                qDebug()<<QSqlDatabase::database().lastError();
        }
    }
}

QStringList AutoSettle::getElderCardNoList(){
    QSqlQuery query(globaldb);
    query.prepare("select cardNo from manage_info where status != 3");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QStringList list;
    while(query.next())
        list.append(query.value(0).toString());
    query.finish();
    query.clear();
    return list;
}

float AutoSettle::getElderAccountByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select account from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    float account = 0;
    if(query.first())
        account = query.value(0).toFloat();
    query.finish();
    query.clear();
    return account;
}

float AutoSettle::getElderBedCostByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate,levelChanged,bedCost from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    int isChanged = 0;
    bool isNewResided = false;
    float bedCost = 0;
    float monthlyCost = 0;
    QDate resideDate;
    if(query.first()){
        resideDate = query.value(0).toDate();
        isChanged = query.value(1).toInt();
        bedCost = query.value(2).toFloat();
    }
    if(resideDate.year() == QDate::currentDate().addMonths(-1).year() && resideDate.month() == QDate::currentDate().addMonths(-1).month())
        isNewResided = true;
    if(isChanged){
        QMap<QDate,float> map = getElderBedChangeInfoByCardNo(cardNo);
        QMapIterator<QDate,float> iterator(map);
        bool first = true;
        QDate date;
        while(iterator.hasNext()){
            iterator.next();
            if(first){
                if(isNewResided){
                    monthlyCost+=(iterator.key().day()-resideDate.day())*iterator.value();
                    insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-resideDate.day()),(iterator.key().day()-resideDate.day())*iterator.value(),QDate::currentDate().addMonths(-1));
                }
                else{
                    monthlyCost+=(iterator.key().day()-1)*iterator.value();
                    insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-1),(iterator.key().day()-1)*iterator.value(),QDate::currentDate().addMonths(-1));
                }
                first = false;
                date=iterator.key();
            }
            else{
                monthlyCost+=(iterator.key().day()-date.day())*iterator.value();
                insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-date.day()),(iterator.key().day()-date.day())*iterator.value(),QDate::currentDate().addMonths(-1));
                date=iterator.key();
            }
        }
        monthlyCost+=(QDate::currentDate().addMonths(-1).daysInMonth()-date.day())*bedCost;
        insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(QDate::currentDate().addMonths(-1).daysInMonth()-date.day()),(QDate::currentDate().addMonths(-1).daysInMonth()-date.day())*bedCost,QDate::currentDate().addMonths(-1));
    }
    else{
        if(isNewResided){
            monthlyCost = bedCost *(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1);
            insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1),bedCost *(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1),QDate::currentDate().addMonths(-1));
        }
        else{
            monthlyCost = bedCost * QDate::currentDate().addMonths(-1).daysInMonth();
            insertSpecialCostInfo(cardNo,1,tr("床位费%1*天数%2").arg(bedCost).arg(QDate::currentDate().addMonths(-1).daysInMonth()),bedCost * QDate::currentDate().addMonths(-1).daysInMonth(),QDate::currentDate().addMonths(-1));
        }
    }
        return monthlyCost;
}

float AutoSettle::getElderNurseCostByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate,levelChanged,nurseCost from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    int isChanged = 0;
    bool isNewResided = false;
    float nurseCost = 0;
    float monthlyCost = 0;
    QDate resideDate;
    if(query.first()){
        resideDate = query.value(0).toDate();
        isChanged = query.value(1).toInt();
        nurseCost = query.value(2).toFloat();
    }
    if(resideDate.year() == QDate::currentDate().addMonths(-1).year() && resideDate.month() == QDate::currentDate().addMonths(-1).month())
        isNewResided = true;
    if(isChanged){
        QMap<QDate,float> map = getElderNurseChangeInfoByCardNo(cardNo);
        QMapIterator<QDate,float> iterator(map);
        bool first = true;
        QDate date;
        while(iterator.hasNext()){
            iterator.next();
            if(first){
                if(isNewResided){
                    monthlyCost+=(iterator.key().day()-resideDate.day())*iterator.value();
                    insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-resideDate.day()),(iterator.key().day()-resideDate.day())*iterator.value(),QDate::currentDate().addMonths(-1));
                }
                else{
                    monthlyCost+=(iterator.key().day()-1)*iterator.value();
                    insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-1),(iterator.key().day()-1)*iterator.value(),QDate::currentDate().addMonths(-1));
                }
                first = false;
                date=iterator.key();
            }
            else{
                monthlyCost+=(iterator.key().day()-date.day())*iterator.value();
                insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(iterator.value()).arg(iterator.key().day()-date.day()),(iterator.key().day()-date.day())*iterator.value(),QDate::currentDate().addMonths(-1));
                date=iterator.key();
            }
        }
        monthlyCost+=(QDate::currentDate().addMonths(-1).daysInMonth()-date.day())*nurseCost;
        insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(nurseCost).arg(QDate::currentDate().addMonths(-1).daysInMonth()-date.day()),(QDate::currentDate().addMonths(-1).daysInMonth()-date.day())*nurseCost,QDate::currentDate().addMonths(-1));
    }
    else{
        if(isNewResided){
            monthlyCost = nurseCost *(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1);
            insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数%2").arg(nurseCost).arg(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1),nurseCost *(QDate::currentDate().addMonths(-1).daysInMonth() - resideDate.day() +1),QDate::currentDate().addMonths(-1));
        }
        else{
            monthlyCost = nurseCost * QDate::currentDate().addMonths(-1).daysInMonth();
            insertSpecialCostInfo(cardNo,2,tr("护理费%1*天数 %2").arg(nurseCost).arg(QDate::currentDate().addMonths(-1).daysInMonth()),nurseCost * QDate::currentDate().addMonths(-1).daysInMonth(),QDate::currentDate().addMonths(-1));
        }
    }
        return monthlyCost;
}

float AutoSettle::getElderSpecialServiceCostByCardNo(QString cardNo){
    int days = QDate::currentDate().addMonths(-1).daysInMonth();
    int year = QDate::currentDate().addMonths(-1).year();
    int month = QDate::currentDate().addMonths(-1).month();
    QSqlQuery query(globaldb);
    query.prepare("select serviceItem,cost,occurenceDate from living_record where item = 4 and cardNo = ? and occurenceDate >= ? and occurenceDate <= ?");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1));
    query.addBindValue(QDate(year,month,days));
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    float cost = 0;
    while(query.next()){
        insertSpecialCostInfo(cardNo,3,query.value(0).toString(),query.value(1).toFloat(),query.value(2).toDate());
        cost += query.value(1).toFloat();
    }
    return cost;
}

float AutoSettle::getElderStageCost(QString cardNo){
    int days = QDate::currentDate().addMonths(-1).daysInMonth();
    int year = QDate::currentDate().addMonths(-1).year();
    int month = QDate::currentDate().addMonths(-1).month();
    QDate resideDate = getElderResideDateByCardNo(cardNo);
    bool isNewResided = false;
    if(resideDate.year() == QDate::currentDate().addMonths(-1).year() && resideDate.month() == QDate::currentDate().addMonths(-1).month())
        isNewResided = true;
    QSqlQuery query(globaldb);
    query.prepare("select item,cost,startDate,endDate from expense_info where type = 5");
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QString item;
    float cost = 0;
    QDate startDate;
    QDate endDate;
    float monthlyCost = 0;
    while(query.next()){
        item = query.value(0).toString();
        cost = query.value(1).toFloat();
        startDate = query.value(2).toDate();
        endDate = query.value(3).toDate();
        if(isNewResided){
            if(startDate>QDate(year,month,days) || endDate<resideDate)
                continue;
            else if(startDate<resideDate && endDate>QDate(year,month,days)){
                monthlyCost += cost*(days-resideDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(days-resideDate.day()+1),cost*(days-resideDate.day()+1),QDate::currentDate().addMonths(-1));
            }
            else if(startDate>=resideDate && endDate <= QDate(year,month,days)){
                monthlyCost += cost*(endDate.day()-startDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-startDate.day()+1),cost*(endDate.day()-startDate.day()+1),QDate::currentDate().addMonths(-1));
            }
            else if(startDate<resideDate && endDate<=QDate(year,month,days)){
                monthlyCost += cost*(endDate.day()-resideDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-resideDate.day()+1),cost*(endDate.day()-resideDate.day()+1),QDate::currentDate().addMonths(-1));
            }
            else{
                monthlyCost += cost*(days-startDate.day() +1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg((days-startDate.day() +1)),cost*(days-startDate.day() +1),QDate::currentDate().addMonths(-1));
            }
        }
        else{
            if(startDate>QDate(year,month,days) || endDate<QDate(year,month,1))
                continue;
            else if(startDate<QDate(year,month,1) && endDate>QDate(year,month,days)){
                monthlyCost += cost*days;
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(days),cost*days,QDate::currentDate().addMonths(-1));
            }
            else if(startDate>=QDate(year,month,1) && endDate<=QDate(year,month,days)){
                monthlyCost += cost*(endDate.day()-startDate.day()+1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()-startDate.day()+1),cost*(endDate.day()-startDate.day()+1),QDate::currentDate().addMonths(-1));
            }
            else if(startDate<QDate(year,month,1) && endDate<=QDate(year,month,days)){
                monthlyCost += cost*endDate.day();
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg(endDate.day()),cost*endDate.day(),QDate::currentDate().addMonths(-1));
            }
            else{
                monthlyCost += cost*(days-startDate.day() +1);
                insertSpecialCostInfo(cardNo,4,tr("%1~%2:%3 每天 %4*天数%5").arg(startDate.toString("yyyy-MM-dd")).arg(endDate.toString("yyyy-MM-dd")).arg(item).arg(cost).arg((days-startDate.day() +1)),cost*(days-startDate.day() +1),QDate::currentDate().addMonths(-1));
            }
        }
    }
    return monthlyCost;
}

//获取护理变更次数
int AutoSettle::getElderNurseChangeTimesByCardNo(QString cardNo){
    int days = QDate::currentDate().addMonths(-1).daysInMonth();
    int year = QDate::currentDate().addMonths(-1).year();
    int month = QDate::currentDate().addMonths(-1).month();
    QSqlQuery query(globaldb);
    query.prepare("select count(*) from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ?");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1));
    query.addBindValue(QDate(year,month,days));
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    int times = 0;
    if(query.first())
        times = query.value(0).toInt();
    query.finish();
    query.clear();
    return times;
}

//获取具体的转床记录信息用于结算
QMap<QDate,float> AutoSettle::getElderBedChangeInfoByCardNo(QString cardNo){
    int days = QDate::currentDate().addMonths(-1).daysInMonth();
    int year = QDate::currentDate().addMonths(-1).year();
    int month = QDate::currentDate().addMonths(-1).month();
    QSqlQuery query(globaldb);
    query.prepare("select bedChangeDate,formerBedCost from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ? order by bedChangeDate asc");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1).toString("yyyy-MM-dd"));
    query.addBindValue(QDate(year,month,days).toString("yyyy-MM-dd"));
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QMap<QDate,float> map;
    while(query.next())
        map.insert(query.value(0).toDate(),query.value(1).toFloat());
    return map;
}

QMap<QDate,float> AutoSettle::getElderNurseChangeInfoByCardNo(QString cardNo){
    int days = QDate::currentDate().addMonths(-1).daysInMonth();
    int year = QDate::currentDate().addMonths(-1).year();
    int month = QDate::currentDate().addMonths(-1).month();
    QSqlQuery query(globaldb);
    query.prepare("select bedChangeDate,formerNurseCost from bed_change_record where cardNo = ? and bedChangeDate >= ? and bedChangeDate<= ? order by bedChangeDate asc");
    query.addBindValue(cardNo);
    query.addBindValue(QDate(year,month,1).toString("yyyy-MM-dd"));
    query.addBindValue(QDate(year,month,days).toString("yyyy-MM-dd"));
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QMap<QDate,float> map;
    while(query.next())
        map.insert(query.value(0).toDate(),query.value(1).toFloat());
    return map;
}

void AutoSettle::updateAccountByCardNoAndCost(QString cardNo, float cost){    
        QSqlQuery query(globaldb);
        query.prepare("insert into account_record (id,cardNo,accountOld,accountNew,remark,operator,operationTime) values(NULL,?,?,?,?,?,?)");
        query.addBindValue(cardNo);
        float account = getElderAccountByCardNo(cardNo);
        query.addBindValue(account);
        query.addBindValue(account - cost);
        query.addBindValue(tr("月费用结算，扣除费用%1").arg(cost));
        query.addBindValue(tr("system"));
        query.addBindValue(QDateTime::currentDateTime());
        query.exec();
        query.finish();
        query.prepare("update manage_info set account =account - ? where cardNo = ?");
        query.addBindValue(cost);
        query.addBindValue(cardNo);
        query.exec();
        if(query.lastError().isValid())
            qDebug()<<query.lastError();
        query.finish();
        query.clear();
}

void AutoSettle::updateLevelChangedByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("update manage_info set levelChanged = 0 where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    query.clear();
}

void AutoSettle::insertBedOrNurseCostInfo(QString cardNo, int type, QString item, float cost){
    QSqlQuery query(globaldb);
    query.prepare("insert into cost_detail (id,cardNo,costType,item,cost) values (NULL,?,?,?,?)");
    query.addBindValue(cardNo);
    query.addBindValue(type);
    query.addBindValue(item);
    query.addBindValue(cost);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
}

void AutoSettle::insertSpecialCostInfo(QString cardNo, int type, QString item, float cost, QDate date){
    QSqlQuery query(globaldb);
    query.prepare("insert into cost_detail (id,cardNo,costType,item,cost,costDate) values (NULL,?,?,?,?,?)");
    query.addBindValue(cardNo);
    query.addBindValue(type);
    query.addBindValue(item);
    query.addBindValue(cost);
    query.addBindValue(date);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    query.finish();
    query.clear();
}

QDate AutoSettle::getElderResideDateByCardNo(QString cardNo){
    QSqlQuery query(globaldb);
    query.prepare("select resideDate from manage_info where cardNo = ?");
    query.addBindValue(cardNo);
    query.exec();
    if(query.lastError().isValid())
        qDebug()<<query.lastError();
    QDate date;
    if(query.first())
        date = query.value(0).toDate();
    return date;
}
