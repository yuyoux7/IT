#include "use_apper.h"
#include "lib.h"
sdlt::lib udt;
data udl[11];
void use_apper::Use_card(std::string card, int player)
{
	bool bl = true;
	if (udt.lib_get(card))
	{
		for (auto j = 0; bl; j++)
		{
			if (udl[player].use_card[j] == 0)
			{
				bl = !bl;
				if (udl[player].use_card[j] == 0)
				{
					for (auto i = 1; i < 5; i++)
					{
						switch (card[i])
						{
						case '0':
							udl[player].use_card[j] += 0;
							break;
						case '1':
							udl[player].use_card[j] += (1 * pow(16, 4 - i));
							break;
						case '2':
							udl[player].use_card[j] += (2 * pow(16, 4 - i));
							break;
						case '3':
							udl[player].use_card[j] += (3 * pow(16, 4 - i));
							break;
						case '4':
							udl[player].use_card[j] += (4 * pow(16, 4 - i));
							break;
						case '5':
							udl[player].use_card[j] += (5 * pow(16, 4 - i));
							break;
						case '6':
							udl[player].use_card[j] += (6 * pow(16, 4 - i));
							break;
						case '7':
							udl[player].use_card[j] += (7 * pow(16, 4 - i));
							break;
						case '8':
							udl[player].use_card[j] += (8 * pow(16, 4 - i));
							break;
						case '9':
							udl[player].use_card[j] += (9 * pow(16, 4 - i));
							break;
						case 'a': case 'A':
							udl[player].use_card[j] += (10 * pow(16, 4 - i));
							break;
						case 'b': case 'B':
							udl[player].use_card[j] += (11 * pow(16, 4 - i));
							break;
						case 'c': case 'C':
							udl[player].use_card[j] += (12 * pow(16, 4 - i));
							break;
						case 'd': case 'D':
							udl[player].use_card[j] += (13 * pow(16, 4 - i));
							break;
						case 'e': case 'E':
							udl[player].use_card[j] += (14 * pow(16, 4 - i));
							break;
						case 'f': case 'F':
							udl[player].use_card[j] += (15 * pow(16, 4 - i));
							break;
						default:
							break;
						}
					}
				}
			}
		}
	}
}
void use_apper::Remove_card(std::string card, int player)
{
	int fldata = NULL;
	bool rf = true;
	if (udt.lib_get(card))
	{
		for (auto i = 1; i < 5; i++)
		{
			switch (card[i])
			{
			case '0':
				fldata += 0;
				break;
			case '1':
				fldata += (1 * pow(16, 4 - i));
				break;
			case '2':
				fldata += (2 * pow(16, 4 - i));
				break;
			case '3':
				fldata += (3 * pow(16, 4 - i));
				break;
			case '4':
				fldata += (4 * pow(16, 4 - i));
				break;
			case '5':
				fldata += (5 * pow(16, 4 - i));
				break;
			case '6':
				fldata += (6 * pow(16, 4 - i));
				break;
			case '7':
				fldata += (7 * pow(16, 4 - i));
				break;
			case '8':
				fldata += (8 * pow(16, 4 - i));
				break;
			case '9':
				fldata += (9 * pow(16, 4 - i));
				break;
			case 'a': case 'A':
				fldata += (10 * pow(16, 4 - i));
				break;
			case 'b': case 'B':
				fldata += (11 * pow(16, 4 - i));
				break;
			case 'c': case 'C':
				fldata += (12 * pow(16, 4 - i));
				break;
			case 'd': case 'D':
				fldata += (13 * pow(16, 4 - i));
				break;
			case 'e': case 'E':
				fldata += (14 * pow(16, 4 - i));
				break;
			case 'f': case 'F':
				fldata += (15 * pow(16, 4 - i));
				break;
			default:
				break;
			}
		}
		for (auto i = 0; i < 0xFF; i++)
		{
			if (udl[player].use_card[i] == fldata && rf)
			{
				udl[player].use_card[i] = NULL;
				for (auto j = i; udl[player].use_card[j + 1] != NULL; j++)
				{
					std::swap(udl[player].use_card[j], udl[player].use_card[j + 1]);
				}
				rf = !rf;
			}
		}
	}
}
void use_apper::Use_magic(std::string magic, int player)
{
	//F9, FA, FB
	int fldata = NULL;
	if (udt.lib_get(magic) && ((magic[1] == '9') || (magic[1] == 'A') || (magic[1] == 'B')))
	{
		for (auto i = 1; i < 5; i++)
		{
			switch (magic[i])
			{
			case '0':
				fldata += 0;
				break;
			case '1':
				fldata += (1 * pow(16, 4 - i));
				break;
			case '2':
				fldata += (2 * pow(16, 4 - i));
				break;
			case '3':
				fldata += (3 * pow(16, 4 - i));
				break;
			case '4':
				fldata += (4 * pow(16, 4 - i));
				break;
			case '5':
				fldata += (5 * pow(16, 4 - i));
				break;
			case '6':
				fldata += (6 * pow(16, 4 - i));
				break;
			case '7':
				fldata += (7 * pow(16, 4 - i));
				break;
			case '8':
				fldata += (8 * pow(16, 4 - i));
				break;
			case '9':
				fldata += (9 * pow(16, 4 - i));
				break;
			case 'a': case 'A':
				fldata += (10 * pow(16, 4 - i));
				break;
			case 'b': case 'B':
				fldata += (11 * pow(16, 4 - i));
				break;
			case 'c': case 'C':
				fldata += (12 * pow(16, 4 - i));
				break;
			case 'd': case 'D':
				fldata += (13 * pow(16, 4 - i));
				break;
			case 'e': case 'E':
				fldata += (14 * pow(16, 4 - i));
				break;
			case 'f': case 'F':
				fldata += (15 * pow(16, 4 - i));
				break;
			default:
				break;
			}
		}
		udl[player].magic = fldata;
	}
}
void use_apper::Use_tao(std::string tao, int player)
{
	//F8
	int fldata = NULL;
	if (udt.lib_get(tao) && tao[1] == '8')
	{
		for (auto i = 1; i < 5; i++)
		{
			switch (tao[i])
			{
			case '0':
				fldata += 0;
				break;
			case '1':
				fldata += (1 * pow(16, 4 - i));
				break;
			case '2':
				fldata += (2 * pow(16, 4 - i));
				break;
			case '3':
				fldata += (3 * pow(16, 4 - i));
				break;
			case '4':
				fldata += (4 * pow(16, 4 - i));
				break;
			case '5':
				fldata += (5 * pow(16, 4 - i));
				break;
			case '6':
				fldata += (6 * pow(16, 4 - i));
				break;
			case '7':
				fldata += (7 * pow(16, 4 - i));
				break;
			case '8':
				fldata += (8 * pow(16, 4 - i));
				break;
			case '9':
				fldata += (9 * pow(16, 4 - i));
				break;
			case 'a': case 'A':
				fldata += (10 * pow(16, 4 - i));
				break;
			case 'b': case 'B':
				fldata += (11 * pow(16, 4 - i));
				break;
			case 'c': case 'C':
				fldata += (12 * pow(16, 4 - i));
				break;
			case 'd': case 'D':
				fldata += (13 * pow(16, 4 - i));
				break;
			case 'e': case 'E':
				fldata += (14 * pow(16, 4 - i));
				break;
			case 'f': case 'F':
				fldata += (15 * pow(16, 4 - i));
				break;
			default:
				break;
			}
		}
		udl[player].tao = fldata;
	}
}
int use_apper::Player_card_count(int player)
{
	int ldata = NULL;
	bool rule = true;
	for (; rule; ldata++)
	{
		if (udl[player].use_card[ldata] == 0)
		{
			if (udl[player].use_card[ldata + 1] == 0)
			{
				if (udl[player].use_card[ldata + 2] == 0)
				{
					if (udl[player].use_card[ldata + 3] == 0)
					{
						rule = !rule;
					}
				}
			}
		}
	}
	return ldata - 1;
}

int use_apper::Player_card(int player, int local)
{
	if (local < 253)
	{
		return udl[player].use_card[local];
	}
	return 0;
}

std::string use_apper::Player_magic(int player)
{
	return std::string();
}

std::string use_apper::Player_tao(int player)
{
	return std::string();
}
