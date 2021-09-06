#include <windows.h>

LRESULT CALLBACK MainWinProc(HWND,UINT,WPARAM,LPARAM);
#define ID_MYBUTTON 1    /* идентификатор для кнопки внутри главного окна */
#define ID_EDIT 2  /* идентификатор для edit  внутри главного окна */
 

int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hpi,LPSTR cmdline,int ss) {
 /* создаем и регистрируем класс главного окна */
 WNDCLASS wc;
 wc.style=0;
 wc.lpfnWndProc=MainWinProc;
 wc.cbClsExtra=wc.cbWndExtra=0;
 wc.hInstance=hInst;
 wc.hIcon=NULL;
 wc.hCursor=NULL;
 wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+2);
 wc.lpszMenuName=NULL;
 wc.lpszClassName="Example 4 MainWnd Class";
 if (!RegisterClass(&wc)) return FALSE;



 /* создаем главное окно и отображаем его */
 HWND hMainWnd=CreateWindow("Example 4 MainWnd Class","EXAMPLE 4",WS_OVERLAPPEDWINDOW,
  CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,NULL,NULL,hInst,NULL);
 if (!hMainWnd) return FALSE;
 ShowWindow(hMainWnd,ss);
 UpdateWindow(hMainWnd);

 MSG msg; /* цикл обработки событий */
 while (GetMessage(&msg,NULL,0,0)) {
  TranslateMessage(&msg); 
  DispatchMessage(&msg); 
 } 
 return msg.wParam; 
}

/* процедура обработки сообщений для главного окна */
LRESULT CALLBACK MainWinProc(HWND hw,UINT msg,WPARAM wp,LPARAM lp) {
 switch (msg) {
  case WM_CREATE:
   /* при создании окна внедряем в него кнопочку */
   CreateWindow("button","My button",WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
    5,5,100,20,hw,(HMENU)ID_MYBUTTON,NULL,NULL);
   /* стиль WS_CHILD означает, что это дочернее окно и для него
    вместо дескриптора меню будет передан целочисленный идентификатор,
    который будет использоваться дочерним окном для оповещения 
    родительского окна через WM_COMMAND */


       // Создаем редактор текста
	
      CreateWindow("edit", NULL,
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         30, 30, 300, 30,
         hw, (HMENU) ID_EDIT, NULL, NULL);

   return 0;

// Когда главное окно приложения получает
    // фокус ввода, отдаем фокус редактору текста
    case WM_SETFOCUS:
    {
    //  SetFocus(hEdit);
      return 0;
    }

  case WM_COMMAND:
   /* нажата наша кнопочка? */
   if ((HIWORD(wp)==0) && (LOWORD(wp)==ID_MYBUTTON)) 
    MessageBox(hw,"You pressed my button","MessageBox",MB_OK|MB_ICONWARNING);
   return 0;
  case WM_DESTROY:
   /* пользователь закрыл окно, программа может завершаться */
   PostQuitMessage(0);
   return 0;
 }
 return DefWindowProc(hw,msg,wp,lp);
}
