#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	std::string Name;
	int Name_NUMBER[2];			//名字編號
	bool live;					//存活狀況
	bool win;					//勝利情況
	int exist;					//存在值
	int intellect;				//理智值
	int anchored;				//錨定值
	int affect;					//影響值
	int understand;				//理解值
	unsigned int observatuon;	//觀測值
	int Race;					//種族
};
class menu
{
	enum line
	{
		atk,
		def,
		player,
		card,
		scenes
	};
public:
	void Menu();
	std::string input_string(int a);
	void atk_int();
	void scenes_home();
	void default_value(int a, int b);
	int rand_v(const int a = 0, const int b = 0);
	std::string Player_NAME_RAND(const int num);
	void player_run_scenes();
	void game_run_end();
private:
	ExMessage input;
};
