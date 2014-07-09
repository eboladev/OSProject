#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTabWidget>
#include <QList>

class QTimer;
class TabInnerWidget;
class QPushButton;
class QListWidgetItem;

class HomePage;

class QDropEvent;
class QToolButton;
class RoomStateSearchDialog;

class TabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit TabWidget(QWidget *parent = 0);
    int tabheight;
    
signals:

public slots:

    void showHomePage();
    void closeCurrentPage();



protected:
    void resizeEvent(QResizeEvent * event);
private:





    HomePage * homepage;



};

#endif // TABWIDGET_H
