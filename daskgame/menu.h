#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	IMAGE Name[2];
	int Name_NUMBER[2];			//�W�r�s��
	bool live;					//�s�����p
	bool win;					//�ӧQ���p
	int exist;					//�s�b��
	int intellect;				//�z����
	int anchored;				//��w��
	int affect;					//�v�T��
	int understand;				//�z�ѭ�
	unsigned int observatuon;	//�[����
	int Race;					//�ر�
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