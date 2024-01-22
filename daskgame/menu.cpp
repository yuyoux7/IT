#include "menu.h"
Player_Data Player[11];
Button button;
int atk_value = NULL, now_player = NULL, list = 4, def_n = NULL;
int player_count = NULL, Game_run = 20;
bool game_end = false;
void menu::Menu()
{
	nlohmann::json Text_Read;
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	int up_list = NULL;
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	loadimage(&number[0], "./image/number/0.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[1], "./image/number/1.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[2], "./image/number/2.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[3], "./image/number/3.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[4], "./image/number/4.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[5], "./image/number/5.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[6], "./image/number/6.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[7], "./image/number/7.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[8], "./image/number/8.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[9], "./image/number/9.jpg", 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	scenes_home(x, y);
	while (!game_end)
	{
		if (Windows::input_r())
		{
			std::cout << "0";
			input = Windows::INPUT_READ();
			switch (input.message)
			{
			case 0x00000202:							//滑鼠左鍵
				list = 999;
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
				cleardevice();
				outtextxy(10, 20, "0");
				settextcolor(0xFFFFFF);
				atk_int();
				Sleep(80);
				break;
			case menu::def:
				cleardevice();
				outtextxy(10, 20, "1");
				settextcolor(0xFFFFFF);
				Sleep(80);
				break;
			case menu::player:
				cleardevice();
				outtextxy(10, 20, "2");
				settextcolor(0xFFFFFF);
				Sleep(80);
				break;
			case menu::card:
				cleardevice();
				outtextxy(10, 20, "3");
				settextcolor(0xFFFFFF);
				Sleep(80);
				break;
			case 0x0000001B:
				cleardevice();
				outtextxy(10, 20, "back");
				settextcolor(0xFFFFFF);
				Sleep(80);
				break;
			default:
				player_run_scenes(x);
				if (Game_run > 0)
				{
					Game_run -= 1;
				}
				else
				{
					game_end = !game_end;
				}
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
				switch (button.button(0, 0, 4))
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
					choose = false;
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
	TCHAR text = NULL;
	bool r = true;
	int x = 20;
	while (r)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.vkcode == 0x00000000D)
			{
				r = false;
			}
			else if (input.message == 0x00000100)
			{
				if (input.vkcode != 0x8)
				{
					if (input.vkcode - '0' < 10)
					{
						Player[a].Name += input.vkcode;
						text += input.vkcode;
					}
					else if (input.vkcode - '0' > 47)
					{
						Player[a].Name += input.vkcode - 48;
						text += input.vkcode - 48;
					}
					else
					{
						Player[a].Name += input.vkcode + 32;
						text += input.vkcode + 32;
					};
					outtextxy(x, 20, text);
					text = NULL;
					x += 15;
				}
				else
				{
					x -= 15;
					if (x <= 20)
					{
						x = 20;
					}
					outtextxy(x, 20, "		");
				}
				std::cout << input.vkcode - '0' << " ";
			}
		}
	}
	return Player[a].Name;
}
/***********
* char to TCHAR
* char ^ 48 -> Ascii
* TCHAR += char ^ 48;
* TCHAR = NULL;
* a -> A + 32
* number - 48
* 
************
* string to char
* char = string[number];
***********/
void menu::scenes_home(int x, int y)
{
	TCHAR T = NULL;
	bool home = false, oo = true;
	int run_for_int = 2;
	IMAGE bg, up, down, start_unp, start_p, player_c;
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	int p_x, p_y;
	loadimage(&bg, "./image/home/bg_.png", x, y, true);
	loadimage(&up, "./image/home/up.png");
	p_x = up.getwidth() * r_x;
	p_y = up.getheight() * r_y;
	loadimage(&up, "./image/home/up.png", p_x, p_y, true);
	loadimage(&down, "./image/home/down.png");
	p_x = down.getwidth() * r_x;
	p_y = down.getheight() * r_y;
	loadimage(&down, "./image/home/down.png", p_x, p_y, true);
	loadimage(&start_unp, "./image/home/startbutton.png");
	p_x = start_unp.getwidth() * r_x;
	p_y = start_unp.getheight() * r_y;
	loadimage(&start_unp, "./image/home/startbutton.png", p_x, p_y, true);
	loadimage(&start_p, "./image/home/startbutton_down.png");
	p_x = start_p.getwidth() * r_x;
	p_y = start_p.getheight() * r_y;
	loadimage(&start_p, "./image/home/startbutton_down.png", p_x, p_y, true);
	loadimage(&player_c, "./image/home/playercount.png");
	p_x = player_c.getwidth() * r_x;
	p_y = player_c.getheight() * r_y;
	loadimage(&player_c, "./image/home/playercount.png", p_x, p_y, true);
	putimage(0, 0, &bg);
	putimage(1117 * r_x, 619 * r_y, &up);
	putimage(1151 * r_x, 659 * r_y, &down);
	putimage(782 * r_x, 622 * r_y, &player_c);
	putimage(952 * r_x, 630 * r_y, &number[2]);
	putimage(702 * r_x, 780 * r_y, &start_unp);
	while (!home)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000201)			//滑鼠左鍵
			{
				if (button.button(input.x, input.y, 0) == 0xA420)
				{
					while (input.message != 0x00000202)
					{
						if (Windows::input_r())
						{
							input = Windows::INPUT_READ();
						}
					}
					if (run_for_int < 10)
					{
						run_for_int++;
					}
				}
				else if (button.button(input.x, input.y, 0) == 0xA430)
				{
					while (input.message != 0x00000202)
					{
						if (Windows::input_r())
						{
							input = Windows::INPUT_READ();
						}
					}
					if (run_for_int > 2)
					{
						run_for_int--;
					}
				}
				else if (button.button(input.x, input.y, 0) == 0xA450)
				{
					putimage(0, 0, &bg);
					putimage(1117 * r_x, 619 * r_y, &up);
					putimage(1151 * r_x, 659 * r_y, &down);
					putimage(782 * r_x, 622 * r_y, &player_c);
					if (run_for_int != 10)  putimage(952 * r_x, 630 * r_y, &number[run_for_int]);
					else { putimage(952 * r_x, 630 * r_y, &number[1]); putimage(952 * r_x + 41 * static_cast<double>(x / static_cast <double>(1920)), 630 * r_y, &number[0]); }
					putimage(702 * r_x, 800 * r_y, &start_p);
					Sleep(80);
					while (input.message != 0x00000202)
					{
						if (Windows::input_r())
						{
							input = Windows::INPUT_READ();
						}
					}
					putimage(702 * r_x, 780 * r_y, &start_unp);
					if (button.button(input.x, input.y, 0) == 0xA450)
					{
						player_count = run_for_int;
						home = !home;
						cleardevice();
						if (player_count != 0)
						{
							for (; run_for_int != 0; run_for_int--)
							{
								Player[run_for_int].Name_NUMBER[0] = rand_v(39, 1);
								Player[run_for_int].Name_NUMBER[1] = rand_v(39, 41);
								Player[run_for_int].Name += (Player_NAME_RAND(Player[run_for_int].Name_NUMBER[0]) + Player_NAME_RAND(Player[run_for_int].Name_NUMBER[1]));
								std::cout << Player[run_for_int].Name << std::endl;
							};
						};
					};
				};
				putimage(782 * r_x, 622 * r_y, &player_c);
				if (run_for_int != 10)  putimage(952 * r_x, 630 * r_y, &number[run_for_int]);
				else { putimage(952 * r_x, 630 * r_y, &number[1]); putimage(952 * r_x + 41 * static_cast<double>(x / static_cast <double>(1920)), 630 * r_y, &number[0]); }
			};
		};
	};
	cleardevice();
}
void menu::default_value(int a, int b)
{
	Player[a].understand = b * 2;
	Player[a].affect = b;
	Player[a].anchored = 100;
	Player[a].exist = b * 2;
	Player[a].intellect = 100;
	Player[a].observatuon = 0;
	switch (Player[a].Race)
	{
	case 1:
		Player[a].observatuon += 5;
		break;
	case 2:
		Player[a].understand += 5;
		break;
	case 3:
		Player[a].affect += 5;
		break;
	case 4:
		Player[a].intellect -= 50;
		break;
	case 5:
		Player[a].anchored -= 50;
		break;
	case 6:
		Player[a].exist += 5;
		break;
	case 7:
		Player[a].anchored -= 25;
		Player[a].affect += 5;
		Player[a].exist += 5;
		break;
	case 8:
		Player[a].understand += 2;
		Player[a].affect += 2;
		Player[a].anchored += 2;
		Player[a].exist = 0;
		Player[a].intellect += 2;
		Player[a].observatuon += 5;
		break;
	}
}
int menu::rand_v(const int a, const int b)
{
	srand((unsigned)time(NULL));
	if (a > 0)
	{
		return rand() % a + b;
	}
	else if (a == 0)
	{

		return rand() + b;
	}
	else
	{
		return 0;
	}
}
std::string menu::Player_NAME_RAND(const int num)
{
	std::string pnm;
	switch (num)
	{
	case 1:
		pnm = "美麗的";
		break;
	case 2:
		pnm = "聰明的";
		break;
	case 3:
		pnm = "快樂的";
		break;
	case 4:
		pnm = "創新的";
		break;
	case 5:
		pnm = "積極的";
		break;
	case 6:
		pnm = "平靜的";
		break;
	case 7:
		pnm = "迷人的";
		break;
	case 8:
		pnm = "勇敢的";
		break;
	case 9:
		pnm = "溫柔的";
		break;
	case 10:
		pnm = "細心的";
		break;
	case 11:
		pnm = "溫暖的";
		break;
	case 12:
		pnm = "神秘的";
		break;
	case 13:
		pnm = "活潑的";
		break;
	case 14:
		pnm = "溫馨的";
		break;
	case 15:
		pnm = "優雅的";
		break;
	case 16:
		pnm = "開朗的";
		break;
	case 17:
		pnm = "自信的";
		break;
	case 18:
		pnm = "細緻的";
		break;
	case 19:
		pnm = "幽默的";
		break;
	case 20:
		pnm = "穩重的";
		break;
	case 21:
		pnm = "純潔的";
		break;
	case 22:
		pnm = "謙虛的";
		break;
	case 23:
		pnm = "有趣的";
		break;
	case 24:
		pnm = "甜蜜的";
		break;
	case 25:
		pnm = "勤奮的";
		break;
	case 26:
		pnm = "豐富的";
		break;
	case 27:
		pnm = "安靜的";
		break;
	case 28:
		pnm = "慷慨的";
		break;
	case 29:
		pnm = "敏感的";
		break;
	case 30:
		pnm = "迷人的";
		break;
	case 31:
		pnm = "豁達的";
		break;
	case 32:
		pnm = "穩健的";
		break;
	case 33:
		pnm = "懶惰的";
		break;
	case 34:
		pnm = "開朗的";
		break;
	case 35:
		pnm = "友善的";
		break;
	case 36:
		pnm = "骯髒的";
		break;
	case 37:
		pnm = "懷舊的";
		break;
	case 38:
		pnm = "夢幻的";
		break;
	case 39:
		pnm = "虛幻的";
		break;
	case 40:
		pnm = "美好的";
		break;
	case 41:
		pnm = "吐司";
		break;
	case 42:
		pnm = "醫生";
		break;
	case 43:
		pnm = "老闆";
		break;
	case 44:
		pnm = "閨密";
		break;
	case 45:
		pnm = "蜜蜂";
		break;
	case 46:
		pnm = "蟑螂";
		break;
	case 47:
		pnm = "老鼠";
		break;
	case 48:
		pnm = "老師";
		break;
	case 49:
		pnm = "貓咪";
		break;
	case 50:
		pnm = "狗溝";
		break;
	case 51:
		pnm = "肉肉";
		break;
	case 52:
		pnm = "杯子";
		break;
	case 53:
		pnm = "黃瓜";
		break;
	case 54:
		pnm = "棍子";
		break;
	case 55:
		pnm = "桶子";
		break;
	case 56:
		pnm = "病毒";
		break;
	case 57:
		pnm = "熱狗";
		break;
	case 58:
		pnm = "芥末";
		break;
	case 59:
		pnm = "桿菌";
		break;
	case 60:
		pnm = "空軍";
		break;
	case 61:
		pnm = "海均";
		break;
	case 62:
		pnm = "乘風";
		break;
	case 63:
		pnm = "巫師";
		break;
	case 64:
		pnm = "道士";
		break;
	case 65:
		pnm = "法師";
		break;
	case 66:
		pnm = "眼鏡";
		break;
	case 67:
		pnm = "狐狸";
		break;
	case 68:
		pnm = "鬼魂";
		break;
	case 69:
		pnm = "幻影";
		break;
	case 70:
		pnm = "先鋒";
		break;
	case 71:
		pnm = "泡泡";
		break;
	case 72:
		pnm = "炸彈";
		break;
	case 73:
		pnm = "姬子";
		break;
	case 74:
		pnm = "麵包";
		break;
	case 75:
		pnm = "早苗";
		break;
	case 76:
		pnm = "輝夜";
		break;
	case 77:
		pnm = "靈夢";
		break;
	case 78:
		pnm = "間桐";
		break;
	case 79:
		pnm = "殭屍";
		break;
	case 80:
		pnm = "衛宮";
		break;
	default:
		break;
	}
	return pnm;
}
void menu::player_run_scenes(int x)
{
	TCHAR chh = NULL;
	outtextxy(x - 80, 40, "剩");
	outtextxy(x - 80, 60, "餘");
	outtextxy(x - 80, 80, "輪");
	outtextxy(x - 80, 100, "次");
	outtextxy(x - 77, 120, ":");
	chh = Game_run / 10 + 48;
	outtextxy(x - 80, 140, chh);
	chh = Game_run % 10 + 48;
	outtextxy(x - 70, 140, chh);
}
void menu::game_run_end(int a, int b)
{
	cleardevice();
	outtextxy(a / 2 - 40, b / 2, "Game End");
	Sleep(10000);
	closegraph();
};
/*********
* 
* 
* 
* 
********/