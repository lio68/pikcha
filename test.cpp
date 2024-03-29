#define STRICT
//#define UNICODE
#include <windows.h>
#include <tchar.h>
#include <mem.h>
#define IDB_Button1 1 // Идентификатор кнопки Button1
#define IDB_Button2 2 // Идентификатор кнопки Buttton2
#define IDB_Button3 3 // Идентификатор кнопки Buttton2
#define IDB_Button4 4 // Идентификатор кнопки Buttton2
#define IDB_Button5 5 // Идентификатор кнопки Buttton2
#define IDB_Button6 6 // Идентификатор кнопки Buttton2

#define ID_EDIT1 1   // Идентификатор редактора текста
#define ID_EDIT2 2   // Идентификатор редактора текста




LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");
int APIENTRY _tWinMain(HINSTANCE This, // Дескриптор текущего приложения
HINSTANCE Prev,// В современных системах всегда 0
LPTSTR cmd,// Командная строка
int mode)// Режим отображения окна
{
     HWND hWnd;// Дескриптор главного окна программы

     HWND hSt1, hSt2, hSt3, hSt4; // Идентификаторы органов управления
	                              // статических элементов





MSG msg;
// Структура для хранения сообщения
WNDCLASS wc; // Класс окна
// Определение класса окна
wc.hInstance = This;
wc.lpszClassName = WinName;
wc.lpfnWndProc = WndProc;
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor = LoadCursor(NULL,IDC_ARROW); // Стандартный курсор
wc.lpszMenuName = NULL;
// Нет меню
wc.cbClsExtra = 0;
// Нет дополнительных данных класса
wc.cbWndExtra = 0;
// Нет дополнительных данных окна
// Заполнение окна белым цветом
wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
if(!RegisterClass(&wc)) return 0; // Регистрация класса окна
// Создание окна
hWnd = CreateWindow(WinName,// Имя класса окна
_T("Каркас Windows-приложения"), // Заголовок окна
WS_OVERLAPPEDWINDOW,
// Стиль окна
CW_USEDEFAULT, // x
CW_USEDEFAULT, // y Размеры окна
CW_USEDEFAULT, // Width 

CW_USEDEFAULT, // Height
HWND_DESKTOP, // Дескриптор родительского окна
NULL,
// Нет меню
This,
// Дескриптор приложения
NULL);

 SetWindowTextW(hWnd, (LPCWSTR) L"Окно для рисования" );//Устанавливает новый заголовок окна


// Дополнительной информации нет
ShowWindow(hWnd, mode); //Показать окно
// Цикл обработки сообщений
while(GetMessage(&msg, NULL, 0, 0))
{
TranslateMessage(&msg);// Функция трансляции кодов нажатой клавиши
DispatchMessage(&msg); // Посылает сообщение функции WndProc()
}
return 0;
}
// Оконная функция вызывается операционной системой
// и получает сообщения из очереди для данного приложения
LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam)
{
// Обработчик сообщений
switch(message)
{
case WM_DESTROY : PostQuitMessage(0);
break; // Завершение программы
// Обработка сообщения по умолчанию
default : return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}
