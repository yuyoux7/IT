#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <Windows.h>
#include <tchar.h>
#include <conio.h>
#include <math.h>
#define REST_FORG_COLOR 15
#define REST_BACK_COLOR 0
#define WHITE 0x0F
#define YELLOW 0x0E
//#define ? 0x0D
#define RED 0x0C
//#define ? 0x0B
#define GREED 0x0A
#define BLUE 0x09
//#define ? 0x08
//#define ? 0x07
//#define ? 0x06
//#define ? 0x05
//#define ? 0x04
//#define ? 0x03
//#define ? 0x02
//#define ? 0x01
#define BLACK 0x00
#define REST_WINDOWS_IP_X 50
#define REST_WINDOWS_IP_Y 50
using std::cout;
using std::cin;
using std::sort;
using std::string;
using std::endl;
using std::sort;
LRESULT CALLBACK MainWndProc(
	HWND hwnd,        // handle to window
	UINT uMsg,        // message identifier
	WPARAM wParam,    // first message parameter
	LPARAM lParam)    // second message parameter
{
	switch (uMsg)
	{
	case WM_CREATE:
		// Initialize the window. 
		return 0;
	case WM_PAINT:
		// Paint the window's client area. 
		return 0;
	case WM_SIZE:
		// Set the size and position of the window. 
		return 0;
	case WM_DESTROY:
		// Clean up window-specific data objects. 
		return 0;
		// Process other messages. 
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}
string ConvertLPCWSTRToString(LPCWSTR lpcwszStr)
{
	// Determine the length of the converted string 
	int strLength = WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1, nullptr, 0, nullptr, nullptr);
	// Create a std::string with the determined length 
	string str(strLength, 0);
	// Perform the conversion from LPCWSTR to std::string 
	WideCharToMultiByte(CP_UTF8, 0, lpcwszStr, -1, &str[0],	strLength, nullptr, nullptr);
	// Return the converted std::string 
	return str;
}
class often_use
{
public:
	int GET_RAND(int __Bailiwick__ = 0);
	void WORLD_BG_RGB_SET_CMD(int __Forg_Color__ = REST_FORG_COLOR, int __Back_Color__ = REST_BACK_COLOR);
	void MOVE_GOTO_SET_CMD(int __x__, int __y__);
	void CLEAR_WINDOW_CMD();
	inline static void WINDOWS_SET_SIZE(const int WINDOWS_SIZE_X, const int WINDOWS_SIZE_Y, LPCWSTR WINDOWS_NAME, HINSTANCE hInstance = NULL, int nCmdShow = SW_SHOW) {
		WNDCLASSEX WINDOWS_WIN32{};
		WINDOWS_WIN32.cbSize = sizeof(WNDCLASSEX);
		WINDOWS_WIN32.style = CS_SAVEBITS | CS_DROPSHADOW;
		WINDOWS_WIN32.lpfnWndProc = MainWndProc;
		WINDOWS_WIN32.hInstance = hInstance;
		WINDOWS_WIN32.lpszClassName = L"New_Window";
		RegisterClassEx(&WINDOWS_WIN32);
		WINDOWS_GUI_HWND = CreateWindowExW(WS_EX_LEFT, WINDOWS_WIN32.lpszClassName, WINDOWS_NAME, WS_SYSMENU | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX, REST_WINDOWS_IP_X, REST_WINDOWS_IP_Y, WINDOWS_SIZE_X, WINDOWS_SIZE_Y, NULL, NULL, hInstance, NULL);
		ShowWindow(WINDOWS_GUI_HWND, nCmdShow);
	};
	inline static void WINDOWS_TEXT(LPCWSTR OutPrintWord, int WINDOWS_X, int WINDOWS_Y) {
		TextOut(GetDC(WINDOWS_GUI_HWND), WINDOWS_X, WINDOWS_Y, OutPrintWord, ConvertLPCWSTRToString(OutPrintWord).size() - 1);
	};
	inline static void WINDOWS_CLOSE() { DestroyWindow(WINDOWS_GUI_HWND); };
private:
	inline static HWND WINDOWS_GUI_HWND;
}easy_use;
void often_use::WORLD_BG_RGB_SET_CMD(int __Forg_Color__, int __Back_Color__)
{
	WORD color_all = ((__Back_Color__ & 0x0F) << 4) + (__Forg_Color__ & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_all);
}
void often_use::MOVE_GOTO_SET_CMD(int __x__, int __y__)
{
	COORD CMD_LOOP_IP{};
	CMD_LOOP_IP.X = __x__;
	CMD_LOOP_IP.Y = __y__;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CMD_LOOP_IP);
}
int often_use::GET_RAND(int __Bailiwick__)
{
	srand(unsigned(time(NULL)));
	if (__Bailiwick__ != 0)
	{
		return rand() % __Bailiwick__;
	}
	else
	{
		return rand();
	}
}
void often_use::CLEAR_WINDOW_CMD()
{
	system("cls");
}
