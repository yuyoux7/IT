#include "card.h"
h16 card::lib(u_string lib)
{
	h16 dtade = 0;
	if (lib[0] == 'F' || lib[0] == 'f')
	{
		dtade = 1;
	}
	else
	{
		lib += 'F';
	}
	switch (lib[dtade])
	{
	case '1':
		return data[lib];
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	case '0':
		break;
	case 'A': case 'a':
		break;
	case 'B': case 'b':
		break;
	case 'C': case 'c':
		break;
	case 'D': case 'd':
		break;
	case 'E': case 'e':
		break;
	case 'F': case 'f':
		break;
	default:
		return 0;
		break;
	}
}
