#ifndef PLOTTER_H
#define PLOTTER_H

#include <QMap>
#include <QPixmap>
#include <QVector>
#include <QWidget>
#include "struct.h"
#include "widget.h"

class QToolButton;
class PlotSettings;
class QScrollBar;
class QPushButton;
class QLabel;
class QLineEdit;


class Plotter : public Widget
{
    Q_OBJECT

public:
    Plotter(QWidget *parent = 0);
    void loadArgs(QString filename);
    void launch();
    void setPlotSettings(int i, const PlotSettings &settings);
    void creatPlotSettings();
    void setCurveData(int id, const QList<QPointF> &data);
    void clearCurve(int id);
   // QSize minimumSizeHint() const;
    //QSize sizeHint() const;
    void setControlState(int type);
signals:
   // void raiseAllButton();
    void delMySelf(QString);

public slots:
   // void zoomIn();
   // void zoomOut();
    void upCurve0();
    void downCurve0();
    void upCurve1();
    void downCurve1();
    void upCurve2();
    void downCurve2();
    void upCurve3();
    void downCurve3();
    void upCurve4();
    void downCurve4();
    //void updateTimeDone();
   // void startAndStopTimer();
    void leftPage();
    void rightPage();
    void onValueChanged(int value);
   // void minimumAndMaxmum();
    void refreshPlotter();
    void updateData();

     void closeMySelf();
     void reloadArgs();

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void wheelEvent(QWheelEvent *event);


private:
    void updateRubberBandRegion();
    void refreshPixmap();
    void drawGrid(QPainter *painter);
    void drawCurves(QPainter *painter);
    void createUpAnddown_buttons();
    //QTimer * refreshtime;
    QTimer * updatedatatimer;
    enum { LEFTMARGIN = 70,RIGHTMARGIN = 50,TOPMARGIN = 100,
           BOTTUMMARGIN = 100,SCALESPACE = 50,MAXCURVENUM = 5,
         ILLSTRATEWIDTH = 250,ILLSTRATEHEIGHT = 15,LINELEN = 40};
   //TOPMARGIN = 60

    //QToolButton *zoomin_button;
    //QToolButton *zoomout_button;
    QToolButton *leftpage_button;
    QToolButton *rightpage_button;
    //QPushButton *startandstop_button;
   // QToolButton * minmumandmaxmum_button;
    QMap<int, QList<QPointF> > curvemap;
    QVector<QString> datatimevec;
    QMap<int,SingleArgAlarmAndRange> argattris;
    QStringList roomnames;
    QStringList argnames;
   // QVector<PlotSettings> zoomStack;
    QVector< QVector<PlotSettings> *> settingsstack;
    QVector<QToolButton *> up_buttons;
    QVector<QToolButton *> down_buttons;
    QVector<QLineEdit *> realtimevalues;
    QVector<QLineEdit * > historyvalues;
    QLabel * realtimevaluehint;
    QLabel * historyvaluehint;
    int hisx;

    int curzoom;
    bool rubberbandisshown;
    QRect rubberbandrect;
    QPixmap pixmap;
    int numcurve;
    QScrollBar * scrollbar;

    bool isstop;
    int olderscrollvalue;
    //QCursor lastcur;

   // bool ismax;
   // QRect geometryandsize;

    static const QColor colorforids[5];

    enum OpenType{NEW,OPEN,EDIT};
    int opentype;

    int timescalecount;
    QString filename;



};
#endif
