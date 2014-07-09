#ifndef HOOK_H
#define HOOK_H

#include <QMessageBox>
#include <QDebug>
#include <windows.h>
#pragma comment(lib ,"user32.lib")
#pragma comment(lib, "advapi32.lib")
//安装钩子,调用该函数即安装钩子
void setHook();
//声明卸载函数,以便调用
void unHook();


#endif // HOOK_H
