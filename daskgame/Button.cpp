#include "Button.h"
#include <iostream>
#include <WTypesbase.h>
int Button::button(int button_x, int button_y, int list)
{
	return 0;
};
int Button::button_value(int now_value, int value)
{
	return now_value + value;
};
char Button::world_lib(const int a)
{
	char ch = a ^ 48;
	return ch;
}