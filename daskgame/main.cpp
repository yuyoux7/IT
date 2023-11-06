#include <iostream>
#include <windows.h>
#define max_player 5
#define die_line -100
#define cls system("cls");
int atk_dem, number = 1;
using namespace std;
struct Data
{
    string name;//使用者名稱
    int live;//是否活著
    int lewgue;//理智 6d*2
    int seve;//存在 6d*2
    int inshin;//影響 6d
    int monden;//錨定 100
    int see;//觀測 0
    int san;//理智 100
    int zundun;/*種族
    [1.人 see +5 
     2.神 lewgue +5 
     3.妖 inshin +5 
     4.外 define san 50 
     5.鬼 define monden 50]*/
};
int def(int monden,int zundun)
{
    if(zundun != 5)
    return (monden - 100);
    else
    return 0;
}
int atk(int inshin,int seve)
{
    return (inshin - seve);
}
int atk_int(int atk,int def)
{
    if(atk - def > 0)
    return (atk - def);
    else
    return 0;
}
void atk_real()
{
	Data player[max_player];
    int atk_n = 0,def_n;
    atk_n = atk(player[number].inshin, player[number].seve);
    def_n = def(player[number].monden, player[number].zundun);
    atk_dem = atk_int(atk_n,def_n);
}
int main()
{
    int player_count, out;
    Data player[max_player];
    cout << "Player Count:";
    cin >> player_count;
    if(player_count >= max_player)
    player_count = max_player;
    else if(player_count <= 1)
    player_count = 1;
    for(number = 1;number != player_count + 1;number++)
    {
    cout << "Player Name:";
    cin >> player[number].name;
    cout << number;
    Sleep(1000);
    cls;
    };
    for(out = 0;out != 1;out--)
    {
    cout << "Enter Player Number:";
    cin >> number;
    if(number >= max_player)
    number = max_player;
    else if(number <= 1)
    number = 1;
    cout << "Player Name:" << player[number].name << endl;
    cout << "Player 種族:" << player[number].zundun << endl;
    cout << "Player Live:" << player[number].live << endl;
    cout << atk_dem;
	Sleep(1000);
    cls;
    }
}
