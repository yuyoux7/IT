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
	Windows Windows(x, y, 0 | 8);
	Windows.Title("��C");					//�M�D
	menu Menu{};
	setbkcolor(0x1F1E33);
	cleardevice();
	Menu.Menu();
	Menu.game_run_end(x, y);
	return Windows.Window_exit();
}