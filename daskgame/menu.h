#pragma once
#include "Windows.h"
#include "Button.h"
struct Player_Data
{
	std::string Name;
	bool live;					//�s�����p
	bool win;					//�ӧQ���p
	int exist;					//�s�b��
	int intellect;				//�z����
	int anchored;				//��w��
	int affect;					//�v�T��
	int understand;				//�z�ѭ�
	int observatuon;			//�[����
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
	void default_value(int a);
	int rand_v(const int a);
private:
	ExMessage input;
};

