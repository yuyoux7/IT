#include "menu.h"
#include "Windows.h"
int main()
{
	nlohmann::json Text_Read, Text_Write;
	std::ofstream File_Write_Log("./Log/Log.json");
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	Windows Windows(x, y, 0 | 8);
	menu Menu{};
	Windows.Title("®à¹C");					//±MÃD
	setbkcolor(0x1F1E33);
	cleardevice();
	Menu.Menu();
	Menu.game_run_end(x, y);
	std::ofstream File_Write("config.json");
	Text_Write["X_size"] = x;
	Text_Write["Y_size"] = y;
	File_Write << Text_Write;
	File_Write.close();
	File_Write_Log.close();
	return 0;//Windows.Window_exit();
}