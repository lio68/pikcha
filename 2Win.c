#include <windows.h>
#define UNICODE
#define IDB_Button1 1 // Идентификатор кнопки Button1
#define IDB_Button2 2 // Идентификатор кнопки Buttton2
#define ID_EDIT1 3 //Идентификатор поля ввода Edit1
#define ID_EDIT2 4 //Идентификатор поля ввода Edit2

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
	wc.hbrBackground = (HBRUSH)(14);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "classic";
	RegisterClass(&wc);

      
          HWND hButton1, hButton2; // Идентификаторы кнопок
		  
		  HWND hEdit1,hEdit2;     // Идентификаторы поля ввода

		  HWND hStat1,hStat2;//Идентификаторы статики

      
     //Создаём первое окно hWnd1
	HWND hWnd1 = CreateWindow("classic", "GDI",WS_OVERLAPPEDWINDOW,        100, 100, 400, 400, NULL, NULL, hInstance, NULL);

    //Создаём второе окно hWnd2
	HWND hWnd2 = CreateWindow("classic", "GDI2",WS_OVERLAPPEDWINDOW,
	510,100, 400, 400,  NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd1, nCmdShow);
	UpdateWindow(hWnd1);

	   // Создаем первую кнопку
  hButton1 = CreateWindow("button", "Button 1",
    WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 20,
    100, 30,
    hWnd1,
    (HMENU) IDB_Button1,
    hInstance, NULL); 

    ShowWindow(hWnd2, nCmdShow);
	UpdateWindow(hWnd2);

	MSG msg;

	  // Создаем вторую кнопку
  hButton2 = CreateWindow("button", "Button 2",
   WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
    20, 20,
    100, 30,
    hWnd2,
    (HMENU) IDB_Button2,
    hInstance, NULL);

 // Создаем редактор текста c индефикатором hEdit1
	
      hEdit1=CreateWindow("edit", "Edit1",
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         20, 100, 200, 30,
         hWnd1, (HMENU) ID_EDIT1, NULL, NULL);

// Когда главное окно приложения получает
    // фокус ввода, отдаем фокус редактору текста
   // case WM_SETFOCUS
   // {
     // SetFocus(hEdit1);
    //  return 0;
    //}


 // Создаем редактор текста с индефикатором hEdit2
	
     hEdit2=CreateWindow("edit", "Edit2",
         WS_CHILD | WS_VISIBLE | WS_BORDER |
         ES_LEFT,
         20, 100, 200, 30,
         hWnd2, (HMENU) ID_EDIT2, NULL, NULL);

   // Статические органы управления
  hStat1 = CreateWindow("static", "Stat1",
    WS_CHILD | WS_VISIBLE | SS_GRAYRECT,
    20, 140, 180, 20,
    hWnd1, (HMENU)-1, hInstance, NULL);

  hStat2 = CreateWindow("static", "Stat2",
    WS_CHILD | WS_VISIBLE | SS_BLACKFRAME,
    20, 140, 180, 20,
    hWnd2, (HMENU)-1, hInstance, NULL);


	HDC hDC = GetDC(hWnd1);
	//Rectangle(hDC, 50, 50, 100, 100);
	//TextOut(hDC, 5, 5, "Первое окно!!!", 14);
	ReleaseDC(hWnd1, hDC);

	while (1)
	{
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		hDC = GetDC(hWnd2);
		//Rectangle(hDC, 50, 50, 100, 100);
		//TextOut(hDC, 5, 5, "Второе окно!!!", 14);
		ReleaseDC(hWnd2, hDC);
	}

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
