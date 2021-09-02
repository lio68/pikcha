
// ----------------------------------------
// Статические органы управления
// ----------------------------------------

#define STRICT
#include <windows.h>
#include <mem.h>
#include <tchar.h>


// Прототипы функций
BOOL InitApp(HINSTANCE);
LRESULT CALLBACK _export WndProc(HWND, UINT, WPARAM, LPARAM);

// Имя класса окна
TCHAR  szClassName[]   = "StaticAppClass";

TCHAR WinName[] =_T ("MainFrame");



// =======================================
// Функция WinMain
// =======================================
#pragma argsused

int PASCAL
WinMain(HINSTANCE hInstance, 
        HINSTANCE hPrevInstance,
        LPSTR     lpszCmdLine, 
        int       nCmdShow)   
{
  MSG  msg;   // структура для работы с сообщениями
  HWND hwnd;  // идентификатор главного окна приложения

  // Идентификаторы органов управления
  HWND hSt1, hSt2, hSt3, hSt4;

  // Инициализируем приложение
  if(!InitApp(hInstance))
      return FALSE;

  // После успешной инициализации приложения создаем
  // главное окнo приложения
  //
  hwnd = CreateWindow(
    szClassName,         // имя класса окна
    _T("Кот"),       // заголовок окна
    WS_OVERLAPPEDWINDOW, // стиль окна
    CW_USEDEFAULT,       // задаем размеры и расположение
    CW_USEDEFAULT,       // окна, принятые по умолчанию 
    CW_USEDEFAULT,
    CW_USEDEFAULT,
    0,                   // идентификатор родительского окна,
    0,                   // идентификатор меню
    hInstance,           // идентификатор приложения,
    NULL);               // указатель на дополнительные
                        // параметры
   // Если создать окно не удалось, завершаем приложeние
  if(!hwnd)
    return FALSE;

SetWindowTextW(hwnd, (LPCWSTR) L"Статические элементы" );//Устанавливает новый заголовок окна


  // Рисуем главное окно
  ShowWindow(hwnd, nCmdShow);
  UpdateWindow(hwnd);

  // Создаем четыре статических
  // органа управления
  hSt1 = CreateWindow("static", "The first namba",
    WS_CHILD | WS_VISIBLE | SS_BLACKRECT,
    20, 20, 180, 20,
    hwnd, (HMENU)-1, hInstance, NULL);

  hSt2 = CreateWindow("static", "oy",
    WS_CHILD | WS_VISIBLE | SS_BLACKFRAME,
    20, 50, 180, 20,
    hwnd, (HMENU)-1, hInstance, NULL);

  hSt3 = CreateWindow("static", "",
    WS_CHILD | WS_VISIBLE | SS_LEFT,
    20, 80, 180, 40,
    hwnd, (HMENU)-1, hInstance, NULL);

  hSt4 = CreateWindow("static", "Simple Control",
    WS_CHILD | WS_VISIBLE | SS_SIMPLE,
    20, 130, 180, 40,
    hwnd, (HMENU)-1, hInstance, NULL);

  // Выводим текст в окно, имеющее стиль SS_LEFT.
  // Этот текст будет выведен в режиме свертки слов
  SetWindowTextW(hSt3, (LPCWSTR) L"Этот текст будет выведен"
      " внутри окна в две строки");

  // Выводим текст в окно, имеющее стиль SS_SIMPLE.
  // Этот текст будет выведен на одной строке,
  // причем часть строки, которая выходит за границы
  // окна, будет обрезана
  SetWindowTextW(hSt4, (LPCWSTR) L"Этот текст будет выведен"
     " внутри окна в одну строку и обрезан");

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
    case WM_DESTROY:
    {
      PostQuitMessage(0);
      return 0;
    }
  }
  return DefWindowProc(hwnd, msg, wParam, lParam);
}
