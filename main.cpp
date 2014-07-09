#include "mainwindow.h"
#include <QtGui/QApplication>
#include <QtCore/QTextCodec>
#include <QtCore/QtDebug>
#include <QWidget>
#include <QMessageBox>
#include <QMainWindow>
#include <QDockWidget>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlError>
#include <QTranslator>
#include <QProcess>
#include "fullscreenmainwindow.h"
#include "alarmdealwithconfirmdialog.h"
#include "struct.h"
#include "tabwidget.h"
#include "hook.h"
#include "dictionary.h"
#include "logindialog.h"

QString serverIP;
QString globalDBName;
QSqlDatabase globaldb;
QString globalUserName;
bool dbisconnected;
bool serverisrunning;

bool connectToGloabalDatabase()
{    
    globaldb = QSqlDatabase::addDatabase("QMYSQL","globaldatabase");
    globaldb.setHostName(serverIP);
    globaldb.setUserName(globalUserName);
    globaldb.setPort(3306);
    globaldb.setPassword(globalUserName);
    globaldb.setDatabaseName(globalDBName);
    if(!globaldb.open())
    {
        qDebug()<<"globaldbconnect failed";
        dbisconnected = false;
        //raao->setAppEnable(false);        
        return false;
    }
    else
    {
        qDebug()<<"globaldbconnect succeed";      
        dbisconnected = true;
        return true;
    }
}

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");
    dbisconnected = false;
    serverisrunning = false;
//    serverIP = "localhost";
    globalUserName = QObject::tr("zsn");
    serverIP = "192.168.1.100";
    globalDBName = "elder";
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("System"));
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("GB-18030"));
    QTranslator trans;
    trans.load("qt_zh_CN.qm");
    QApplication app(argc, argv);
    app.installTranslator(&trans);

    QSqlDatabase::removeDatabase("globaldatabase");
    if(!connectToGloabalDatabase())
    {
        QMessageBox::warning(0,"警告","数据库连接失败，程序无法运行!","确定");
        return -1;
    } 
//    setHook();
//    AlarmDealWithConfirmDialog awcd;
//    awcd.setState(LOGGIN);
//    if(awcd.exec() == awcd.Accepted)
//    {
//        insertLog("登陆系统");
//        FullScreenMainWindow w;
//         int ret = app.exec();
//         if (ret == 773)
//         {
//             QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//             return 0;
//         }
//         return ret;
//    }
//    else
//    {
//        app.exit(0);
//        return 0;
//    }
   //不要忘记把这里补上
    LoginDialog loginDialog;
    if(loginDialog.exec() == loginDialog.Accepted)
    {
        insertLog("登陆系统");
        FullScreenMainWindow w;
         int ret = app.exec();
         if (ret == 773)
         {
             QProcess::startDetached(qApp->applicationFilePath(), QStringList());
             return 0;
         }
         return ret;
    }
    else
    {
        app.exit(0);
        return 0;
    }


//   FullScreenMainWindow w;
//    int ret = app.exec();
//    if (ret == 773)
//    {
//        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
//        return 0;
//    }
//    return ret;
}
