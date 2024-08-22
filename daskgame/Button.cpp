#include "Button.h"
Button_ip Button_IP[List][Count];
double r_x;
double r_y;
int Button::button(int ip_x, int ip_y, int list)
{
	nlohmann::json Text_Read, set;
	std::ifstream File_Raed("config.json");
	std::ifstream set_file("image_set.json");
	File_Raed >> Text_Read;
	set_file >> set;
	set_file.close();
	File_Raed.close(); 
	int d = NULL;
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	r_x = x / static_cast<double>(1920);
	r_y = y / static_cast<double>(1080);
	IMAGE up, down, start_unp;
	switch (list)
	{
	case Button::home:
		loadimage(&up, static_cast<std::string>(set["home"]["up_button"]).data(), 0xA420, list);
		loadimage(&down, static_cast<std::string>(set["home"]["down_button"]).data(), 0xA430, list);
		loadimage(&start_unp, static_cast<std::string>(set["home"]["start_button_no_push"]).data(), 0xA450, list);
		if (ip_x > 1117 * r_x && ip_x < (1117 * r_x + Button_IP[list][0xA420].X_ip))
		{
			if (ip_y > 619 * r_y && ip_y < (619 * r_y + Button_IP[list][0xA420].Y_ip))
			{
				return Button_IP[list][0xA420].button_value;
			}
		}
		if (ip_x > 1151 * r_x && ip_x < (1151 * r_x + Button_IP[list][0xA430].X_ip))
		{
			if (ip_y > 659 * r_y && ip_y < (659 * r_y + Button_IP[list][0xA430].Y_ip))
			{
				return Button_IP[list][0xA430].button_value;
			}
		}
		if (ip_x > 702 * r_x && ip_x < (702 * r_x + Button_IP[list][0xA450].X_ip))
		{
			if (ip_y > 780 * r_y && ip_y < (780 * r_y + Button_IP[list][0xA450].Y_ip))
			{
				return Button_IP[list][0xA450].button_value;
			}
		}
		break;
	case Button::player_set:
		loadimage(&image[1], static_cast<std::string>(set["player_set"]["race"]["people"]).data(), 0xA510, list);
		loadimage(&image[2], static_cast<std::string>(set["player_set"]["race"]["god"]).data(), 0xA520, list);
		loadimage(&image[3], static_cast<std::string>(set["player_set"]["race"]["monster"]).data(), 0xA530, list);
		loadimage(&image[4], static_cast<std::string>(set["player_set"]["race"]["out_people"]).data(), 0xA540, list);
		loadimage(&image[5], static_cast<std::string>(set["player_set"]["race"]["thinking_people"]).data(), 0xA550, list);
		loadimage(&image[6], static_cast<std::string>(set["player_set"]["race"]["elf"]).data(), 0xA560, list);
		loadimage(&image[7], static_cast<std::string>(set["player_set"]["race"]["bug"]).data(), 0xA570, list);
		loadimage(&image[8], static_cast<std::string>(set["player_set"]["race"]["no_save_monster"]).data(), 0xA580, list);
		loadimage(&image[9], static_cast<std::string>(set["player_set"]["rand"]).data(), 0xA590, list);
		loadimage(&image[0], static_cast<std::string>(set["player_set"]["next"]).data(), 0xA500, list);
		loadimage(&image[10], static_cast<std::string>(set["player_set"]["up"]).data(), 0xB510, list, 0.7);
		loadimage(&image[10], static_cast<std::string>(set["player_set"]["up"]).data(), 0xB511, list, 0.7);
		loadimage(&image[11], static_cast<std::string>(set["player_set"]["down"]).data(), 0xB520, list, 0.7);
		loadimage(&image[11], static_cast<std::string>(set["player_set"]["down"]).data(), 0xB521, list, 0.7);
		if (ip_x > (1920 - 350) * r_x && ip_x < (1920 - 350) * r_x + Button_IP[player_set][0xA500].X_ip)
		{
			if (ip_y > (1080 - 70) * r_y && ip_y < (1080 - 70) * r_y + Button_IP[player_set][0xA500].Y_ip)
			{
				return Button_IP[player_set][0xA500].button_value;
			}
		}
		if (ip_x > 50 * r_x && ip_x < (50 * r_x + Button_IP[player_set][0xA510].X_ip))
		{
			if (ip_y > 370 * r_y && ip_y < (370 * r_y + Button_IP[player_set][0xA510].Y_ip))
			{
				return Button_IP[player_set][0xA510].button_value;
			}
		}
		if (ip_x > 50 * r_x && ip_x < (50 * r_x + Button_IP[player_set][0xA520].X_ip))
		{
			if (ip_y > 520 * r_y && ip_y < (520 * r_y + Button_IP[player_set][0xA520].Y_ip))
			{
				return Button_IP[player_set][0xA520].button_value;
			}
		}
		if (ip_x > 50 * r_x && ip_x < (50 * r_x + Button_IP[player_set][0xA530].X_ip))
		{
			if (ip_y > 670 * r_y && ip_y < (670 * r_y + Button_IP[player_set][0xA530].Y_ip))
			{
				return Button_IP[player_set][0xA530].button_value;
			}
		}
		if (ip_x > 50 * r_x && ip_x < (50 * r_x + Button_IP[player_set][0xA540].X_ip))
		{
			if (ip_y > 820 * r_y && ip_y < (820 * r_y + Button_IP[player_set][0xA540].Y_ip))
			{
				return Button_IP[player_set][0xA540].button_value;
			}
		}
		if (ip_x > 430 * r_x && ip_x < (430 * r_x + Button_IP[player_set][0xA550].X_ip))
		{
			if (ip_y > 370 * r_y && ip_y < (370 * r_y + Button_IP[player_set][0xA550].Y_ip))
			{
				return Button_IP[player_set][0xA550].button_value;
			}
		}
		if (ip_x > 430 * r_x && ip_x < (430 * r_x + Button_IP[player_set][0xA560].X_ip))
		{
			if (ip_y > 520 * r_y && ip_y < (520 * r_y + Button_IP[player_set][0xA560].Y_ip))
			{
				return Button_IP[player_set][0xA560].button_value;
			}
		}
		if (ip_x > 430 * r_x && ip_x < (430 * r_x + Button_IP[player_set][0xA570].X_ip))
		{
			if (ip_y > 670 * r_y && ip_y < (670 * r_y + Button_IP[player_set][0xA570].Y_ip))
			{
				return Button_IP[player_set][0xA570].button_value;
			}
		}
		if (ip_x > 430 * r_x && ip_x < (430 * r_x + Button_IP[player_set][0xA580].X_ip))
		{
			if (ip_y > 820 * r_y && ip_y < (820 * r_y + Button_IP[player_set][0xA580].Y_ip))
			{
				return Button_IP[player_set][0xA580].button_value;
			}
		}
		if (ip_x > 1645 * r_x && ip_x < (1645 * r_x + Button_IP[player_set][0xA590].X_ip))
		{
			if (ip_y > 385 * r_y && ip_y < (385 * r_y + Button_IP[player_set][0xA590].Y_ip))
			{
				return Button_IP[player_set][0xA590].button_value;
			}
		}
		if (ip_x > 1625 * r_x && ip_x < (1625 * r_x + Button_IP[player_set][0xB510].X_ip))
		{
			if (ip_y > 600 * r_y && ip_y < (600 * r_y + Button_IP[player_set][0xB510].Y_ip))
			{
				return Button_IP[player_set][0xB510].button_value;
			}
		}
		if (ip_x > 1625 * r_x && ip_x < (1625 * r_x + Button_IP[player_set][0xB520].X_ip))
		{
			if (ip_y > 640 * r_y && ip_y < (640 * r_y + Button_IP[player_set][0xB520].Y_ip))
			{
				return Button_IP[player_set][0xB520].button_value;
			}
		}
		if (ip_x > 1625 * r_x && ip_x < (1625 * r_x + Button_IP[player_set][0xB511].X_ip))
		{
			if (ip_y > 705 * r_y && ip_y < (705 * r_y + Button_IP[player_set][0xB511].Y_ip))
			{
				return Button_IP[player_set][0xB511].button_value;
			}
		}
		if (ip_x > 1625 * r_x && ip_x < (1625 * r_x + Button_IP[player_set][0xB521].X_ip))
		{
			if (ip_y > 745 * r_y && ip_y < (745 * r_y + Button_IP[player_set][0xB521].Y_ip))
			{
				return Button_IP[player_set][0xB521].button_value;
			}
		}
		break;
	case Button::game_round:
		loadimage(&image[61], static_cast<std::string>(set["game_round"]["first"]).data(), 0xA610, list);
		loadimage(&image[62], static_cast<std::string>(set["game_round"]["second"]).data(), 0xA620, list);
		loadimage(&image[63], static_cast<std::string>(set["game_round"]["third"]).data(), 0xA630, list);
		loadimage(&image[64], static_cast<std::string>(set["game_round"]["forth"]).data(), 0xA640, list);
		loadimage(&image[65], static_cast<std::string>(set["game_round"]["player_block"]).data(), 0xA650, list);
		loadimage(&image[68], static_cast<std::string>(set["game_round"]["next"]).data(), 0xA600, list);
		for (auto i = 0xA651; i < 0xA660; i++)
		{
			Button_IP[list][i].X_ip = Button_IP[list][0xA650].X_ip;
			Button_IP[list][i].Y_ip = Button_IP[list][0xA650].Y_ip;
			Button_IP[list][i].button_value = i;
		}
		if (ip_x > (1920 - 350) * r_x && ip_x < (1920 - 350) * r_x + Button_IP[game_round][0xA600].X_ip)
		{
			if (ip_y > (1080 - 70) * r_y && ip_y < (1080 - 70) * r_y + Button_IP[game_round][0xA600].Y_ip)
			{
				return Button_IP[game_round][0xA600].button_value;
			}
		}
		for (auto i = 0; i < 11; i++)
		{
			if (i > 4)
			{
				d = 150;
				if (ip_x > (150 + ((i - 5) * 350)) * r_x && ip_x < (150 + ((i - 5) * 350)) * r_x + Button_IP[game_round][0xA650 + i].X_ip)
				{

					if (ip_y > (600 + d) * r_y && ip_y < (600 + d) * r_y + Button_IP[game_round][0xA650 + i].Y_ip)
					{
						return Button_IP[game_round][0xA650 + i].button_value;
					}
				}
			}
			else
			{
				if (ip_x > (150 + (i * 350)) * r_x && ip_x < (150 + (i * 350)) * r_x + Button_IP[game_round][0xA650 + i].X_ip)
				{

					if (ip_y > 600 * r_y && ip_y < 600 * r_y + Button_IP[game_round][0xA650 + i].Y_ip)
					{
						return Button_IP[game_round][0xA650 + i].button_value;
					}
				}
			}
		}
		break;
	case Button::gamecard_set:
		loadimage(&image[31], static_cast<std::string>(set["gamecard_set"]["no"]).data(), 0xA710, list);
		loadimage(&image[32], static_cast<std::string>(set["gamecard_set"]["yes"]).data(), 0xA720, list);
		loadimage(&image[33], static_cast<std::string>(set["gamecard_set"]["card"]).data(), 0xA730, list);
		loadimage(&image[34], static_cast<std::string>(set["gamecard_set"]["magic"]).data(), 0xA740, list);
		loadimage(&image[35], static_cast<std::string>(set["gamecard_set"]["taoism"]).data(), 0xA750, list);
		loadimage(&image[36], static_cast<std::string>(set["gamecard_set"]["atk"]).data(), 0xA760, list);
		loadimage(&image[37], static_cast<std::string>(set["gamecard_set"]["next"]).data(), 0xA770, list);
		loadimage(&image[300], static_cast<std::string>(set["gamecard_set"]["move"]).data(), 0xA780, list);
		loadimage(&image[38], static_cast<std::string>(set["gamecard_set"]["delete"]).data(), 0xA700, list);
		if (ip_x > 830 * r_x && ip_x < 830 * r_x + Button_IP[gamecard_set][0xA710].X_ip)
		{
			if (ip_y > 210 * r_y && ip_y < 210 * r_y + Button_IP[gamecard_set][0xA710].Y_ip)
			{
				return Button_IP[gamecard_set][0xA710].button_value;
			}
		}
		if (ip_x > 970 * r_x && ip_x < 970 * r_x + Button_IP[gamecard_set][0xA720].X_ip)
		{
			if (ip_y > 210 * r_y && ip_y < 210 * r_y + Button_IP[gamecard_set][0xA720].Y_ip)
			{
				return Button_IP[gamecard_set][0xA720].button_value;
			}
		}
		if (ip_x > 640 * r_x && ip_x < 640 * r_x + Button_IP[gamecard_set][0xA730].X_ip)
		{
			if (ip_y > 140 * r_y && ip_y < 140 * r_y + Button_IP[gamecard_set][0xA730].Y_ip)
			{
				return Button_IP[gamecard_set][0xA730].button_value;
			}
		}
		if (ip_x > 640 * r_x && ip_x < 640 * r_x + Button_IP[gamecard_set][0xA740].X_ip)
		{
			if (ip_y > 380 * r_y && ip_y < 380 * r_y + Button_IP[gamecard_set][0xA740].Y_ip)
			{
				return Button_IP[gamecard_set][0xA740].button_value;
			}
		}
		if (ip_x > 640 * r_x && ip_x < 640 * r_x + Button_IP[gamecard_set][0xA750].X_ip)
		{
			if (ip_y > 280 * r_y && ip_y < 280 * r_y + Button_IP[gamecard_set][0xA750].Y_ip)
			{
				return Button_IP[gamecard_set][0xA750].button_value;
			}
		}
		if (ip_x > 1570 * r_x && ip_x < 1570 * r_x + Button_IP[gamecard_set][0xA760].X_ip)
		{
			if (ip_y > 900 * r_y && ip_y < 900 * r_y + Button_IP[gamecard_set][0xA760].Y_ip)
			{
				return Button_IP[gamecard_set][0xA760].button_value;
			}
		}
		if (ip_x > 1570 * r_x && ip_x < 1570 * r_x + Button_IP[gamecard_set][0xA770].X_ip)
		{
			if (ip_y > 1010 * r_y && ip_y < 1010 * r_y + Button_IP[gamecard_set][0xA770].Y_ip)
			{
				return Button_IP[gamecard_set][0xA770].button_value;
			}
		}
		if (ip_x > 1100 * r_x && ip_x < 1100 * r_x + Button_IP[gamecard_set][0xA780].X_ip)
		{
			if (ip_y > 380 * r_y && ip_y < 380 * r_y + Button_IP[gamecard_set][0xA780].Y_ip)
			{
				return Button_IP[gamecard_set][0xA780].button_value;
			}
		}
		if (ip_x > 1100 * r_x && ip_x < 1100 * r_x + Button_IP[gamecard_set][0xA700].X_ip)
		{
			if (ip_y > 280 * r_y && ip_y < 280 * r_y + Button_IP[gamecard_set][0xA700].Y_ip)
			{
				return Button_IP[gamecard_set][0xA700].button_value;
			}
		}
		break;
	case Button::atk_set:
		loadimage(&image[109], static_cast<std::string>(set["atk_set"]["next"]).data(), 0xA990, list);
		loadimage(&image[112], static_cast<std::string>(set["atk_set"]["pnch"]).data(), 0xAD0, list);
		for (auto i = 0xAD1; i < 0xADA; i++)
		{
			Button_IP[list][i].X_ip = Button_IP[list][0xAD0].X_ip;
			Button_IP[list][i].Y_ip = Button_IP[list][0xAD0].Y_ip;
			Button_IP[list][i].button_value = i;
		}
		if (ip_x > 1570 * r_x && ip_x < 1570 * r_x + Button_IP[atk_set][0xA990].X_ip)
		{
			if (ip_y > 1010 * r_y && ip_y < 1010 * r_y + Button_IP[atk_set][0xA990].Y_ip)
			{
				return Button_IP[atk_set][0xA990].button_value;
			}
		}
		break;
	default:
		break;
	}
	return 0;
}
void Button::loadimage(IMAGE* img, LPCTSTR address, int value, int list, double a)
{
	::loadimage(img, address);
	Button_IP[list][value].X_ip = img->getwidth() * r_x * a;
	Button_IP[list][value].Y_ip = img->getheight() * r_y * a;
	Button_IP[list][value].button_value = value;
}