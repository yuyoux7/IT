#include "menu.h"
Player_Data Player[11];
Button button;
int atk_value = NULL, now_player = NULL, list = 4, def_n = NULL;
int player_count = NULL, Game_run = 20;
bool game_end = false;
nlohmann::json Image_file;
void menu::Menu()
{
	nlohmann::json Text_Read;
	std::ifstream File_Raed("config.json");
	std::ifstream image_file("image_set.json");
	image_file >> Image_file;
	File_Raed >> Text_Read;
	File_Raed.close();
	image_file.close();
	int up_list = NULL;
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	loadimage(&number[0], static_cast<std::string>(Image_file["number"]["number_0"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[1], static_cast<std::string>(Image_file["number"]["number_1"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[2], static_cast<std::string>(Image_file["number"]["number_2"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[3], static_cast<std::string>(Image_file["number"]["number_3"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[4], static_cast<std::string>(Image_file["number"]["number_4"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[5], static_cast<std::string>(Image_file["number"]["number_5"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[6], static_cast<std::string>(Image_file["number"]["number_6"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[7], static_cast<std::string>(Image_file["number"]["number_7"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[8], static_cast<std::string>(Image_file["number"]["number_8"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	loadimage(&number[9], static_cast<std::string>(Image_file["number"]["number_9"]).data(), 41 * static_cast<double>(x / static_cast <double>(1920)), 71 * static_cast<double>(y / static_cast <double>(1080)), true);
	scenes_home(x, y);
	while (!game_end)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();

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
			if (input.message == 0x00000202)			//·Æ¹«¥ªÁä
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
void menu::image_load(int scenes, int x, int y)
{
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	int p_x, p_y;
	switch (scenes)
	{
	case 1:
		loadimage(&image[1], static_cast<std::string>(Image_file["player_set"]["bg"]).data(), x, y, true);
		loadimage(&image[2], static_cast<std::string>(Image_file["player_set"]["next"]).data());
		p_x = image[2].getwidth() * r_x;
		p_y = image[2].getheight() * r_y;
		loadimage(&image[2], static_cast<std::string>(Image_file["player_set"]["next"]).data(), p_x, p_y, true);
		loadimage(&image[3], static_cast<std::string>(Image_file["player_set"]["race"]["people"]).data());
		p_x = image[3].getwidth() * r_x;
		p_y = image[3].getheight() * r_y;
		loadimage(&image[3], static_cast<std::string>(Image_file["player_set"]["race"]["people"]).data(), p_x, p_y, true);
		loadimage(&image[4], static_cast<std::string>(Image_file["player_set"]["race"]["people_push"]).data());
		p_x = image[4].getwidth() * r_x;
		p_y = image[4].getheight() * r_y;
		loadimage(&image[4], static_cast<std::string>(Image_file["player_set"]["race"]["people_push"]).data(), p_x, p_y, true);
		loadimage(&image[5], static_cast<std::string>(Image_file["player_set"]["race"]["god"]).data());
		p_x = image[5].getwidth() * r_x;
		p_y = image[5].getheight() * r_y;
		loadimage(&image[5], static_cast<std::string>(Image_file["player_set"]["race"]["god"]).data(), p_x, p_y, true);
		loadimage(&image[6], static_cast<std::string>(Image_file["player_set"]["race"]["god_push"]).data());
		p_x = image[6].getwidth() * r_x;
		p_y = image[6].getheight() * r_y;
		loadimage(&image[6], static_cast<std::string>(Image_file["player_set"]["race"]["god_push"]).data(), p_x, p_y, true);
		loadimage(&image[7], static_cast<std::string>(Image_file["player_set"]["race"]["monster"]).data());
		p_x = image[7].getwidth() * r_x;
		p_y = image[7].getheight() * r_y;
		loadimage(&image[7], static_cast<std::string>(Image_file["player_set"]["race"]["monster"]).data(), p_x, p_y, true);
		loadimage(&image[8], static_cast<std::string>(Image_file["player_set"]["race"]["monster_push"]).data());
		p_x = image[8].getwidth() * r_x;
		p_y = image[8].getheight() * r_y;
		loadimage(&image[8], static_cast<std::string>(Image_file["player_set"]["race"]["monster_push"]).data(), p_x, p_y, true);
		loadimage(&image[9], static_cast<std::string>(Image_file["player_set"]["race"]["out_people"]).data());
		p_x = image[9].getwidth() * r_x;
		p_y = image[9].getheight() * r_y;
		loadimage(&image[9], static_cast<std::string>(Image_file["player_set"]["race"]["out_people"]).data(), p_x, p_y, true);
		loadimage(&image[10], static_cast<std::string>(Image_file["player_set"]["race"]["out_people_push"]).data());
		p_x = image[10].getwidth() * r_x;
		p_y = image[10].getheight() * r_y;
		loadimage(&image[10], static_cast<std::string>(Image_file["player_set"]["race"]["out_people_push"]).data(), p_x, p_y, true);
		loadimage(&image[11], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people"]).data());
		p_x = image[11].getwidth() * r_x;
		p_y = image[11].getheight() * r_y;
		loadimage(&image[11], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people"]).data(), p_x, p_y, true);
		loadimage(&image[12], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people_push"]).data());
		p_x = image[12].getwidth() * r_x;
		p_y = image[12].getheight() * r_y;
		loadimage(&image[12], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people_push"]).data(), p_x, p_y, true);
		loadimage(&image[13], static_cast<std::string>(Image_file["player_set"]["race"]["elf"]).data());
		p_x = image[13].getwidth() * r_x;
		p_y = image[13].getheight() * r_y;
		loadimage(&image[13], static_cast<std::string>(Image_file["player_set"]["race"]["elf"]).data(), p_x, p_y, true);
		loadimage(&image[14], static_cast<std::string>(Image_file["player_set"]["race"]["elf_push"]).data());
		p_x = image[14].getwidth() * r_x;
		p_y = image[14].getheight() * r_y;
		loadimage(&image[14], static_cast<std::string>(Image_file["player_set"]["race"]["elf_push"]).data(), p_x, p_y, true);
		loadimage(&image[15], static_cast<std::string>(Image_file["player_set"]["race"]["bug"]).data());
		p_x = image[15].getwidth() * r_x;
		p_y = image[15].getheight() * r_y;
		loadimage(&image[15], static_cast<std::string>(Image_file["player_set"]["race"]["bug"]).data(), p_x, p_y, true);
		loadimage(&image[16], static_cast<std::string>(Image_file["player_set"]["race"]["bug_push"]).data());
		p_x = image[16].getwidth() * r_x;
		p_y = image[16].getheight() * r_y;
		loadimage(&image[16], static_cast<std::string>(Image_file["player_set"]["race"]["bug_push"]).data(), p_x, p_y, true);
		loadimage(&image[17], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster"]).data());
		p_x = image[17].getwidth() * r_x;
		p_y = image[17].getheight() * r_y;
		loadimage(&image[17], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster"]).data(), p_x, p_y, true);
		loadimage(&image[18], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster_push"]).data());
		p_x = image[18].getwidth() * r_x;
		p_y = image[18].getheight() * r_y;
		loadimage(&image[18], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster_push"]).data(), p_x, p_y, true);
		loadimage(&image[19], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["exist"]).data());
		p_x = image[19].getwidth() * r_x;
		p_y = image[19].getheight() * r_y;
		loadimage(&image[19], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["exist"]).data(), p_x, p_y, true);
		loadimage(&image[20], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["anchored"]).data());
		p_x = image[20].getwidth() * r_x;
		p_y = image[20].getheight() * r_y;
		loadimage(&image[20], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["anchored"]).data(), p_x, p_y, true);
		loadimage(&image[21], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["affect"]).data());
		p_x = image[21].getwidth() * r_x;
		p_y = image[21].getheight() * r_y;
		loadimage(&image[21], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["affect"]).data(), p_x, p_y, true);
		loadimage(&image[22], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["observatuon"]).data());
		p_x = image[22].getwidth() * r_x;
		p_y = image[22].getheight() * r_y;
		loadimage(&image[22], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["observatuon"]).data(), p_x, p_y, true);
		loadimage(&image[23], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["intellect"]).data());
		p_x = image[23].getwidth() * r_x;
		p_y = image[23].getheight() * r_y;
		loadimage(&image[23], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["intellect"]).data(), p_x, p_y, true);
		loadimage(&image[24], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["understand"]).data());
		p_x = image[24].getwidth() * r_x;
		p_y = image[24].getheight() * r_y;
		loadimage(&image[24], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["understand"]).data(), p_x, p_y, true);
		loadimage(&image[25], static_cast<std::string>(Image_file["player_set"]["player_name_box"]).data());
		p_x = image[25].getwidth() * r_x;
		p_y = image[25].getheight() * r_y;
		loadimage(&image[25], static_cast<std::string>(Image_file["player_set"]["player_name_box"]).data(), p_x, p_y, true);
		loadimage(&image[26], static_cast<std::string>(Image_file["player_set"]["rand"]).data());
		p_x = image[26].getwidth() * r_x;
		p_y = image[26].getheight() * r_y;
		loadimage(&image[26], static_cast<std::string>(Image_file["player_set"]["rand"]).data(), p_x, p_y, true);
		break;
		case 2:
			break;
		case 3:

			break;
	default:
		break;
	}
}
std::string menu::input_string(int a)
{
	return "";
	/*
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
	*/
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
	bool home = false;
	int run_for_int = 2;
	IMAGE bg, up, down, start_unp, start_p, player_c;
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	int p_x, p_y;
	loadimage(&bg, static_cast<std::string>(Image_file["home"]["bg"]).data(), x, y, true);
	loadimage(&up, static_cast<std::string>(Image_file["home"]["up_button"]).data());
	p_x = up.getwidth() * r_x;
	p_y = up.getheight() * r_y;
	loadimage(&up, static_cast<std::string>(Image_file["home"]["up_button"]).data(), p_x, p_y, true);
	loadimage(&down, static_cast<std::string>(Image_file["home"]["down_button"]).data());
	p_x = down.getwidth() * r_x;
	p_y = down.getheight() * r_y;
	loadimage(&down, static_cast<std::string>(Image_file["home"]["down_button"]).data(), p_x, p_y, true);
	loadimage(&start_unp, static_cast<std::string>(Image_file["home"]["start_button_no_push"]).data());
	p_x = start_unp.getwidth() * r_x;
	p_y = start_unp.getheight() * r_y;
	loadimage(&start_unp, static_cast<std::string>(Image_file["home"]["start_button_no_push"]).data(), p_x, p_y, true);
	loadimage(&start_p, static_cast<std::string>(Image_file["home"]["start_button_push"]).data());
	p_x = start_p.getwidth() * r_x;
	p_y = start_p.getheight() * r_y;
	loadimage(&start_p, static_cast<std::string>(Image_file["home"]["start_button_push"]).data(), p_x, p_y, true);
	loadimage(&player_c, static_cast<std::string>(Image_file["home"]["player_count"]).data());
	p_x = player_c.getwidth() * r_x;
	p_y = player_c.getheight() * r_y;
	loadimage(&player_c, static_cast<std::string>(Image_file["home"]["player_count"]).data(), p_x, p_y, true);
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
			if (input.message == 0x00000201)			//·Æ¹«¥ªÁä
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
						image_load(1, x, y);
						cleardevice();
						if (player_count != 0)
						{
							for (; run_for_int != 0; run_for_int--)
							{
								player_set(x, y, run_for_int);
								//Player[run_for_int].Name_NUMBER[0] = rand_v(39, 1);
								//Player[run_for_int].Name_NUMBER[1] = rand_v(39, 41);
								//Player[run_for_int].Name += (Player_NAME_RAND(Player[run_for_int].Name_NUMBER[0]) + Player_NAME_RAND(Player[run_for_int].Name_NUMBER[1]));
								//std::cout << Player[run_for_int].Name << std::endl;
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
		pnm = Image_file["player_set"]["player_name"]["name_adj_1"];
		break;
	case 2:
		pnm = Image_file["player_set"]["player_name"]["name_adj_2"];
		break;
	case 3:
		pnm = Image_file["player_set"]["player_name"]["name_adj_3"];
		break;
	case 4:
		pnm = Image_file["player_set"]["player_name"]["name_adj_4"];
		break;
	case 5:
		pnm = Image_file["player_set"]["player_name"]["name_adj_5"];
		break;
	case 6:
		pnm = Image_file["player_set"]["player_name"]["name_adj_6"];
		break;
	case 7:
		pnm = Image_file["player_set"]["player_name"]["name_adj_7"];
		break;
	case 8:
		pnm = Image_file["player_set"]["player_name"]["name_adj_8"];
		break;
	case 9:
		pnm = Image_file["player_set"]["player_name"]["name_adj_9"];
		break;
	case 10:
		pnm = Image_file["player_set"]["player_name"]["name_adj_10"];
		break;
	case 11:
		pnm = Image_file["player_set"]["player_name"]["name_adj_11"];
		break;
	case 12:
		pnm = Image_file["player_set"]["player_name"]["name_adj_12"];
		break;
	case 13:
		pnm = Image_file["player_set"]["player_name"]["name_adj_13"];
		break;
	case 14:
		pnm = Image_file["player_set"]["player_name"]["name_adj_14"];
		break;
	case 15:
		pnm = Image_file["player_set"]["player_name"]["name_adj_15"];
		break;
	case 16:
		pnm = Image_file["player_set"]["player_name"]["name_adj_16"];
		break;
	case 17:
		pnm = Image_file["player_set"]["player_name"]["name_adj_17"];
		break;
	case 18:
		pnm = Image_file["player_set"]["player_name"]["name_adj_18"];
		break;
	case 19:
		pnm = Image_file["player_set"]["player_name"]["name_adj_19"];
		break;
	case 20:
		pnm = Image_file["player_set"]["player_name"]["name_adj_20"];
		break;
	case 21:
		pnm = Image_file["player_set"]["player_name"]["name_adj_21"];
		break;
	case 22:
		pnm = Image_file["player_set"]["player_name"]["name_adj_22"];
		break;
	case 23:
		pnm = Image_file["player_set"]["player_name"]["name_adj_23"];
		break;
	case 24:
		pnm = Image_file["player_set"]["player_name"]["name_adj_24"];
		break;
	case 25:
		pnm = Image_file["player_set"]["player_name"]["name_adj_25"];
		break;
	case 26:
		pnm = Image_file["player_set"]["player_name"]["name_adj_26"];
		break;
	case 27:
		pnm = Image_file["player_set"]["player_name"]["name_adj_27"];
		break;
	case 28:
		pnm = Image_file["player_set"]["player_name"]["name_adj_28"];
		break;
	case 29:
		pnm = Image_file["player_set"]["player_name"]["name_adj_29"];
		break;
	case 30:
		pnm = Image_file["player_set"]["player_name"]["name_adj_30"];
		break;
	case 31:
		pnm = Image_file["player_set"]["player_name"]["name_adj_31"];
		break;
	case 32:
		pnm = Image_file["player_set"]["player_name"]["name_adj_32"];
		break;
	case 33:
		pnm = Image_file["player_set"]["player_name"]["name_adj_33"];
		break;
	case 34:
		pnm = Image_file["player_set"]["player_name"]["name_adj_34"];
		break;
	case 35:
		pnm = Image_file["player_set"]["player_name"]["name_adj_35"];
		break;
	case 36:
		pnm = Image_file["player_set"]["player_name"]["name_adj_36"];
		break;
	case 37:
		pnm = Image_file["player_set"]["player_name"]["name_adj_37"];
		break;
	case 38:
		pnm = Image_file["player_set"]["player_name"]["name_adj_38"];
		break;
	case 39:
		pnm = Image_file["player_set"]["player_name"]["name_adj_39"];
		break;
	case 40:
		pnm = Image_file["player_set"]["player_name"]["name_adj_40"];
		break;
	case 41:
		pnm = Image_file["player_set"]["player_name"]["name_1"];
		break;
	case 42:
		pnm = Image_file["player_set"]["player_name"]["name_2"];
		break;
	case 43:
		pnm = Image_file["player_set"]["player_name"]["name_3"];
		break;
	case 44:
		pnm = Image_file["player_set"]["player_name"]["name_4"];
		break;
	case 45:
		pnm = Image_file["player_set"]["player_name"]["name_5"];
		break;
	case 46:
		pnm = Image_file["player_set"]["player_name"]["name_6"];
		break;
	case 47:
		pnm = Image_file["player_set"]["player_name"]["name_7"];
		break;
	case 48:
		pnm = Image_file["player_set"]["player_name"]["name_8"];
		break;
	case 49:
		pnm = Image_file["player_set"]["player_name"]["name_9"];
		break;
	case 50:
		pnm = Image_file["player_set"]["player_name"]["name_10"];
		break;
	case 51:
		pnm = Image_file["player_set"]["player_name"]["name_11"];
		break;
	case 52:
		pnm = Image_file["player_set"]["player_name"]["name_12"];
		break;
	case 53:
		pnm = Image_file["player_set"]["player_name"]["name_13"];
		break;
	case 54:
		pnm = Image_file["player_set"]["player_name"]["name_14"];
		break;
	case 55:
		pnm = Image_file["player_set"]["player_name"]["name_15"];
		break;
	case 56:
		pnm = Image_file["player_set"]["player_name"]["name_16"];
		break;
	case 57:
		pnm = Image_file["player_set"]["player_name"]["name_17"];
		break;
	case 58:
		pnm = Image_file["player_set"]["player_name"]["name_18"];
		break;
	case 59:
		pnm = Image_file["player_set"]["player_name"]["name_19"];
		break;
	case 60:
		pnm = Image_file["player_set"]["player_name"]["name_20"];
		break;
	case 61:
		pnm = Image_file["player_set"]["player_name"]["name_21"];
		break;
	case 62:
		pnm = Image_file["player_set"]["player_name"]["name_22"];
		break;
	case 63:
		pnm = Image_file["player_set"]["player_name"]["name_23"];
		break;
	case 64:
		pnm = Image_file["player_set"]["player_name"]["name_24"];
		break;
	case 65:
		pnm = Image_file["player_set"]["player_name"]["name_25"];
		break;
	case 66:
		pnm = Image_file["player_set"]["player_name"]["name_26"];
		break;
	case 67:
		pnm = Image_file["player_set"]["player_name"]["name_27"];
		break;
	case 68:
		pnm = Image_file["player_set"]["player_name"]["name_28"];
		break;
	case 69:
		pnm = Image_file["player_set"]["player_name"]["name_29"];
		break;
	case 70:
		pnm = Image_file["player_set"]["player_name"]["name_30"];
		break;
	case 71:
		pnm = Image_file["player_set"]["player_name"]["name_31"];
		break;
	case 72:
		pnm = Image_file["player_set"]["player_name"]["name_32"];
		break;
	case 73:
		pnm = Image_file["player_set"]["player_name"]["name_33"];
		break;
	case 74:
		pnm = Image_file["player_set"]["player_name"]["name_34"];
		break;
	case 75:
		pnm = Image_file["player_set"]["player_name"]["name_35"];
		break;
	case 76:
		pnm = Image_file["player_set"]["player_name"]["name_36"];
		break;
	case 77:
		pnm = Image_file["player_set"]["player_name"]["name_37"];
		break;
	case 78:
		pnm = Image_file["player_set"]["player_name"]["name_38"];
		break;
	case 79:
		pnm = Image_file["player_set"]["player_name"]["name_39"];
		break;
	case 80:
		pnm = Image_file["player_set"]["player_name"]["name_40"];
		break;
	default:
		break;
	}
	return pnm;
}
void menu::player_set(int x, int y, int a)
{
	bool rca = false;
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	putimage(0, 0, &image[1]);
	putimage(50 * r_x, 370 * r_y, &image[3]);
	putimage(50 * r_x, 520 * r_y, &image[5]);
	putimage(50 * r_x, 670 * r_y, &image[7]);
	putimage(50 * r_x, 820 * r_y, &image[9]);
	putimage(430 * r_x, 370 * r_y, &image[11]);
	putimage(430 * r_x, 520 * r_y, &image[13]);
	putimage(430 * r_x, 670 * r_y, &image[15]);
	putimage(430 * r_x, 820 * r_y, &image[17]);
	putimage(830 * r_x, 370 * r_y, &image[19]);
	putimage(830 * r_x, 471 * r_y, &image[20]);
	putimage(830 * r_x, 572 * r_y, &image[21]);
	putimage(830 * r_x, 673 * r_y, &image[22]);
	putimage(830 * r_x, 774 * r_y, &image[23]);
	putimage(830 * r_x, 874 * r_y, &image[24]);
	putimage(1340 * r_x, 400 * r_y, &image[25]);
	putimage(1645 * r_x, 385 * r_y, &image[26]);
	putimage((1920 - 350)* r_x, (1080 - 70)* r_y, &image[2]);
	while (!rca)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x201)
			{
				if (button.button(input.x, input.y, 1) != 0xA500 && button.button(input.x, input.y, 1) != 0 && button.button(input.x, input.y, 1) != 0xA590)
				{
					Player[a].Race = button.button(input.x, input.y, 1);
					default_value(a, 1);
					putimage(50 * r_x, 370 * r_y, &image[3]);
					putimage(50 * r_x, 520 * r_y, &image[5]);
					putimage(50 * r_x, 670 * r_y, &image[7]);
					putimage(50 * r_x, 820 * r_y, &image[9]);
					putimage(430 * r_x, 370 * r_y, &image[11]);
					putimage(430 * r_x, 520 * r_y, &image[13]);
					putimage(430 * r_x, 670 * r_y, &image[15]);
					putimage(430 * r_x, 820 * r_y, &image[17]);
					putimage(830 * r_x, 370 * r_y, &image[19]);
					putimage(830 * r_x, 471 * r_y, &image[20]);
					putimage(830 * r_x, 572 * r_y, &image[21]);
					putimage(830 * r_x, 673 * r_y, &image[22]);
					putimage(830 * r_x, 774 * r_y, &image[23]);
					putimage(830 * r_x, 874 * r_y, &image[24]);
					switch (Player[a].Race)
					{
					case 0xA510:
						putimage(50 * r_x, 370 * r_y, &image[4]);
						break;
					case 0xA520:
						putimage(50 * r_x, 520 * r_y, &image[6]);
						break;
					case 0xA530:
						putimage(50 * r_x, 670 * r_y, &image[8]);
						break;
					case 0xA540:
						putimage(50 * r_x, 820 * r_y, &image[10]);
						break;
					case 0xA550:
						putimage(430 * r_x, 370 * r_y, &image[12]);
						break;
					case 0xA560:
						putimage(430 * r_x, 520 * r_y, &image[14]);
						break;
					case 0xA570:
						putimage(430 * r_x, 670 * r_y, &image[16]);
						break;
					case 0xA580:
						putimage(430 * r_x, 820 * r_y, &image[18]);
						break;
					default:
						break;
					}
				}
				if (button.button(input.x, input.y, 1) == 0xA590)
				{
					Player[a].Name_NUMBER[0] = rand_v(39, 1);
					Player[a].Name_NUMBER[1] = rand_v(39, 41);
					int p_x, p_y;
					loadimage(&Player[a].Name[0], Player_NAME_RAND(Player[a].Name_NUMBER[0]).data());
					p_x = Player[a].Name[0].getwidth() * r_x;
					p_y = Player[a].Name[0].getheight() * r_y;
					loadimage(&Player[a].Name[0], Player_NAME_RAND(Player[a].Name_NUMBER[0]).data(), p_x, p_y, true);
					loadimage(&Player[a].Name[1], Player_NAME_RAND(Player[a].Name_NUMBER[1]).data());
					p_x = Player[a].Name[1].getwidth() * r_x;
					p_y = Player[a].Name[1].getheight() * r_y;
					loadimage(&Player[a].Name[1], Player_NAME_RAND(Player[a].Name_NUMBER[1]).data(), p_x, p_y, true);
				}
				if (button.button(input.x, input.y, 1) == 0xA500)
				{
					if (Player[a].Race != 0)
					{
						default_value(a, 0);
						rca = !rca;
					}
				}
			}
		}
	}
}
void menu::player_run_scenes(int x)
{
	TCHAR chh = NULL;
	outtextxy(x - 80, 40, "³Ñ");
	outtextxy(x - 80, 60, "¾l");
	outtextxy(x - 80, 80, "½ü");
	outtextxy(x - 80, 100, "¦¸");
	outtextxy(x - 77, 120, ":");
	chh = Game_run / 10 + 48;
	outtextxy(x - 80, 140, chh);
	chh = Game_run % 10 + 48;
	outtextxy(x - 70, 140, chh);
}
void menu::player_card_use(int x, int y, int a)
{
	bool run = false;
	loadimage(&image[30], static_cast<std::string>(Image_file["gamecard_set"]["bg"]).data(), x, y, true);
	putimage(0, 0, &image[30]);
	while (!run)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000201)
			{

			}
		}
	}
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