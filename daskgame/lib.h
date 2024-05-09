#pragma once
#include "GUI.h"
namespace sdlt {
	class lib
	{
	public:
		void loade_w();
		void loade_c();
		std::string word_lib(std::string card_v);
		int card_lib(std::string card_v);
	private:
		nlohmann::json word;
		nlohmann::json card;
	};
};
