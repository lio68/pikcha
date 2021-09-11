#include <windows.h>

// объявление функций
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);

////////////////////////////////////////////////////////////////////////// 
// функция вхождений программы WinMain
int APIENTRY WinMain(HINSTANCE hInstance,
             HINSTANCE         hPrevInstance,
             LPSTR             lpCmdLine,
             int               nCmdShow)
{

  // имя будущего класса
  LPCTSTR lpzClass = TEXT("My Window Class!");

  // регистрация класса
  if (!RegMyWindowClass(hInstance, lpzClass))
    return 1;

  // вычисление координат центра экрана
  RECT screen_rect;
  GetWindowRect(GetDesktopWindow(),&screen_rect); // разрешение экрана
  int x = screen_rect.right / 2 - 450;
  int y = screen_rect.bottom / 2 - 430;

  // создание диалогового окна
  HWND hWnd = CreateWindow(lpzClass, TEXT("Dialog Window"), 
    WS_OVERLAPPEDWINDOW | WS_VISIBLE, x, y, 900, 600, NULL, NULL, 
    hInstance, NULL);

  // если окно не создано, описатель будет равен 0
  if(!hWnd) return 2; 

  // цикл сообщений приложения
  MSG msg = {0};    // структура сообщения
  int iGetOk = 0;   // переменная состояния
  while ((iGetOk = GetMessage(&msg, NULL, 0, 0 )) != 0) // цикл сообщений
  {
    if (iGetOk == -1) return 3;  // если GetMessage вернул ошибку - выход
    TranslateMessage(&msg);    
    DispatchMessage(&msg);
  }

  return msg.wParam;  // возвращаем код завершения программы
}

////////////////////////////////////////////////////////////////////////// 
// функция регистрации класса окон
ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName)
{
  WNDCLASS wcWindowClass = {0};
  // адрес ф-ции обработки сообщений
  wcWindowClass.lpfnWndProc = (WNDPROC)WndProc;
  // стиль окна
  wcWindowClass.style = CS_HREDRAW|CS_VREDRAW;
  // дискриптор экземпляра приложения
  wcWindowClass.hInstance = hInst;
  // название класса
  wcWindowClass.lpszClassName = lpzClassName;
  // загрузка курсора
  wcWindowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
  // загрузка цвета окон
  wcWindowClass.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
  return RegisterClass(&wcWindowClass); // регистрация класса
}

////////////////////////////////////////////////////////////////////////// 
// функция обработки сообщений
LRESULT CALLBACK WndProc(
  HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  // выборка и обработка сообщений
  switch (message)
  {
  case WM_LBUTTONUP:
     // реакция на сообщение
    MessageBox(hWnd, TEXT(" Вы кликнули!"), TEXT("событие"), 0);
    break;
  case WM_DESTROY:
    PostQuitMessage(0);  // реакция на сообщение
    break;
  default:  
    // все сообщения не обработанные Вами обработает сама Windows
    return DefWindowProc(hWnd, message, wParam, lParam);
  }
  return 0;
}
