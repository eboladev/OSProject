#ifndef FULLSCREENMAINWINDOW_H
#define FULLSCREENMAINWINDOW_H

#include <QMainWindow>
class MainWindow;
class QSplashScreen;

class FullScreenMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit FullScreenMainWindow(QWidget *parent = 0);
    MainWindow * centralmainwindow;
    /*QSize sizeHint() const
    {
        return QSize(1,1);
    }*/

signals:
    
public slots:
    void otherOperation();
private:
    QToolBar * toolbar;
    QTimer * timer;
    QSplashScreen *splash;
};

#endif // FULLSCREENMAINWINDOW_H
