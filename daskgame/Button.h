#pragma once
#include <iostream>
#include "GUI.h"
#define List 6
#define Count 0xFFFF
struct Button_ip
{
	double X_ip;
	double Y_ip;
	int button_value;
	std::string fn;
};
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
	int button(int ip_x, int ip_y, int list);
private:
	IMAGE image[500];
};