#include <windows.h>

/*        Стартова функция API32

 * hInst - дескриптор для данного экземпляра программы
 * hpi - в Win32 не используется (всегда NULL)
 * cmdline - командная строка
 * ss - код состояния главного окна */

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hpi,LPSTR cmdline,int ss) {
         MessageBox(NULL,"Hello, World!","Test",MB_OK);
             return 0;
       }
