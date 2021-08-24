
// ----------------------------------------
// Управление стандартной кнопкой
// ----------------------------------------

#define STRICT
#include <windows.h>
#include <mem.h>

// Идентификаторы кнопок
#define IDB_Button1 1
#define IDB_Button2 2
#define IDB_Button3 3
#define IDB_Button4 4
#define IDB_Button5 5

// Прототипы функций
BOOL InitApp(HINSTANCE);
LRESULT CALLBACK _export WndProc(HWND, UINT, WPARAM, LPARAM);

// Имя класса окна
char const szClassName[]   = "ButtonCtlAppClass";

// Заголовок окна
char const szWindowTitle[] = "Button Control Demo";

// Идентификаторы кнопок
HWND hButton1, hButton2, hButton3, hButton4, hButton5;

// =====================================
// Функция WinMain
// =====================================
#pragma argsused

int PASCAL
WinMain(HINSTANCE hInstance, 
        HINSTANCE hPrevInstance,
        LPSTR     lpszCmdLine, 
        int       nCmdShow)   
{
  MSG  msg;   // структура для работы с сообщениями
  HWND hwnd;  // идентификатор главного окна приложения


  // Инициализируем приложение
  if(!InitApp(hInstance))
      return FALSE;

  // После успешной инициализации приложения создаем
  // главное окно приложения
  hwnd = CreateWindow(
    szClassName,         // имя класса окна
    szWindowTitle,       // заголовок окна
    WS_OVERLAPPEDWINDOW, // стиль окна
    CW_USEDEFAULT,       // задаем размеры и расположение
    CW_USEDEFAULT,       // окна, принятые по умолчанию 
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    0,                   // идентификатор родительского окна
    0,                   // идентификатор меню
    hInstance,           // идентификатор приложения
    NULL);               // указатель на дополнительные
                         // параметры
  // Если создать окно не удалось, завершаем приложение
  if(!hwnd)
    return FALSE;

  // Рисуем главное окно
  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // Создаем пять кнопок
  hButton1 = CreateWindow("button", "Button 1",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 20, 90, 30,
    hwnd, (HMENU) IDB_Button1, hInstance, NULL);

  hButton2 = CreateWindow("button", "Button 2",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 60, 90, 30, hwnd,
    (HMENU) IDB_Button2, hInstance, NULL);

  hButton3 = CreateWindow("button", "Button 3",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 100, 90, 30, hwnd,
    (HMENU) IDB_Button3, hInstance, NULL);

  hButton4 = CreateWindow("button", "Button 4",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 140, 90, 30, hwnd,
    (HMENU) IDB_Button4, hInstance, NULL);

  hButton5 = CreateWindow("button", "Button 5",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 180, 90, 30, hwnd,
    (HMENU) IDB_Button5, hInstance, NULL);

  // Увеличиваем горизонтальный размер
  // первой кнопки
  MoveWindow(hButton1, 20, 20, 180, 30, TRUE);

  // Изменяем надписи на остальных кнопках
  SetWindowText(hButton2, "PUSH");
  SetWindowText(hButton3, "POP");
  SetWindowText(hButton4, "OFF");
  SetWindowText(hButton5, "ON");

  // Запускаем цикл обработки сообщений
  while(GetMessage(&msg, 0, 0, 0))
  {
    DispatchMessage(&msg);
  }
  return msg.wParam;
}

// =====================================
// Функция InitApp
// Выполняет регистрацию класса окна
// =====================================

BOOL
InitApp(HINSTANCE hInstance)
{
  ATOM aWndClass; // атом для кода возврата
  WNDCLASS wc;    // структура для регистрации
                  // класса окна

  memset(&wc, 0, sizeof(wc));

  wc.style = 0;
  wc.lpfnWndProc = (WNDPROC) WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
  wc.lpszMenuName = (LPSTR)NULL;
  wc.lpszClassName = (LPSTR)szClassName;

  // Регистрация класса
  aWndClass = RegisterClass(&wc);

  return (aWndClass != 0);
}

// =====================================
// Функция WndProc
// =====================================

LRESULT CALLBACK _export
WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  switch (msg)
  {
    // Сообщение приходит, когда вы нажимаете
    // на одну из двух созданных кнопок
    case WM_COMMAND:
    {
      // Если нажата первая кнопка, выводим
      // сообщение
      if(wParam == IDB_Button1)
      {
          MessageBox(hwnd, "Нажата кнопка Button 1",
          "Message WM_COMMAND",MB_OK);
      }
      // Если нажата вторая кнопка,
      // переводим первую кнопку в нажатое состояние
      else if(wParam == IDB_Button2)
      {
        SendMessage(hButton1, BM_SETSTATE, TRUE, 0L);
      }
      // Если нажата третья кнопка,
      // возвращаем первую кнопку в исходное состояние
      else if(wParam == IDB_Button3)
      {
          SendMessage(hButton1, BM_SETSTATE, FALSE, 0L);
      }
      // Если нажата четвертая кнопка,
      // переводим первую кнопку в неактивное состояние
      else if(wParam == IDB_Button4)
      {
          EnableWindow(hButton1, FALSE);
      }
      // Если нажата пятая кнопка,
      // переводим первую кнопку в активное состояние
      else if(wParam == IDB_Button5)
      {
          EnableWindow(hButton1, TRUE);
      }
      return 0;
    }

    case WM_DESTROY:
    {
      PostQuitMessage(0);
      return 0;
    }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}
