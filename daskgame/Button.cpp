#include "Button.h"
#include <WTypesbase.h>
Button_ip Button_IP[List][Count];
int Button::button(int ip_x, int ip_y, int list)
{
	nlohmann::json Text_Read;
	std::ifstream File_Raed("config.json");
	File_Raed >> Text_Read;
	File_Raed.close();
	int x = Text_Read["X_size"];
	int y = Text_Read["Y_size"];
	double r_x = x / static_cast<double>(1920);
	double r_y = y / static_cast<double>(1080);
	IMAGE up, down, start_unp;
	switch (list)
	{
	case Button::home:
		loadimage(&up, "./image/home/up.png");
		Button_IP[list][0xA420].X_ip = up.getwidth() * r_x;
		Button_IP[list][0xA420].Y_ip = up.getheight() * r_y;
		Button_IP[list][0xA420].button_value = 0xA420;
		loadimage(&down, "./image/home/down.png");
		Button_IP[list][0xA430].X_ip = down.getwidth() * r_x;
		Button_IP[list][0xA430].Y_ip = down.getheight() * r_y;
		Button_IP[list][0xA430].button_value = 0xA430;
		loadimage(&start_unp, "./image/home/startbutton.png");
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