#include <iostream>
#include <windows.h>
#define max_player 5
#define die_line -100
#define cls system("cls");
int atk_dem;
using namespace std;
struct Data
{
    string name;//名稱
    int live = 1;//是否活著
    int lewgue;//理解 6d*2
    int seve;//存在 6d*2
    int inshin;//影響 6d
    int monden = 100;//錨定 100
    int see = NULL;//觀測 0
    int san = 100;//理智 100
    int zundun;/*種族
    [1.人 see +5 
     2.神 lewgue +5 
     3.妖 inshin +5 
     4.污 define san 50 
     5.鬼 define monden 50]*/
};
int def(int monden,int zundun)
{
    if(zundun != 5)
    return (monden - 100);
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
    int atk_n = 0,def_n;
    atk_n = atk(player[number].inshin, player[number].seve);
    def_n = def(player[number].monden, player[number].zundun);
    atk_dem = atk_int(atk_n,def_n);
}
int main()
{
    int number = 1, player_count;
    Data player[max_player];
    cin >> player_count;
    if(player_count >= max_player)
    player_count = max_player;
    else if(player_count <= 1)
    player_count = 1;
    for(number = 1;number <= player_count;number++)
{
    cin >> player[number].name;
    cout << number;
    Sleep(1000);
    cls;
}
    while(true)
    {
    cout << "Enter Player Number:";
    cin >> number;
    cout << "Player Name:" << player[number].name << endl;
    cout << "Player 種族:" << player[number].zundun << endl;
    cout << "Player Live:" << player[number].live ? "YES" : "NO" << endl;
    }
}