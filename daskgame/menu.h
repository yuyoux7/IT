#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	std::string Name;
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
	void scenes_home();
	void default_value(int a, int b);
	int rand_v(const int a = 0, const int b = 0);
	std::string Player_NAME_RAND(const int num);
	void player_run_scenes();
	void game_run_end();
private:
	ExMessage input;
};
