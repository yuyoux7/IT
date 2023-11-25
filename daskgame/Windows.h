#pragma once
#include "GUI.h"
class Windows
{
public:
	Windows(int x,int y,int flog);
	int Window_exit();
	void Title(const std::string& title);
	inline static bool input_r()
	{
		return ::peekmessage(&READ_INPUT_, EX_MOUSE | EX_KEY);
	};
	inline static const ExMessage& INPUT_READ() 
	{
		return READ_INPUT_;
	}
private:
	HWND Window_size;
	inline static ExMessage READ_INPUT_;
};