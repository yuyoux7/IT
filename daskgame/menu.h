#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	IMAGE Name[2]{};
	int Name_NUMBER[2]{};			//名字編號
	bool live{};					//存活狀況
	bool win{};					//勝利情況
	int exist{};					//存在值
	int intellect{};				//理智值
	int anchored{};				//錨定值
	int affect{};					//影響值
	int understand{};				//理解值
	int observatuon{};			//觀測值
	int Race{};					//種族
	int EX_Race{};				//種族
	int Rsp{};					//順位
	std::string u_card{};
	std::string u_magic{};
	std::string u_tao{};
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
	std::string input_string() const;
	void atk_int();
	void image_load(int scenes);
	void scenes_home(int x, int y);
	void default_value(int a, int b);
	int rand_v(const int a = 0, const int b = 0);
	std::string Player_NAME_RAND(const int num);
	void player_set(int x, int y, int player);
	void player_run_scenes();
	void player_card_use(int player);
	void atk_scenes(int player);
	void game_run_end(int a, int b);
	void putimage(int x, int y, const IMAGE* image);
	void loadimage(IMAGE* img, LPCTSTR address, double dx = 1, double dy = 1);
private:
	ExMessage input;
	inline static IMAGE e_number[11];
	inline static IMAGE number[11];
	inline static IMAGE image[500];
	inline static IMAGE Word[500];
};