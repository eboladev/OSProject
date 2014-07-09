//���ÿ�ݼ�
#include "hook.h"

HHOOK keyHook=NULL;
HHOOK mouseHook=NULL;

//���̹��ӹ���





LRESULT CALLBACK LowLevelKeyboardProc(int nCode,// hook code
                                       WPARAM wParam,// message identifier
                                       LPARAM lParam )  // message data
{
        PKBDLLHOOKSTRUCT pm = NULL;
        if (nCode == HC_ACTION)
        {
                pm = (PKBDLLHOOKSTRUCT)lParam;
                switch(pm->vkCode)
                {
                        //����win��
                case VK_LWIN:
                case VK_RWIN:
                        return 1;
                        break;

                        //����alt+tab
                case VK_TAB:
                        if(pm->flags & LLKHF_ALTDOWN)
                                return 1;
                        break;
                        //����esc  alt+esc  ctrl+esc
                case VK_ESCAPE:
                                return 1;
                        break;
                         //����ALT+F4
                case VK_F4:
                        if(pm->flags & LLKHF_ALTDOWN)
                                return 1;
                        break;
                         //����F1
                case VK_F1:
                        return 1;
                        break;
                         //����CTRL+ALT+DEL
                case VK_DELETE:
//                        if((pm->flags & LLKHF_ALTDOWN) && (GetKeyState(VK_CONTROL)  &  0x8000))
                    if((pm->flags & LLKHF_ALTDOWN))

                        {
                                return 1;
                        }
                        break;
                case VK_CONTROL:
                    if((pm->flags & LLKHF_ALTDOWN) && (GetKeyState(VK_DELETE) & 0x8000))
                    {
                        qDebug()<<"test";
                        return 1;
                    }
                    break;
                default:
                    break;
                }
        }
        return CallNextHookEx(NULL,nCode,wParam,lParam);
}

void unHook()
{
    UnhookWindowsHookEx(keyHook);
}
//��װ����,���øú�������װ����
void setHook()
{
    keyHook =SetWindowsHookEx( WH_KEYBOARD_LL,LowLevelKeyboardProc,GetModuleHandle(NULL),0);
}
