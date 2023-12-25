#include "menu.h"
#include "Windows.h"
int main()
{
	nlohmann::json Text_Read;
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	Windows Windows(x, y, 0 | 8);
	menu Menu{};
	Windows.Title("桌遊");					//專題
	setbkcolor(0x1F1E33);
	cleardevice();
	Menu.Menu();
	Menu.game_run_end();
	std::ofstream File_Write("config.json");
	File_Write << Text_Read;
	File_Write.close();
	return Windows.Window_exit();
}
