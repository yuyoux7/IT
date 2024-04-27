#pragma once
#include "GUI.h"
typedef unsigned long h16;
typedef const char* u_string;
class card
{
public:
	inline static void data_load(u_string locad) {
		std::ifstream lib(locad);
		lib >> data;
	};
	h16 lib(u_string lib);
private:
	inline static nlohmann::json data;
};

