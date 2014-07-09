#ifndef REFRESHANALOGATTRIOBJECT_H
#define REFRESHANALOGATTRIOBJECT_H

#include <QObject>
#include <QWidget>
class MainWindow;
class RefreshAnalogAttriObject : public QObject
{
    Q_OBJECT
public:
    explicit RefreshAnalogAttriObject(QWidget *parent = 0);
    void setAppEnable(bool flag);
    
signals:
    void refreshArgs();
    
public slots:
private:
    MainWindow * parentwid;
    
};

#endif // REFRESHANALOGATTRIOBJECT_H
