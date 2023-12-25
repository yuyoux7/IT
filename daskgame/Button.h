#pragma once
#include <iostream>
class Button
{
	enum button_list
	{
		home,
		player_set,
		game_round,
		gamecard_set,
		atk_set
	};
public:
	int button(int button_x_up, int button_y_up, int button_x_down, int button_y_down, int ip_x, int ip_y, int list);
	int button(int button_main, int ip_x, int ip_y, int list);
	int button_value(int now_value, int value);
	int button_round(int button_number, int __x__, int __y__, int list);
	int button_round(int button_number);
private:
};
char world_lib_char(const int ch);
std::string world_lib_string(const int str);