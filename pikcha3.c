#include <windows.h>
#define IDB_Button1 1 // Идентификатор кнопки Button1
#define IDB_Button2 2 // Идентификатор кнопки Buttton2
#define ID_EDIT 1   // Идентификатор редактора текста


LRESULT _stdcall WndProc(HWND hWnd, UINT massege, WPARAM wParam, LPARAM IParam);

int _stdcall WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS wc;
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)( COLOR_WINDOW-2);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "classic";
	RegisterClass(&wc);

///////////////////////////////////////////////////////////////

           HWND hButton1, hButton2;//Индентификаторы кнопок	

	       HWND hEdit1;//Идентификатор №1 редактора текста

           HWND hEdit2;//Идентификатор №2 редактора текста

           HWND hEdit3;//Идентификатор №3 редактора текста

///////////////////////////////////////////////////////////////
	  

      //Индефикаторы окон , создаём окна
	HWND hWnd1 = CreateWindow("classic", "GDI", WS_OVERLAPPEDWINDOW, 200, 200, 400, 400, NULL, NULL, hInstance, NULL);
	HWND hWnd2 = CreateWindow("classic", "GDI2", WS_OVERLAPPEDWINDOW, 610, 200, 400, 400, NULL, NULL, hInstance, NULL);

	//Показываем окно 1 с индефикатором hWnd1
	ShowWindow(hWnd1, nCmdShow);
	UpdateWindow(hWnd1);

	   // Создаем первую кнопку
  hButton1 = CreateWindow(
  "button", // название класса для кнопок "button"
  "Button 1",// надпись на кнопки
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,// стиль кнопки как комбинацию констант  
    20, 160,// координаты от левого верхнего угла
    150, 40,// ширина высота
    hWnd1,// Индефикатор окна в котором создаём кнопку
    (HMENU) IDB_Button1, //произвольное название индефикатора класса кнопки
    hInstance,//wc.hInstance = hInstance
	NULL); // для кнопки всегда ноль

    ShowWindow(hWnd2, nCmdShow);
	UpdateWindow(hWnd2);
	MSG msg;

	  // Создаем вторую кнопку
  hButton2 = CreateWindow("button", "Button 2",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 20,
    150, 60,
    hWnd2,
    (HMENU) IDB_Button2,
    hInstance, NULL);

/////////////////////////////////////////////////////////////

// Создаем редактор текста №1  в окне с id  hWnd1
      hEdit1 = CreateWindow("edit", NULL,
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         20, 20, 100, 30,
         hWnd1, (HMENU) ID_EDIT, hInstance, NULL);

  // Создаем редактор текста №2  в окне с id  hWnd1
      hEdit2 = CreateWindow("edit", NULL,
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         20, 70, 100, 30,
         hWnd1, (HMENU) ID_EDIT, hInstance, NULL);

 // Создаем редактор текста №3  в окне с id  hWnd1
      hEdit3 = CreateWindow("edit", NULL,
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         20, 120, 100, 30,
         hWnd1, (HMENU) ID_EDIT, hInstance, NULL);

/////////////////////////////////////////////////////////////


	while (1)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//hDC = GetDC(hWnd2);
		//Rectangle(hDC, 50, 50, 100, 100);
		//TextOut(hDC, 5, 5, "Второе окно!!!", 14);
		//ReleaseDC(hWnd2, hDC);
	

	return 0;
}

LRESULT _stdcall WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
}
