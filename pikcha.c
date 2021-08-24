#include <stdio.h>
#include <stdlib.h>
#define _WIN32_WINNT_WiN7 0x0601 //для win7 
#include <windows.h>

/*int main() {

	HWND hwnd=GetConsoleWindow();

	HDC dc = GetDC (hwnd);

	 SelectObject(dc, GetStockObject(DC_BRUSH));
	  SetDCBrushColor(dc,RGB(255, 0, 255));
	  Rectangle (dc, 10, 10, 110, 110);
	  Ellipse (dc, 200, 100, 300, 200);


     return 0;
}*/

int WINAPI WinMain(HINSTANCE hlnst,HINSTANCE hpi,LPSTR cmdline,int ss) {

     MessageBox(NULL,"Hello,World!","Test",MB_OK);


	 return 0;

  }
