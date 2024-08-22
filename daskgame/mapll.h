#pragma once
#include "GUI.h"
class mapll
{
public:
	void fmpd();
	void turnll_mp(int step, int player);
	int get_mp(int player);
	void fn_mp(int step);
private:
	int data[11]{};
	nlohmann::json mp{};
};

