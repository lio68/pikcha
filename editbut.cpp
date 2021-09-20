// ----------------------------------------
// Редактор текста
// ----------------------------------------


#include <windows.h>
#include <mem.h>
#include <tchar.h>
#include <iostream>



// Идентификатор редактора текста
#define ID_EDIT   1

#define ID_EDIT2  2 

// Идентификатор кнопки
#define ID_BUTTON 3

using namespace std;

// Прототипы функций
BOOL InitApp(HINSTANCE);
LRESULT CALLBACK  WndProc(HWND, UINT, WPARAM, LPARAM);

// Имя класса окна
char const szClassName[]   = "EditAppClass";

// Заголовок окна
char const szWindowTitle[] = "Edit Demo";

// Идентификатор копии приложения
HINSTANCE hInst;

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

  // Сохраняем идентификатор копии приложения
  // в глобальной переменной
  hInst = hInstance;

  // После успешной инициализации приложения создаем
  // главное окно приложения
  hwnd = CreateWindow(
    szClassName,         // имя класса окна
    szWindowTitle,       // заголовок окна
    WS_OVERLAPPEDWINDOW, // стиль окна
    CW_USEDEFAULT,       // задаем расположение и размеры
    CW_USEDEFAULT,       // окна, принятые по умолчанию
    CW_USEDEFAULT,       // 
    CW_USEDEFAULT,       // 
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

  // Запускаем цикл обработки сообщений
  while(GetMessage(&msg, 0, 0, 0))
  {
    // Создаем символьные сообщения 
    TranslateMessage(&msg);
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
  wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 6);
  wc.lpszMenuName = (LPSTR)NULL;
  wc.lpszClassName = (LPSTR)szClassName;

  // Регистрация класса
  aWndClass = RegisterClass(&wc);

  return (aWndClass != 0);
}

// =====================================
// Функция WndProc
// =====================================

LRESULT CALLBACK 
WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  // Идентификатор редактора текста
  static HWND hEdit;

  static HWND hEdit2;


  // Идентификатор кнопки
  static HWND hButton;

  //Идентификатор статического элемента
  static HWND hSt1 , hSt2;

  switch (msg)
  {
    case WM_CREATE:
    {
      // Создаем редактор текста
      hEdit = CreateWindow("edit", NULL,
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         200, 30, 300, 30,
         hwnd, (HMENU) ID_EDIT, hInst, NULL);

       hEdit2 = CreateWindow("edit", "hEdit2",
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         200, 70, 300, 30,
         hwnd, (HMENU) ID_EDIT2, hInst, NULL);


      // Создаем кнопку
      hButton = CreateWindow("button", "OK",
         WS_CHILD | WS_VISIBLE |
         BS_PUSHBUTTON,
         30, 80, 100, 30,
         hwnd, (HMENU) ID_BUTTON, hInst, NULL);

	  //Создаём статические элементы hSt1 , hSt2
     hSt1 = CreateWindow("static", "Input Text this hEdit: ",
         WS_CHILD | WS_VISIBLE | SS_CENTER , //| WS_BORDER , //| SS_BLACKRECT,
        30, 30, 150, 30,
         hwnd, (HMENU)-1, hInst, NULL);

     hSt2 = CreateWindow("static", "..... ",
         WS_CHILD | WS_VISIBLE | SS_CENTER , //| WS_BORDER , //| SS_BLACKRECT,
        200, 110, 150, 30,
         hwnd, (HMENU)-1, hInst, NULL);


      return 0;
    }

    // Когда главное окно приложения получает
    // фокус ввода, отдаем фокус редактору текста
    case WM_SETFOCUS:
    {
      SetFocus(hEdit);
      return 0;
    }

    case WM_COMMAND:
    {
      // Обработка извещения текстового редактора
      // об ошибке
      if(wParam == ID_EDIT)
      {
        if(HIWORD(lParam) == EN_ERRSPACE)
        {
          MessageBox(hwnd, "Мало памяти",
           szWindowTitle, MB_OK);
        }
      }

      // Сообщение от кнопки
      else if(wParam == ID_BUTTON)
      {
        /*// Способ №1 по передаче данных из edit
		 
		   LPSTR chBuff[100];        

         // Записываем в первое слово буфера
         // значение размера буфера в байтах
         * (WORD *) chBuff = sizeof (chBuff) - 1;
	

         //  Получаем от редактора текста содержимое
         // первой строки. Функция возвращает количество
         // байт, скопированных в буфер
         SendMessage(hEdit, EM_GETLINE, 0, (LPARAM) chBuff);
         
         // Выводим содержимое буфера в статический элемент hSt2 и окно	

         SetWindowTextA( hSt2,(LPSTR) chBuff);

         SetWindowTextA( hwnd,(LPSTR) chBuff);

         SetWindowTextA( hEdit2,(LPSTR) chBuff); 

         SetWindowTextA( hEdit,0); // устанавливаем "0" в hEdit


         MessageBox(hwnd, (LPSTR)chBuff, szWindowTitle, MB_OK );*/


		  //Способ №2 по передачи данных из edit
		 
             int cTextLength;   //длина текста

        cTextLength = GetWindowTextLength(hEdit);//получить длину текста

        wchar_t * textS = new wchar_t[cTextLength + 1];//динамический выделяет буфер


 //получение текста из edit и сохранение его в буферной переменной textS

 GetWindowTextW(hEdit, textS, cTextLength + 1);


 //вывод текста в сообщение MessageBox
 MessageBoxW(hwnd,(LPCWSTR) textS, textS, MB_OKCANCEL | MB_ICONEXCLAMATION);

//вывод текста в hSt2 
SetWindowTextW( hSt2,(LPCWSTR) textS);

//вывод текста в hEdit2 
SetWindowTextW( hEdit2,(LPCWSTR) textS);

//Устанавливаем пустую строку в hEdit
SetWindowTextW( hEdit,0);


 delete[] textS;// освободить выделенную памят

	  }
      return 0;
    }

    case WM_PAINT:
 {
      HDC hdc;
      PAINTSTRUCT ps;

      // Получаем индекс контекста устройства
      hdc = BeginPaint(hwnd, &ps);

     //здесь можно вставить какие-нибудь функции рисования:

   // SetЕTextColor( hdc,red );  
      TextOutW(hdc, 30, 10,L" Convoy",8);//выводим текст      
    Ellipse(hdc,40,150,200,300);//рисуем элипс
      Rectangle(hdc, 400, 150, 200, 300);//рисуем прямоугольник
   // MoveTo(hdc,120,80);//установка начальной позиции пера
      LineTo( hdc,450,300);//рисуем линию
     

      // Отдаем индекс контекста устройства			
      EndPaint(hwnd, &ps);
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
