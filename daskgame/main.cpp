#include "menu.h"
#include "Windows.h"
int main()
{
	Windows Windows(1280, 720, 1 | 8);
	menu Menu{};
	Windows.Title("®à¹C");					//±MÃD
	setbkcolor(0xFFFFFF);
	cleardevice();
	Menu.Menu();
	return Windows.Window_exit();
}