#include "menu.h"
#include <iostream>
#include <conio.h>
Player_Data Player[10];
Button button;
int atk_value = NULL, now_player = NULL, list = 4;
int player_count = NULL;
void menu::Menu()
{
	int up_list = NULL;
	scenes_home();
	while (true)
	{
		if (Windows::input_r())
		{
			std::cout << "0";
			input = Windows::INPUT_READ();
			switch (input.message)
			{
			case 0x0000020A:							//滑鼠滾輪
				list += 1;
				break;
			case 0x00000202:							//滑鼠左鍵
				list = 0;
				break;
			case 0x00000205:							//滑鼠右鍵
				list = 0x1B;
				break;
			case 0x00000100:
				list = input.vkcode;
				break;
			default:
				list = 999;
				break;
			}
			switch (list)
			{
			case menu::atk:
				outtextxy(10, 20, "0");
				settextcolor(0xFFFFFF);
				atk_int();
				Sleep(80);
				cleardevice();
				break;
			case menu::def:
				outtextxy(10, 20, "1");
				settextcolor(0xFFFFFF);
				Sleep(80);
				cleardevice();
				break;
			case menu::player:
				outtextxy(10, 20, "2");
				settextcolor(0xFFFFFF);
				Sleep(80);
				cleardevice();
				break;
			case menu::card:
				outtextxy(10, 20, "3");
				settextcolor(0xFFFFFF);
				Sleep(80);
				cleardevice();
				break;
			case menu::scenes:
				outtextxy(10, 20, "4");
				settextcolor(0xFFFFFF);
				scenes_home();
				Sleep(80);
				cleardevice();
				break;
			case 0x0000001B:
				outtextxy(10, 20, "back");
				settextcolor(0xFFFFFF);
				Sleep(80);
				cleardevice();
				break;
			default:
				break;
			};
		}
	}
}

void menu::atk_int()
{
	bool choose = true;
	while (choose)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000202)			//滑鼠左鍵
			{
				switch (/*button.button(0, 0, list)*/0xC901)
				{
				case 0x0000C901:
					atk_value = Player[now_player].affect + Player[now_player].observatuon;
					choose = false;
					break;
				case 0x0000C902:
					atk_value = Player[now_player].understand + Player[now_player].observatuon;
					choose = false;
					break;
				case 0x0000C903:
					atk_value = Player[now_player].affect + Player[now_player].understand;
					break;
					choose = 0;
				case 0x0000001B:
					atk_value = 0;
					choose = false;
					break;
				};
			}
		}
	}
	list = 4;
}

std::string menu::input_string(int a)
{
	bool r = true;
	while (r)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000100)
			{
				Player[a].Name += input.vkcode;
				std::cout << input.vkcode;
			};
			if (input.vkcode == 0x00000000D)
			{
				r = false;
			}
		}
	}
	return Player[a].Name;
}

void menu::scenes_home()
{
	bool home = false;
	int run_for_int = NULL;
	while (!home)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000202)			//滑鼠左鍵
			{
				switch (button.button_value(0xC402, 1))
				{
				case 0x0000C402:
					player_count = 2;
					home = true;
					break;
				case 0x0000C403:
					player_count = 3;
					home = true;
					break;
				case 0x0000C404:
					player_count = 4;
					home = true;
					break;
				case 0x0000C405:
					player_count = 5;
					home = true;
					break;
				case 0x0000C406:
					player_count = 6;
					home = true;
					break;
				case 0x0000C407:
					player_count = 7;
					home = true;
					break;
				case 0x0000C408:
					player_count = 8;
					home = true;
					break;
				case 0x0000C409:
					player_count = 9;
					home = true;
					break;
				case 0x0000C410:
					player_count = 10;
					home = true;
					break;
				default:
					break;
				};
				if (player_count != 0)
				{
					for (run_for_int = player_count; run_for_int != 0; run_for_int--)
					{
						input_string(run_for_int);
						//settextcolor(0xFFFFFF);
					};
				};
			};
		};
	};
}
