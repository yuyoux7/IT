#pragma once
#include "GUI.h"
namespace sdlt {
	class lib
	{
	public:
		void loade_w();
		void loade_c();
		bool lib_get(std::string fn);
		std::string fn_get(std::string fn);
		long long fc_get(std::string fn);
		long long pom(int a, unsigned int b);
	private:
		nlohmann::json word;
		nlohmann::json card;
	};
};
