#ifndef AUTOSETTLE_H
#define AUTOSETTLE_H

#include <QObject>
#include<QDate>
#include<QMap>
#include<QStringList>
class AutoSettle : public QObject
{
    Q_OBJECT
public:
    explicit AutoSettle(QObject *parent = 0);
    
signals:
    
public slots:
    void expenseSettle();
    QStringList getElderCardNoList();
    float getElderAccountByCardNo(QString);
    float getElderBedCostByCardNo(QString);
    float getElderNurseCostByCardNo(QString);
    float getElderStageCost(QString);
    float getElderSpecialServiceCostByCardNo(QString);
    int getElderNurseChangeTimesByCardNo(QString);
    QMap<QDate,float> getElderBedChangeInfoByCardNo(QString);
    QMap<QDate,float> getElderNurseChangeInfoByCardNo(QString);
    void updateAccountByCardNoAndCost(QString,float);
    void updateLevelChangedByCardNo(QString);
    void insertBedOrNurseCostInfo(QString,int,QString,float);
    void insertSpecialCostInfo(QString,int,QString,float,QDate);
    QDate getElderResideDateByCardNo(QString);
};

#endif // AUTOSETTLE_H
