#include "menu.h"
#include "Windows.h"
int main()
{
	nlohmann::json Text_Read, Text_Write;
	std::ofstream File_Write_Log("./Log/Log.json");
	File_Write_Log.close();
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	Windows Windows(x, y, 1 | 8);
	Windows.Title("®à¹C");					//±MÃD
	menu Menu{};
	setbkmode(TRANSPARENT);
	setbkcolor(BLACK);
	cleardevice();
	Menu.Menu();
	Menu.game_run_end(x, y);
	return 0;// Windows.Window_exit();
}