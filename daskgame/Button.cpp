#include "Button.h"
Button_ip Button_IP[List][Count];
int Button::button(int ip_x, int ip_y, int list)
{
	nlohmann::json Text_Read, set;
	std::ifstream File_Raed("config.json");
	std::ifstream set_file("image_set.json");
	File_Raed >> Text_Read;
	set_file >> set;
	set_file.close();
	File_Raed.close();
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	IMAGE up, down, start_unp;
	switch (list)
	{
	case Button::home:
		loadimage(&up, static_cast<std::string>(set["home"]["up_button"]).data());
		Button_IP[list][0xA420].X_ip = up.getwidth() * r_x;
		Button_IP[list][0xA420].Y_ip = up.getheight() * r_y;
		Button_IP[list][0xA420].button_value = 0xA420;
		loadimage(&down, static_cast<std::string>(set["home"]["down_button"]).data());
		Button_IP[list][0xA430].X_ip = down.getwidth() * r_x;
		Button_IP[list][0xA430].Y_ip = down.getheight() * r_y;
		Button_IP[list][0xA430].button_value = 0xA430;
		loadimage(&start_unp, static_cast<std::string>(set["home"]["start_button_no_push"]).data());
		Button_IP[list][0xA450].X_ip = start_unp.getwidth() * r_x;
		Button_IP[list][0xA450].Y_ip = start_unp.getheight() * r_y;
		Button_IP[list][0xA450].button_value = 0xA450;
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
		loadimage(&image[1], static_cast<std::string>(set["player_set"]["race"]["people"]).data());
		Button_IP[player_set][0xA510].X_ip = image[1].getwidth() * r_x;
		Button_IP[player_set][0xA510].Y_ip = image[1].getheight() * r_y;
		Button_IP[player_set][0xA510].button_value = 0xA510;
		loadimage(&image[2], static_cast<std::string>(set["player_set"]["race"]["god"]).data());
		Button_IP[player_set][0xA520].X_ip = image[2].getwidth() * r_x;
		Button_IP[player_set][0xA520].Y_ip = image[2].getheight() * r_y;
		Button_IP[player_set][0xA520].button_value = 0xA520;
		loadimage(&image[3], static_cast<std::string>(set["player_set"]["race"]["monster"]).data());
		Button_IP[player_set][0xA530].X_ip = image[3].getwidth() * r_x;
		Button_IP[player_set][0xA530].Y_ip = image[3].getheight() * r_y;
		Button_IP[player_set][0xA530].button_value = 0xA530;
		loadimage(&image[4], static_cast<std::string>(set["player_set"]["race"]["out_people"]).data());
		Button_IP[player_set][0xA540].X_ip = image[4].getwidth() * r_x;
		Button_IP[player_set][0xA540].Y_ip = image[4].getheight() * r_y;
		Button_IP[player_set][0xA540].button_value = 0xA540;
		loadimage(&image[5], static_cast<std::string>(set["player_set"]["race"]["thinking_people"]).data());
		Button_IP[player_set][0xA550].X_ip = image[5].getwidth() * r_x;
		Button_IP[player_set][0xA550].Y_ip = image[5].getheight() * r_y;
		Button_IP[player_set][0xA550].button_value = 0xA550;
		loadimage(&image[6], static_cast<std::string>(set["player_set"]["race"]["elf"]).data());
		Button_IP[player_set][0xA560].X_ip = image[6].getwidth() * r_x;
		Button_IP[player_set][0xA560].Y_ip = image[6].getheight() * r_y;
		Button_IP[player_set][0xA560].button_value = 0xA560;
		loadimage(&image[7], static_cast<std::string>(set["player_set"]["race"]["bug"]).data());
		Button_IP[player_set][0xA570].X_ip = image[7].getwidth() * r_x;
		Button_IP[player_set][0xA570].Y_ip = image[7].getheight() * r_y;
		Button_IP[player_set][0xA570].button_value = 0xA570;
		loadimage(&image[8], static_cast<std::string>(set["player_set"]["race"]["no_save_monster"]).data());
		Button_IP[player_set][0xA580].X_ip = image[8].getwidth() * r_x;
		Button_IP[player_set][0xA580].Y_ip = image[8].getheight() * r_y;
		Button_IP[player_set][0xA580].button_value = 0xA580;
		loadimage(&image[0], static_cast<std::string>(set["player_set"]["next"]).data());
		Button_IP[player_set][0xA500].X_ip = image[0].getwidth() * r_x;
		Button_IP[player_set][0xA500].Y_ip = image[0].getheight() * r_y;
		Button_IP[player_set][0xA500].button_value = 0xA500;
		loadimage(&image[9], static_cast<std::string>(set["player_set"]["rand"]).data());
		Button_IP[player_set][0xA590].X_ip = image[9].getwidth() * r_x;
		Button_IP[player_set][0xA590].Y_ip = image[9].getheight() * r_y;
		Button_IP[player_set][0xA590].button_value = 0xA590;
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
		break;
	case Button::game_round:
		break;
	case Button::gamecard_set:
		break;
	case Button::atk_set:
		break;
	default:
		break;
	}
	return 0;
};