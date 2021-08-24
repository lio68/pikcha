#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define _WIN32_WINNT_WiN7 0x0601 //для win7

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR WinName[] = _T("MainFrame");

   int APIENTRY _tWinMain(HINSTANCE This, // Дескриптор текущего приложения
                          HINSTANCE Prev, // В современных системах всегда 0
                              LPTSTR cmd, // Командная строка
                                int mode)//nCmdShow)//mode) // Режим отображения окна

    {  HWND hWnd; // Дескриптор главного окна программы
         MSG msg; // Структура для хранения сообщения
     WNDCLASS wc; // Класс окна

        // Определение класса окна

        wc.hInstance = This;
        wc.lpszClassName = WinName; // Имя класса окна
        wc.lpfnWndProc = WndProc; // Функция окна
        wc.style = CS_HREDRAW | CS_VREDRAW; // Стиль окна
        wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Стандартная иконка
        wc.hCursor = LoadCursor(NULL,IDC_ARROW); // Стандартный курсор
        wc.lpszMenuName = NULL; // Нет меню
        wc.cbClsExtra = 0; // Нет дополнительных данных класса
        wc.cbWndExtra = 0; // Нет дополнительных данных окна
        wc.hbrBackground = (HBRUSH)(COLOR_WINDOW-2); // Заполнение окна голубым цветом

   if(!RegisterClass(&wc)) return 0; // Регистрация класса окна

// Создание окна1
 HWND hWnd1 = CreateWindow(WinName, // Имя класса окна
_T("Ostav One Windows-divice"), // Заголовок окна
WS_OVERLAPPEDWINDOW, // Стиль окна
 300,     //CW_USEDEFAULT, // x
 100,     //CW_USEDEFAULT, // y Размеры окна
 400,     //CW_USEDEFAULT, // Width
 400,     //CW_USEDEFAULT, // Height
HWND_DESKTOP, // Дескриптор родительского окна
NULL, // Нет меню
This, // Дескриптор приложения
NULL); // Дополнительной информации нет

ShowWindow(hWnd1, mode); //Показать окно

UpdateWindow(hWnd1);

// Создание окна 2
 HWND  hWnd2 = CreateWindow(WinName, // Имя класса окна
_T("Ostav 2 Windows-divice"), // Заголовок окна
WS_OVERLAPPEDWINDOW, // Стиль окна
100,    //CW_USEDEFAULT, // x
100,    //CW_USEDEFAULT, // y Размеры окна
500,    //CW_USEDEFAULT, // Width
500,    //CW_USEDEFAULT, // Height
HWND_DESKTOP, // Дескриптор родительского окна
NULL, // Нет меню
This, // Дескриптор приложения
NULL); // Дополнительной информации нет

ShowWindow(hWnd2, mode); //Показать окно

UpdateWindow(hWnd2);


HDC hDC = GetDC(hWnd2);               // получение контекста устройства
//Rectangle(hDC, 50, 50, 200, 200);    // рисование прямоугольника
//TextOut(hDC, 5, 5, L"Hello!!!", 9); // вывод текста
ReleaseDC(hWnd2, hDC);                // освобождение контекста устройства



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
{ // Обработчик сообщений
switch(message)
{
case WM_DESTROY : PostQuitMessage(0);
break; // Завершение программы
// Обработка сообщения по умолчанию
default : return DefWindowProc(hWnd, message, wParam, lParam);
}
return 0;
}


