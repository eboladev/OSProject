#ifndef PIEWIDGET_H
#define PIEWIDGET_H

#include <QWidget>

class QLabel;
class PieWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieWidget(QString piename,int diameter,bool isparent , QWidget *parent = 0);
    void updateData(int normalcount,int firstalarmcount,int secondalarmcount,int offlinecount);
protected:
    virtual void paintEvent(QPaintEvent *event);
signals:
    
public slots:
private:
    //QLabel * namelabel;
    QString name;
    int diameter;
    bool isparent;
    QVector<int> statecounts;
    enum {HORIZONSPACE = 20,VERTICALSPACE = 10,STATENUM = 4,STATEHINTHEIGHT = 20,STATEHINTVERSPACE = 5};
    static const QColor statecolors[4];
    QStringList statename;
    
};

#endif // PIEWIDGET_H
