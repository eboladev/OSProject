#ifndef DRAGDROPWIDGET_H
#define DRAGDROPWIDGET_H
#include<QDockWidget>
#include<QListWidget>
#include<QLabel>
class DragDropWidget:public QDockWidget
{
    Q_OBJECT
public:
    explicit DragDropWidget(const QString &title, QWidget *parent = 0);
    QListWidget* drags;
    QLabel* garbage;
signals:
private:
};

#endif // DRAGDROPWIDGET_H
