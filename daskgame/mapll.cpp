#include "mapll.h"
void mapll::fmpd()
{
	std::ifstream rfmp("./mp_big.json");
	rfmp >> mp;
	rfmp.close();
}

void mapll::turnll_mp(int step, int player)
{
	data[player] = step;
}

int mapll::get_mp(int player)
{
	fmpd();
	int fd = data[player];
	fd -= (int)mp["01"]["step"];
	if (fd <= 0) { return 1; };
	fd -= (int)mp["02"]["step"];
	if (fd <= 0) { return 2; };
	fd -= (int)mp["03"]["step"];
	if (fd <= 0) { return 3; };
	fd -= (int)mp["04"]["step"];
	if (fd <= 0) { return 4; };
	fd -= (int)mp["05"]["step"];
	if (fd <= 0) { return 5; };
	fd -= (int)mp["06"]["step"];
	if (fd <= 0) { return 6; };
	fd -= (int)mp["07"]["step"];
	if (fd <= 0) { return 7; };
	fd -= (int)mp["08"]["step"];
	if (fd <= 0) { return 8; };
	fd -= (int)mp["09"]["step"];
	if (fd <= 0) { return 9; };
	fd -= (int)mp["10"]["step"];
	if (fd <= 0) { return 10; };
	fd -= (int)mp["11"]["step"];
	if (fd <= 0) { return 11; };
	fd -= (int)mp["12"]["step"];
	if (fd <= 0) { return 12; };
	fd -= (int)mp["13"]["step"];
	if (fd <= 0) { return 13; };
	fd -= (int)mp["14"]["step"];
	if (fd <= 0) { return 14; };
	fd -= (int)mp["15"]["step"];
	if (fd <= 0) { return 15; };
	fd -= (int)mp["16"]["step"];
	if (fd <= 0) { return 16; };
	fd -= (int)mp["17"]["step"];
	if (fd <= 0) { return 17; };
	fd -= (int)mp["18"]["step"];
	if (fd <= 0) { return 18; };
	fd -= (int)mp["19"]["step"];
	if (fd <= 0) { return 19; };
	fd -= (int)mp["20"]["step"];
	if (fd <= 0) { return 20; };
	fd -= (int)mp["21"]["step"];
	if (fd <= 0) { return 21; };
	fd -= (int)mp["22"]["step"];
	if (fd <= 0) { return 22; };
	fd -= (int)mp["23"]["step"];
	if (fd <= 0) { return 23; };
	fd -= (int)mp["24"]["step"];
	if (fd <= 0) { return 24; };
	fd -= (int)mp["25"]["step"];
	if (fd <= 0) { return 25; };
	return 0;
}

void mapll::fn_mp(int step)
{
}
