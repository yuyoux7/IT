#pragma once
#include "GUI.h"
class use_apper
{
public:
	void Use_card(std::string card, int player);
	void Use_magic(std::string magic, int player);
	void Use_tao(std::string tao, int player);
	int Player_card_count(int player);
	int Player_card(int player, int local);
	std::string Player_magic(int player);
	std::string Player_tao(int player);
private:
};
