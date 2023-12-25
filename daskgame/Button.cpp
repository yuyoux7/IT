#include "Button.h"
#include <iostream>
#include <WTypesbase.h>
int Button::button(int button_x_up, int button_y_up, int button_x_down, int button_y_down, int ip_x, int ip_y, int list)
{
	if (button_x_up < ip_x && ip_x < button_x_down && button_y_up < ip_y && ip_y < button_y_down)
	{
		switch (list)
		{
		case Button::home:
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
	}
	return 0;
};
int Button::button(int button_main, int ip_x, int ip_y, int list)
{
	if (button_round(button_main, ip_x, ip_y, list))
	{
		switch (list)
		{
		case Button::home:
			return button_round(button_main);
			break;
		case Button::player_set:
			button_round(button_main);
			break;
		case Button::game_round:
			button_round(button_main);
			break;
		case Button::gamecard_set:
			button_round(button_main);
			break;
		case Button::atk_set:
			button_round(button_main);
			break;
		default:
			break;
		}
	};
	return 0;
};
int Button::button_value(int now_value, int value)
{
	return now_value + value;
}
int Button::button_round(int button_number, int __x__, int __y__, int list)
{
	int x_up = 0, y_up = 0, x_down = 0, y_down = 0;
	switch (list)
	{
	case Button::home:
		switch (button_number)
		{
		case 0:
			return true;
		default:
			break;
		}
		break;
	case Button::player_set:
		switch (button_number)
		{
		default:
			break;
		}
		break;
	case Button::game_round:
		switch (button_number)
		{
		default:
			break;
		}
		break;
	case Button::gamecard_set:
		switch (button_number)
		{
		default:
			break;
		}
		break;
	case Button::atk_set:
		switch (button_number)
		{
		default:
			break;
		}
		break;
	default:
		break;
	}
	return false;
}
int Button::button_round(int button_number)
{
	switch (button_number)
	{
	case 0:
		return 1;
	default:
		break;
	}
	return 0;
};
char world_lib_char(const int ch)
{
	char ch_w;
	ch_w = ch ^ 48;
	return ch_w;
}
std::string world_lib_string(const int str)
{
	std::string str_w;
	str_w += str;
	return str_w;
}