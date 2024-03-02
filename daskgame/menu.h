#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	IMAGE Name[2];
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
	void image_load(int scenes, int x, int y);
	void scenes_home(int x, int y);
	void default_value(int a, int b);
	int rand_v(const int a = 0, const int b = 0);
	std::string Player_NAME_RAND(const int num);
	void player_set(int x, int y, int a);
	void player_run_scenes(int x);
	void player_card_use(int x, int y, int a);
	void game_run_end(int a, int b);
private:
	ExMessage input;
	IMAGE number[11];
	IMAGE image[500];
	IMAGE Word[500];
};