#ifndef HOOK_H
#define HOOK_H

#include <QMessageBox>
#include <QDebug>
#include <windows.h>
#pragma comment(lib ,"user32.lib")
#pragma comment(lib, "advapi32.lib")
//��װ����,���øú�������װ����
void setHook();
//����ж�غ���,�Ա����
void unHook();


#endif // HOOK_H
