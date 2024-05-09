#include "menu.h"
#include "lib.h"
#include "use_apper.h"
Button button;
Player_Data Player[11];
int atk_value = NULL, now_player = NULL, list = 4, def_n = NULL;
int player_count = NULL, Game_run = 20;
bool game_end = false;
nlohmann::json Image_file;
nlohmann::json Text_Read;
sdlt::lib lib_data;
void menu::Menu()
{
	lib_data.loade_c();
	lib_data.loade_w();
	srand((unsigned)time(NULL));
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	std::ifstream image_file("image_set.json");
	image_file >> Image_file;
	image_file.close();
	int up_list = NULL;
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	loadimage(&number[0], static_cast<std::string>(Image_file["number"]["number_0"]).data());
	loadimage(&number[1], static_cast<std::string>(Image_file["number"]["number_1"]).data());
	loadimage(&number[2], static_cast<std::string>(Image_file["number"]["number_2"]).data());
	loadimage(&number[3], static_cast<std::string>(Image_file["number"]["number_3"]).data());
	loadimage(&number[4], static_cast<std::string>(Image_file["number"]["number_4"]).data());
	loadimage(&number[5], static_cast<std::string>(Image_file["number"]["number_5"]).data());
	loadimage(&number[6], static_cast<std::string>(Image_file["number"]["number_6"]).data());
	loadimage(&number[7], static_cast<std::string>(Image_file["number"]["number_7"]).data());
	loadimage(&number[8], static_cast<std::string>(Image_file["number"]["number_8"]).data());
	loadimage(&number[9], static_cast<std::string>(Image_file["number"]["number_9"]).data());
	loadimage(&number[10], static_cast<std::string>(Image_file["number"]["number_dash"]).data());
	scenes_home(x, y);
	now_player = player_count;
	while (!game_end)
	{
		player_run_scenes();
		player_card_use(now_player);
		for (auto i = 1; i <= player_count; i++)
		{
			Player[i].Rsp -= 1;
			if (Player[i].Rsp < 0)
			{
				Player[i].Rsp = player_count - 1;
			}
		}
		now_player--;
		if (now_player == 0)
		{
			now_player = player_count;
			Game_run--;
		}
		if (Game_run == 0)
		{
			game_end = !game_end;
		}
		Sleep(1);;
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
		Sleep(1);;
	}
	list = 4;
}
void menu::image_load(int scenes)
{
	switch (scenes)
	{
	case 1:
		loadimage(&image[1], static_cast<std::string>(Image_file["player_set"]["bg"]).data());
		loadimage(&image[2], static_cast<std::string>(Image_file["player_set"]["next"]).data());
		loadimage(&image[3], static_cast<std::string>(Image_file["player_set"]["race"]["people"]).data());
		loadimage(&image[4], static_cast<std::string>(Image_file["player_set"]["race"]["people_push"]).data());
		loadimage(&image[5], static_cast<std::string>(Image_file["player_set"]["race"]["god"]).data());
		loadimage(&image[6], static_cast<std::string>(Image_file["player_set"]["race"]["god_push"]).data());
		loadimage(&image[7], static_cast<std::string>(Image_file["player_set"]["race"]["monster"]).data());
		loadimage(&image[8], static_cast<std::string>(Image_file["player_set"]["race"]["monster_push"]).data());
		loadimage(&image[9], static_cast<std::string>(Image_file["player_set"]["race"]["out_people"]).data());
		loadimage(&image[10], static_cast<std::string>(Image_file["player_set"]["race"]["out_people_push"]).data());
		loadimage(&image[11], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people"]).data());
		loadimage(&image[12], static_cast<std::string>(Image_file["player_set"]["race"]["thinking_people_push"]).data());
		loadimage(&image[13], static_cast<std::string>(Image_file["player_set"]["race"]["elf"]).data());
		loadimage(&image[14], static_cast<std::string>(Image_file["player_set"]["race"]["elf_push"]).data());
		loadimage(&image[15], static_cast<std::string>(Image_file["player_set"]["race"]["bug"]).data());
		loadimage(&image[16], static_cast<std::string>(Image_file["player_set"]["race"]["bug_push"]).data());
		loadimage(&image[17], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster"]).data());
		loadimage(&image[18], static_cast<std::string>(Image_file["player_set"]["race"]["no_save_monster_push"]).data());
		loadimage(&image[19], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["exist"]).data());
		loadimage(&image[20], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["anchored"]).data());
		loadimage(&image[21], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["affect"]).data());
		loadimage(&image[22], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["observatuon"]).data());
		loadimage(&image[23], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["intellect"]).data());
		loadimage(&image[24], static_cast<std::string>(Image_file["player_set"]["player_value_box"]["understand"]).data());
		loadimage(&image[25], static_cast<std::string>(Image_file["player_set"]["player_name_box"]).data());
		loadimage(&image[26], static_cast<std::string>(Image_file["player_set"]["rand"]).data());
		loadimage(&image[27], static_cast<std::string>(Image_file["player_set"]["dicenumber"]).data());
		loadimage(&image[270], static_cast<std::string>(Image_file["player_set"]["dicenumder"]).data());
		loadimage(&image[28], static_cast<std::string>(Image_file["player_set"]["up"]).data(), 0.7, 0.7);
		loadimage(&image[29], static_cast<std::string>(Image_file["player_set"]["down"]).data(), 0.7, 0.7);
		loadimage(&e_number[0], static_cast<std::string>(Image_file["number"]["number_0"]).data(), 0.78, 0.78);
		loadimage(&e_number[1], static_cast<std::string>(Image_file["number"]["number_1"]).data(), 0.78, 0.78);
		loadimage(&e_number[2], static_cast<std::string>(Image_file["number"]["number_2"]).data(), 0.78, 0.78);
		loadimage(&e_number[3], static_cast<std::string>(Image_file["number"]["number_3"]).data(), 0.78, 0.78);
		loadimage(&e_number[4], static_cast<std::string>(Image_file["number"]["number_4"]).data(), 0.78, 0.78);
		loadimage(&e_number[5], static_cast<std::string>(Image_file["number"]["number_5"]).data(), 0.78, 0.78);
		loadimage(&e_number[6], static_cast<std::string>(Image_file["number"]["number_6"]).data(), 0.78, 0.78);
		loadimage(&e_number[7], static_cast<std::string>(Image_file["number"]["number_7"]).data(), 0.78, 0.78);
		loadimage(&e_number[8], static_cast<std::string>(Image_file["number"]["number_8"]).data(), 0.78, 0.78);
		loadimage(&e_number[9], static_cast<std::string>(Image_file["number"]["number_9"]).data(), 0.78, 0.78);
		break;
	case 2:
		loadimage(&image[60], static_cast<std::string>(Image_file["game_round"]["bg"]).data());
		loadimage(&image[61], static_cast<std::string>(Image_file["game_round"]["first"]).data());
		loadimage(&image[62], static_cast<std::string>(Image_file["game_round"]["second"]).data());
		loadimage(&image[63], static_cast<std::string>(Image_file["game_round"]["third"]).data());
		loadimage(&image[64], static_cast<std::string>(Image_file["game_round"]["forth"]).data());
		loadimage(&image[65], static_cast<std::string>(Image_file["game_round"]["player_block"]).data());
		loadimage(&image[66], static_cast<std::string>(Image_file["game_round"]["player_order"]).data());
		loadimage(&image[67], static_cast<std::string>(Image_file["game_round"]["next_player"]).data());
		loadimage(&image[68], static_cast<std::string>(Image_file["game_round"]["next"]).data());
		loadimage(&image[69], static_cast<std::string>(Image_file["game_round"]["round"]).data());
		break;
	case 3:
		loadimage(&image[30], static_cast<std::string>(Image_file["gamecard_set"]["bg"]).data());
		loadimage(&image[31], static_cast<std::string>(Image_file["gamecard_set"]["no"]).data());
		loadimage(&image[32], static_cast<std::string>(Image_file["gamecard_set"]["yes"]).data());
		loadimage(&image[33], static_cast<std::string>(Image_file["gamecard_set"]["card"]).data());
		loadimage(&image[34], static_cast<std::string>(Image_file["gamecard_set"]["magic"]).data());
		loadimage(&image[35], static_cast<std::string>(Image_file["gamecard_set"]["taoism"]).data());
		loadimage(&image[36], static_cast<std::string>(Image_file["gamecard_set"]["atk"]).data());
		loadimage(&image[37], static_cast<std::string>(Image_file["gamecard_set"]["next"]).data());
		loadimage(&image[38], static_cast<std::string>(Image_file["gamecard_set"]["delete"]).data());
		loadimage(&image[39], static_cast<std::string>(Image_file["gamecard_set"]["now_step"]).data());
		loadimage(&image[40], static_cast<std::string>(Image_file["gamecard_set"]["game_round"]).data());
		loadimage(&image[41], static_cast<std::string>(Image_file["gamecard_set"]["effect"]["effect"]).data());
		loadimage(&image[42], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["exist"]).data());
		loadimage(&image[43], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["anchored"]).data());
		loadimage(&image[44], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["affect"]).data());
		loadimage(&image[45], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["observatuon"]).data());
		loadimage(&image[46], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["intellect"]).data());
		loadimage(&image[47], static_cast<std::string>(Image_file["gamecard_set"]["player_value_box"]["understand"]).data());
		loadimage(&image[50], static_cast<std::string>(Image_file["gamecard_set"]["player_name"]).data());
		break;
	case 4:
		loadimage(&image[100], static_cast<std::string>(Image_file["atk_set"]["bg"]).data());
		loadimage(&image[101], static_cast<std::string>(Image_file["atk_set"]["atkeffect"]).data());
		loadimage(&image[102], static_cast<std::string>(Image_file["atk_set"]["tageffect"]).data());
		loadimage(&image[103], static_cast<std::string>(Image_file["atk_set"]["exist"]).data());
		loadimage(&image[104], static_cast<std::string>(Image_file["atk_set"]["anchored"]).data());
		loadimage(&image[105], static_cast<std::string>(Image_file["atk_set"]["affect"]).data());
		loadimage(&image[106], static_cast<std::string>(Image_file["atk_set"]["observatuon"]).data());
		loadimage(&image[107], static_cast<std::string>(Image_file["atk_set"]["intellect"]).data());
		loadimage(&image[108], static_cast<std::string>(Image_file["atk_set"]["understand"]).data());
		loadimage(&image[109], static_cast<std::string>(Image_file["atk_set"]["next"]).data());
		loadimage(&image[110], static_cast<std::string>(Image_file["atk_set"]["patk"]).data());
		loadimage(&image[111], static_cast<std::string>(Image_file["atk_set"]["pch"]).data());
		loadimage(&image[112], static_cast<std::string>(Image_file["atk_set"]["pnch"]).data());
		loadimage(&image[113], static_cast<std::string>(Image_file["atk_set"]["pnm"]).data());
		break;
	default:
		break;
	}
}
std::string menu::input_string() const
{
	std::string fstr;
	if (input.message == 0x00000100)
	{
		if (input.vkcode == 0x00000000D)
		{
			return "enter";
		}
		else if (input.vkcode != 0x8)
		{
			if (input.vkcode - '0' < 10)
			{
				fstr += input.vkcode;
			}
			else if (input.vkcode - '0' > 47)
			{
				fstr += input.vkcode - 48;
			}
			else
			{
				fstr += input.vkcode + 32;
			}
		}
		else
		{
			return "remove";
		}
	}
	return fstr;
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
	loadimage(&bg, static_cast<std::string>(Image_file["home"]["bg"]).data());
	loadimage(&up, static_cast<std::string>(Image_file["home"]["up_button"]).data());
	loadimage(&down, static_cast<std::string>(Image_file["home"]["down_button"]).data());
	loadimage(&start_unp, static_cast<std::string>(Image_file["home"]["start_button_no_push"]).data());
	loadimage(&start_p, static_cast<std::string>(Image_file["home"]["start_button_push"]).data());
	loadimage(&player_c, static_cast<std::string>(Image_file["home"]["player_count"]).data());
	putimage(0, 0, &bg);
	putimage(1117, 619 , &up);
	putimage(1151, 659 , &down);
	putimage(782, 622 , &player_c);
	putimage(952, 638 + 5, &number[2]);
	putimage(702, 780 , &start_unp);
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
					putimage(1117, 619 , &up);
					putimage(1151, 659 , &down);
					putimage(782, 622 , &player_c);
					if (run_for_int != 10)  putimage(952, 638 + 5, &number[run_for_int]);
					else { putimage(952, 638 + 5, &number[1]); putimage(955 + 43 * static_cast<double>(x / static_cast <double>(1920)), 638 + 5, &number[0]); }
					putimage(702, 800 , &start_p);
					Sleep(80);
					while (input.message != 0x00000202)
					{
						if (Windows::input_r())
						{
							input = Windows::INPUT_READ();
						}
					}
					putimage(702, 780 , &start_unp);
					if (button.button(input.x, input.y, 0) == 0xA450)
					{
						player_count = run_for_int;
						home = !home;
						image_load(1);
						cleardevice();
						if (player_count != 0)
						{
							for (; run_for_int != 0; run_for_int--)
							{
								Player[run_for_int].Rsp = player_count - run_for_int;
								player_set(x, y, run_for_int);
								Sleep(1);
							};
						};
					};
				};
				putimage(782, 622 , &player_c);
				if (run_for_int != 10)  putimage(952, 638 + 5, &number[run_for_int]);
				else { putimage(952, 638 + 5, &number[1]); putimage(955 + 43 * static_cast<double>(x / static_cast <double>(1920)), 638 + 5, &number[0]); }
			};
		};
		Sleep(1);
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
	case 0xA510:
		Player[a].observatuon += 5;
		break;
	case 0xA520:
		Player[a].understand += 5;
		break;
	case 0xA530:
		Player[a].affect += 5;
		break;
	case 0xA540:
		Player[a].intellect -= 50;
		break;
	case 0xA550:
		Player[a].anchored -= 50;
		break;
	case 0xA560:
		Player[a].exist += 5;
		break;
	case 0xA570:
		Player[a].anchored -= 25;
		Player[a].affect += 5;
		Player[a].exist += 5;
		break;
	case 0xA580:
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
void menu::player_set(int x, int y, int player)
{
	bool rca = false;
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	int dicenumber_v = 1;
	putimage(0, 0, &image[1]);
	putimage(50, 370 , &image[3]);
	putimage(50, 520 , &image[5]);
	putimage(50, 670 , &image[7]);
	putimage(50, 820 , &image[9]);
	putimage(430, 370 , &image[11]);
	putimage(430, 520 , &image[13]);
	putimage(430, 670 , &image[15]);
	putimage(430, 820 , &image[17]);
	putimage(830, 370 , &image[19]);
	putimage(830, 471 , &image[20]);
	putimage(830, 572 , &image[21]);
	putimage(830, 673 , &image[22]);
	putimage(830, 774 , &image[23]);
	putimage(830, 874 , &image[24]);
	putimage(1340, 400 , &image[25]);
	putimage(1645, 385 , &image[26]);
	putimage(1340, 600, &image[27]);
	putimage(1625, 600, &image[28]);
	putimage(1625, 640, &image[29]);
	putimage((1920 - 350), (1080 - 70), &image[2]);
	Player[player].Name_NUMBER[0] = rand_v(40, 1);
	Player[player].Name_NUMBER[1] = rand_v(40, 41);
	loadimage(&Player[player].Name[0], Player_NAME_RAND(Player[player].Name_NUMBER[0]).data());
	loadimage(&Player[player].Name[1], Player_NAME_RAND(Player[player].Name_NUMBER[1]).data());
	putimage(1354, 473, &Player[player].Name[0]);
	putimage(1605, 473, &Player[player].Name[1]);
	putimage(1560, 615, &e_number[dicenumber_v]);
	while (!rca)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x201)
			{
				if (button.button(input.x, input.y, 1) != 0xA500 && button.button(input.x, input.y, 1) != 0 && button.button(input.x, input.y, 1) != 0xA590 && button.button(input.x, input.y, 1) != 0xB510 && button.button(input.x, input.y, 1) != 0xB520)
				{
					Player[player].Race = button.button(input.x, input.y, 1);
					default_value(player, 1);
					putimage(50, 370 , &image[3]);
					putimage(50, 520 , &image[5]);
					putimage(50, 670 , &image[7]);
					putimage(50, 820 , &image[9]);
					putimage(430, 370 , &image[11]);
					putimage(430, 520 , &image[13]);
					putimage(430, 670 , &image[15]);
					putimage(430, 820 , &image[17]);
					putimage(830, 370 , &image[19]);
					putimage(830, 471 , &image[20]);
					putimage(830, 572 , &image[21]);
					putimage(830, 673 , &image[22]);
					putimage(830, 774 , &image[23]);
					putimage(830, 874 , &image[24]);
					switch (Player[player].Race)
					{
					case 0xA510:
						putimage(50, 370 , &image[4]);
						break;
					case 0xA520:
						putimage(50, 520 , &image[6]);
						break;
					case 0xA530:
						putimage(50, 670 , &image[8]);
						break;
					case 0xA540:
						putimage(50, 820 , &image[10]);
						break;
					case 0xA550:
						putimage(430, 370 , &image[12]);
						break;
					case 0xA560:
						putimage(430, 520 , &image[14]);
						break;
					case 0xA570:
						putimage(430, 670 , &image[16]);
						break;
					case 0xA580:
						putimage(430, 820 , &image[18]);
						break;
					default:
						break;
					}
					default_value(player, dicenumber_v);
					putimage(1100, 375 + 5, &e_number[Player[player].exist / 10]);// dv 1 ip
					putimage(1140, 375 + 5, &e_number[Player[player].exist - ((Player[player].exist / 10) * 10)]);
					putimage(1080, 477 + 5, &e_number[Player[player].anchored / 100]);// dv 2 ip
					putimage(1120, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) / 10]);
					putimage(1160, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) - ((Player[player].anchored - (Player[player].anchored / 100) * 100) / 10) * 10]);
					putimage(1100, 578 + 5, &e_number[Player[player].affect / 10]);// dv 3 ip
					putimage(1140, 578 + 5, &e_number[Player[player].affect - ((Player[player].affect / 10) * 10)]);
					putimage(1100, 679 + 5, &e_number[Player[player].observatuon / 10]);// dv 4 ip
					putimage(1140, 679 + 5, &e_number[Player[player].observatuon - ((Player[player].observatuon / 10) * 10)]);
					putimage(1080, 780 + 5, &e_number[Player[player].intellect / 100]);// dv 5 ip
					putimage(1120, 780 + 5, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) / 10]);
					putimage(1160, 780 + 5, &e_number[Player[player].intellect - ((Player[player].intellect / 100) * 100) - ((Player[player].intellect - (Player[player].intellect / 100) * 100) / 10) * 10]);
					putimage(1100, 880 + 5, &e_number[Player[player].understand / 10]);// dv 6 ip
					putimage(1140, 880 + 5, &e_number[Player[player].understand - ((Player[player].understand / 10) * 10)]);
				}
				if (button.button(input.x, input.y, 1) == 0xA590)
				{
					Player[player].Name_NUMBER[0] = rand_v(40, 1);
					Player[player].Name_NUMBER[1] = rand_v(40, 41);
					loadimage(&Player[player].Name[0], Player_NAME_RAND(Player[player].Name_NUMBER[0]).data());
					loadimage(&Player[player].Name[1], Player_NAME_RAND(Player[player].Name_NUMBER[1]).data());
					putimage(1354, 473, &Player[player].Name[0]);
					putimage(1605, 473, &Player[player].Name[1]);
				}
				if (button.button(input.x, input.y, 1) == 0xB510 && Player[player].Race != 0)
				{
					if (dicenumber_v < 6)
					{
						++dicenumber_v;
					}
					putimage(1560, 615, &e_number[dicenumber_v]);
					default_value(player, dicenumber_v);
					putimage(1100, 375 + 5, &e_number[Player[player].exist / 10]);// dv 1 ip
					putimage(1140, 375 + 5, &e_number[Player[player].exist - ((Player[player].exist / 10) * 10)]);
					putimage(1080, 477 + 5, &e_number[Player[player].anchored / 100]);// dv 2 ip
					putimage(1120, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) / 10]);
					putimage(1160, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) - ((Player[player].anchored - (Player[player].anchored / 100) * 100) / 10) * 10]);
					putimage(1100, 578 + 5, &e_number[Player[player].affect / 10]);// dv 3 ip
					putimage(1140, 578 + 5, &e_number[Player[player].affect - ((Player[player].affect / 10) * 10)]);
					putimage(1100, 679 + 5, &e_number[Player[player].observatuon / 10]);// dv 4 ip
					putimage(1140, 679 + 5, &e_number[Player[player].observatuon - ((Player[player].observatuon / 10) * 10)]);
					putimage(1080, 780 + 5, &e_number[Player[player].intellect / 100]);// dv 5 ip
					putimage(1120, 780 + 5, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) / 10]);
					putimage(1160, 780 + 5, &e_number[Player[player].intellect - ((Player[player].intellect / 100) * 100) - ((Player[player].intellect - (Player[player].intellect / 100) * 100) / 10) * 10]);
					putimage(1100, 880 + 5, &e_number[Player[player].understand / 10]);// dv 6 ip
					putimage(1140, 880 + 5, &e_number[Player[player].understand - ((Player[player].understand / 10) * 10)]);
				}
				if (button.button(input.x, input.y, 1) == 0xB520 && Player[player].Race != 0)
				{
					if (dicenumber_v > 1)
					{
						--dicenumber_v;
					}
					putimage(1560, 615, &e_number[dicenumber_v]);
					default_value(player, dicenumber_v);
					putimage(1100, 375 + 5, &e_number[Player[player].exist / 10]);// dv 1 ip
					putimage(1140, 375 + 5, &e_number[Player[player].exist - ((Player[player].exist / 10) * 10)]);
					putimage(1080, 477 + 5, &e_number[Player[player].anchored / 100]);// dv 2 ip
					putimage(1120, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) / 10]);
					putimage(1160, 477 + 5, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) - ((Player[player].anchored - (Player[player].anchored / 100) * 100) / 10) * 10]);
					putimage(1100, 578 + 5, &e_number[Player[player].affect / 10]);// dv 3 ip
					putimage(1140, 578 + 5, &e_number[Player[player].affect - ((Player[player].affect / 10) * 10)]);
					putimage(1100, 679 + 5, &e_number[Player[player].observatuon / 10]);// dv 4 ip
					putimage(1140, 679 + 5, &e_number[Player[player].observatuon - ((Player[player].observatuon / 10) * 10)]);
					putimage(1080, 780 + 5, &e_number[Player[player].intellect / 100]);// dv 5 ip
					putimage(1120, 780 + 5, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) / 10]);
					putimage(1160, 780 + 5, &e_number[Player[player].intellect - ((Player[player].intellect / 100) * 100) - ((Player[player].intellect - (Player[player].intellect / 100) * 100) / 10) * 10]);
					putimage(1100, 880 + 5, &e_number[Player[player].understand / 10]);// dv 6 ip
					putimage(1140, 880 + 5, &e_number[Player[player].understand - ((Player[player].understand / 10) * 10)]);
				}
				if (button.button(input.x, input.y, 1) == 0xA500)
				{
					if (Player[player].Race != 0)
					{
						default_value(player, dicenumber_v);
						rca = !rca;
					}
				}
			}
		}
		Sleep(1);;
	}
}
void menu::player_run_scenes()
{
	bool run = false;
	bool kfp = false;
	int lppy = NULL;
	int pcld[10]{};
	image_load(2);
	putimage(0, 0, &image[60]);
	putimage(130, 500, &image[66]);
	putimage(130, 250, &image[67]);
	putimage(1780, 50, &image[69]);
	putimage(1570, 1010, &image[68]);
	putimage(100, 350, &image[61]);
	putimage(500, 350, &image[62]);
	putimage(150, 600, &image[65]);
	putimage(500, 600, &image[65]);
	putimage(1430,970,&image[270]);
	putimage(1790, 450, &e_number[Game_run / 10]); putimage(1825, 450, &e_number[Game_run - (Game_run / 10) * 10]);
	for (auto i = 1; i <= player_count; i++)
	{
		for (auto j = 1; j <= player_count; j++)
		{
			if (Player[j].Rsp  == i - 1)
			{
				pcld[i] = j;
			}
		}
	}
	putimage(160, 370, &Player[pcld[1]].Name[0]); putimage(340, 370, &Player[pcld[1]].Name[1]);
	putimage(560, 370, &Player[pcld[2]].Name[0]); putimage(740, 370, &Player[pcld[2]].Name[1]);
	putimage(160, 620, &Player[player_count].Name[0]); putimage(340, 620, &Player[player_count].Name[1]);
	if (player_count > 0)
	{
		putimage(510, 620, &Player[player_count - 1].Name[0]); putimage(690, 620, &Player[player_count - 1].Name[1]);
	}
	switch (player_count)
	{
	case 3:
		putimage(900, 350, &image[63]);
		putimage(850, 600, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		break;
	case 4:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		break;
	case 5:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		break;
	case 6:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(150, 750, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		putimage(160, 770, &Player[player_count - 5].Name[0]); putimage(340, 770, &Player[player_count - 5].Name[1]);
		break;
	case 7:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(150, 750, &image[65]);
		putimage(500, 750, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		putimage(160, 770, &Player[player_count - 5].Name[0]); putimage(340, 770, &Player[player_count - 5].Name[1]);
		putimage(510, 770, &Player[player_count - 6].Name[0]); putimage(690, 770, &Player[player_count - 6].Name[1]);
		break;
	case 8:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(150, 750, &image[65]);
		putimage(500, 750, &image[65]);
		putimage(850, 750, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		putimage(160, 770, &Player[player_count - 5].Name[0]); putimage(340, 770, &Player[player_count - 5].Name[1]);
		putimage(510, 770, &Player[player_count - 6].Name[0]); putimage(690, 770, &Player[player_count - 6].Name[1]);
		putimage(860, 770, &Player[player_count - 7].Name[0]); putimage(1040, 770, &Player[player_count - 7].Name[1]);
		break;
	case 9:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(150, 750, &image[65]);
		putimage(500, 750, &image[65]);
		putimage(850, 750, &image[65]);
		putimage(1200, 750, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		putimage(160, 770, &Player[player_count - 5].Name[0]); putimage(340, 770, &Player[player_count - 5].Name[1]);
		putimage(510, 770, &Player[player_count - 6].Name[0]); putimage(690, 770, &Player[player_count - 6].Name[1]);
		putimage(860, 770, &Player[player_count - 7].Name[0]); putimage(1040, 770, &Player[player_count - 7].Name[1]);
		putimage(1210, 770, &Player[player_count - 8].Name[0]); putimage(1390, 770, &Player[player_count - 8].Name[1]);
		break;
	case 10:
		putimage(900, 350, &image[63]);
		putimage(1300, 350, &image[64]);
		putimage(850, 600, &image[65]);
		putimage(1200, 600, &image[65]);
		putimage(1550, 600, &image[65]);
		putimage(150, 750, &image[65]);
		putimage(500, 750, &image[65]);
		putimage(850, 750, &image[65]);
		putimage(1200, 750, &image[65]);
		putimage(1550, 750, &image[65]);
		putimage(860, 620, &Player[player_count - 2].Name[0]); putimage(1040, 620, &Player[player_count - 2].Name[1]);
		putimage(1210, 620, &Player[player_count - 3].Name[0]); putimage(1390, 620, &Player[player_count - 3].Name[1]);
		putimage(1560, 620, &Player[player_count - 4].Name[0]); putimage(1740, 620, &Player[player_count - 4].Name[1]);
		putimage(160, 770, &Player[player_count -5].Name[0]); putimage(340, 770, &Player[player_count - 5].Name[1]);
		putimage(510, 770, &Player[player_count - 6].Name[0]); putimage(690, 770, &Player[player_count - 6].Name[1]);
		putimage(860, 770, &Player[player_count - 7].Name[0]); putimage(1040, 770, &Player[player_count - 7].Name[1]);
		putimage(1210, 770, &Player[player_count - 8].Name[0]); putimage(1390, 770, &Player[player_count - 8].Name[1]);
		putimage(1560, 770, &Player[player_count - 9].Name[0]); putimage(1740, 770, &Player[player_count - 9].Name[1]);
		break;
	default:
		break;
	}
	if (player_count >= 3)
	{
		putimage(960, 370, &Player[pcld[3]].Name[0]); putimage(1140, 370, &Player[pcld[3]].Name[1]);
		if (player_count >= 4)
		{
			putimage(1360, 370, &Player[pcld[4]].Name[0]); putimage(1540, 370, &Player[pcld[4]].Name[1]);
		}
	}
	while (!run)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000201)
			{
				switch (button.button(input.x, input.y, 2))
				{
				case 0xA600:
					run = !run;
					break;
				case 0xA650: case 0xA651: case 0xA652: case 0xA653: case 0xA654:
				case 0xA655: case 0xA656: case 0xA657: case 0xA658: case 0xA659:
					lppy = button.button(input.x, input.y, 2) - 0xA650;
					std::cout << lppy;
					if (lppy <= player_count)
					{
						if (player_count < 10)
						{
							putimage(1460, 1000, &e_number[Player[player_count - lppy].Rsp + 1]);
						}
						else
						{
							putimage(1445, 1000, &e_number[(Player[player_count - lppy].Rsp + 1) / 10]);
							putimage(1475, 1000, &e_number[(Player[player_count - lppy].Rsp + 1) - ((Player[player_count - lppy].Rsp + 1) / 10) * 10]);
						}
						
					}
					//kfp = true;
					break;
				}
			}
		}
		Sleep(1);;
	}
}
void menu::player_card_use(int player)
{
	bool run = false;
	std::string flstr;
	int fn = NULL;
	image_load(3);
	putimage(0, 0, &image[30]);
	putimage(100, 220, &image[50]); putimage(270, 223, &Player[player].Name[0]); putimage(435, 223, &Player[player].Name[1]);
	putimage(100, 380, &image[42]); putimage(100, 480, &image[43]); putimage(100, 580, &image[44]);
	putimage(100, 680, &image[45]); putimage(100, 780, &image[46]); putimage(100, 880, &image[47]);
	putimage(640, 140, &image[33]); putimage(640, 280, &image[35]); putimage(640, 380, &image[34]);
	putimage(640, 530, &image[41]); putimage(830, 210, &image[31]); putimage(970, 210, &image[32]);
	putimage(1100, 280, &image[38]); putimage(1660, 100, &image[39]); putimage(1780, 100, &image[40]);
	//putimage(1670, 500, &e_number[Game_run / 10]); putimage(1705, 500, &e_number[Game_run - (Game_run / 10) * 10]);
	putimage(1790, 500, &e_number[Game_run / 10]); putimage(1825, 500, &e_number[Game_run - (Game_run / 10) * 10]);
	putimage(1570, 900, &image[36]); putimage(1570, 1010, &image[37]);
	if (Player[player].affect < 0)
	{
		putimage(280, 588, &number[10]);
		Player[player].affect *= -1;
		putimage(340, 590, &e_number[Player[player].affect / 100]);
		putimage(380, 590, &e_number[(Player[player].affect - (Player[player].affect / 100) * 100) / 10]);
		putimage(420, 590, &e_number[(Player[player].affect - (Player[player].affect / 100) * 100) - ((Player[player].affect - (Player[player].affect / 100) * 100) / 10) * 10]);
		Player[player].affect *= -1;
	}
	else
	{
		putimage(340, 590, &e_number[Player[player].affect / 100]);
		putimage(380, 590, &e_number[(Player[player].affect - (Player[player].affect / 100) * 100) / 10]);
		putimage(420, 590, &e_number[(Player[player].affect - (Player[player].affect / 100) * 100) - ((Player[player].affect - (Player[player].affect / 100) * 100) / 10) * 10]);
	}
	if (Player[player].anchored < 0)
	{
		putimage(280, 488, &number[10]);
		Player[player].anchored *= -1;
		putimage(340, 490, &e_number[Player[player].anchored / 100]);
		putimage(380, 490, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) / 10]);
		putimage(420, 490, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) - ((Player[player].anchored - (Player[player].anchored / 100) * 100) / 10) * 10]);
		Player[player].anchored *= -1;
	}
	else
	{
		putimage(340, 490, &e_number[Player[player].anchored / 100]);
		putimage(380, 490, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) / 10]);
		putimage(420, 490, &e_number[(Player[player].anchored - (Player[player].anchored / 100) * 100) - ((Player[player].anchored - (Player[player].anchored / 100) * 100) / 10) * 10]);
	}
	if (Player[player].exist < 0)
	{
		putimage(280, 388, &number[10]);
		Player[player].exist *= -1;
		putimage(340, 390, &e_number[Player[player].exist / 100]);
		putimage(380, 390, &e_number[(Player[player].exist - (Player[player].exist / 100) * 100) / 10]);
		putimage(420, 390, &e_number[(Player[player].exist - (Player[player].exist / 100) * 100) - ((Player[player].exist - (Player[player].exist / 100) * 100) / 10) * 10]);
		Player[player].exist *= -1;
	}
	else
	{
		putimage(340, 390, &e_number[Player[player].exist / 100]);
		putimage(380, 390, &e_number[(Player[player].exist - (Player[player].exist / 100) * 100) / 10]);
		putimage(420, 390, &e_number[(Player[player].exist - (Player[player].exist / 100) * 100) - ((Player[player].exist - (Player[player].exist / 100) * 100) / 10) * 10]);
	}
	if (Player[player].intellect < 0)
	{
		putimage(280, 788, &number[10]);
		Player[player].intellect *= -1;
		putimage(340, 790, &e_number[Player[player].intellect / 100]);
		putimage(380, 790, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) / 10]);
		putimage(420, 790, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) - ((Player[player].intellect - (Player[player].intellect / 100) * 100) / 10) * 10]);
		Player[player].intellect *= -1;
	}
	else
	{
		putimage(340, 790, &e_number[Player[player].intellect / 100]);
		putimage(380, 790, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) / 10]);
		putimage(420, 790, &e_number[(Player[player].intellect - (Player[player].intellect / 100) * 100) - ((Player[player].intellect - (Player[player].intellect / 100) * 100) / 10) * 10]);
	}
	if (Player[player].understand < 0)
	{
		putimage(280, 888, &number[10]);
		Player[player].understand *= -1;
		putimage(340, 890, &e_number[Player[player].understand / 100]);
		putimage(380, 890, &e_number[(Player[player].understand - (Player[player].understand / 100) * 100) / 10]);
		putimage(420, 890, &e_number[(Player[player].understand - (Player[player].understand / 100) * 100) - ((Player[player].understand - (Player[player].understand / 100) * 100) / 10) * 10]);
		Player[player].understand *= -1;
	}
	else
	{
		putimage(340, 890, &e_number[Player[player].understand / 100]);
		putimage(380, 890, &e_number[(Player[player].understand - (Player[player].understand / 100) * 100) / 10]);
		putimage(420, 890, &e_number[(Player[player].understand - (Player[player].understand / 100) * 100) - ((Player[player].understand - (Player[player].understand / 100) * 100) / 10) * 10]);
	}
	putimage(340, 690, &e_number[Player[player].observatuon / 100]);
	putimage(380, 690, &e_number[(Player[player].observatuon - (Player[player].observatuon / 100) * 100) / 10]);
	putimage(420, 690, &e_number[(Player[player].observatuon - (Player[player].observatuon / 100) * 100) - ((Player[player].observatuon - (Player[player].observatuon / 100) * 100) / 10) * 10]);
	while (!run)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000201 || input.message == 0x00000100)
			{
				switch (button.button(input.x, input.y, 3))
				{
				case 0xA710:
					break;
				case 0xA720:
					break;
				case 0xA730:
					fn = 1;
					break;
				case 0xA740:
					Player[player].u_magic += input_string();
					break;
				case 0xA750:
					Player[player].u_tao += input_string();
					break;
				case 0xA760:
					atk_scenes(player);
					run = !run;
					break;
				case 0xA770:
					run = !run;
					break;
				case 0xA700:
					break;
				default:
					if (fn == 1)
					{
						if (input_string() == "remove")
						{
							if (Player[player].u_card.size() > 0)
							{
								for (auto i = 0; i < Player[player].u_card.size() - 1; i++)
								{
									flstr += Player[player].u_card[i];
								}
								Player[player].u_card = flstr;
								flstr.clear();
							}
						}
						else if (input_string() == "enter")
						{
							lib_data.word_lib(Player[player].u_card);
							lib_data.card_lib(Player[player].u_card);
							Player[player].u_card.clear();
						}
						else
						{
							if (Player[player].u_card.size() < 5)
							{
								switch (input_string()[0])
								{
								case '1':	case '2':
								case '3':	case '4':
								case '5':	case '6':
								case '7':	case '8':
								case '9':	case '0':
									Player[player].u_card += input_string();
									break;
								case 'a':	case 'A':
									Player[player].u_card += 'A';
									break;
								case 'b':	case 'B':
									Player[player].u_card += 'B';
									break;
								case 'c':	case 'C':
									Player[player].u_card += 'C';
									break;
								case 'd':	case 'D':
									Player[player].u_card += 'D';
									break;
								case 'e':	case 'E':
									Player[player].u_card += 'E';
									break;
								case 'f':	case 'F':
									Player[player].u_card += 'F';
									break;
								default:
									break;
								}
							}
						}
					}
					break;
				}
			}
		}
		Sleep(1);
	}
}
void menu::atk_scenes(int player)
{
	bool run = false;
	image_load(4);
	putimage(0, 0, &image[100]);
	putimage(100, 170, &image[113]);
	putimage(270, 175, &Player[player].Name[0]); putimage(435, 175, &Player[player].Name[1]);
	putimage(100, 280, &image[103]);
	putimage(100, 390, &image[104]);
	putimage(100, 500, &image[105]);
	putimage(100, 610, &image[106]);
	putimage(100, 720, &image[107]);
	putimage(100, 830, &image[108]);
	putimage(630, 170, &image[110]);
	putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
	putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
	putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
	/*putimage(940, 80, &Player[player].Name[0]); putimage(1110, 80, &Player[player].Name[1]);
	putimage(1280, 80, &Player[player].Name[0]); putimage(1450, 80, &Player[player].Name[1]);
	putimage(1620, 80, &Player[player].Name[0]); putimage(1790, 80, &Player[player].Name[1]);
	putimage(940, 190, &Player[player].Name[0]); putimage(1110, 190, &Player[player].Name[1]);
	putimage(1280, 190, &Player[player].Name[0]); putimage(1450, 190, &Player[player].Name[1]);
	putimage(1620, 190, &Player[player].Name[0]); putimage(1790, 190, &Player[player].Name[1]);
	putimage(940, 300, &Player[player].Name[0]); putimage(1110, 300, &Player[player].Name[1]);
	putimage(1280, 300, &Player[player].Name[0]); putimage(1450, 300, &Player[player].Name[1]);
	putimage(1620, 300, &Player[player].Name[0]); putimage(1790, 300, &Player[player].Name[1]);*/
	putimage(630, 400, &image[101]);
	putimage(630, 650, &image[102]);
	putimage(1570, 1010, &image[109]);
	while (!run)
	{
		if (Windows::input_r())
		{
			input = Windows::INPUT_READ();
			if (input.message == 0x00000201)
			{
				switch (button.button(input.x, input.y, 4))
				{
				case 0xAD1:
					putimage(930, 70, &image[111]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD2:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[111]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD3:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[111]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD4:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[111]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD5:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[111]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD6:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[111]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD7:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[111]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD8:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[111]); putimage(1610, 290, &image[112]);
					break;
				case 0xAD9:
					putimage(930, 70, &image[112]); putimage(1270, 70, &image[112]); putimage(1610, 70, &image[112]);
					putimage(930, 180, &image[112]); putimage(1270, 180, &image[112]); putimage(1610, 180, &image[112]);
					putimage(930, 290, &image[112]); putimage(1270, 290, &image[112]); putimage(1610, 290, &image[111]);
					break;
				case 0xA990:
					//atk_int();
					run = !run;
					break;
				}
			}
		}
		Sleep(1);;
	}
}
void menu::game_run_end(int a, int b)
{
	
}
void menu::putimage(int x, int y, const IMAGE* image)
{
	double r_x = Text_Read["X_size"] / static_cast<double>(1920);
	double r_y = Text_Read["Y_size"] / static_cast<double>(1080);
	::putimage(x * r_x, y * r_y, image);
}
void menu::loadimage(IMAGE* img, LPCTSTR address, double dx, double dy)
{
		double r_x = Text_Read["X_size"] / static_cast<double>(1920);
		double r_y = Text_Read["Y_size"] / static_cast<double>(1080);
		::loadimage(img, address, NULL, NULL, true);
		int x = img->getwidth();
		int y = img->getheight();
		::loadimage(img, address, x * r_x * dx, y * r_y *dy, true);
}
/*********
* 10000 + kf -> exist 11000 + kf -> -exist
* 20000 + kf -> intellect 21000 + kf -> -intellect
* 30000 + kf -> anchored
* 40000 + kf -> affect
* 50000 + kf -> understand
* 60000 + kf -> observatuon
* 
* 
				case 0xA610:
					if (kfp)
					{
						kfp = false;
					}
					break;
				case 0xA620:
					if (kfp)
					{
						kfp = false;
					}
					break;
				case 0xA630:
					if (kfp && player_count >= 3)
					{
						kfp = false;
					}
					break;
				case 0xA640:
					if (kfp && player_count >= 4)
					{
						kfp = false;
					}
					break;
********/