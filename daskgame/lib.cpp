#include "lib.h"
void sdlt::lib::loade_w()
{
	std::ifstream data("./text.json");
	data >> word;
	data.close();
}
void sdlt::lib::loade_c()
{
	std::ifstream data("./code_Rv.json");
	data >> card;
	data.close();
}

bool sdlt::lib::lib_get(std::string fn)
{
	loade_w();
	if (fn.size() == 5 && (fn[0] == 'F' || fn[0] == 'f'))
	{
		return word.contains(fn);
	}
	return false;
}

std::string sdlt::lib::fn_get(std::string fn)
{
	loade_w();
	if (lib::lib_get(fn))
	{
		return word[fn];
	}
}

long long sdlt::lib::fc_get(std::string fn)
{
	loade_c();
	long long fc_data = 0;
	if (lib::lib_get(fn))
	{
		for (auto i = 0; i < 18; i++)
		{
			fc_data += (((static_cast<std::string>(card[fn])[i]) ^ 48) * pom(10, 17 - i));
		}
	}
	return fc_data;
}

long long sdlt::lib::pom(int a, unsigned int b)
{
	long long f = a;
	if (b != 0)
	{
		for (auto i = 1; i < b; i++)
		{
			f *= a;
		}
		return f;
	}
	return 1;
}
