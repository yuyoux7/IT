#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	IMAGE Name[2]{};
	int Name_NUMBER[2]{};			//�W�r�s��
	bool live{};					//�s�����p
	bool win{};					//�ӧQ���p
	int exist{};					//�s�b��
	int intellect{};				//�z����
	int anchored{};				//��w��
	int affect{};					//�v�T��
	int understand{};				//�z�ѭ�
	int observatuon{};			//�[����
	int Race{};					//�ر�
	int EX_Race{};				//�ر�
	int Rsp{};					//����
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