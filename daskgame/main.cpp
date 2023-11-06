#include <iostream>
#define max_player 5
using namespace std;
struct Data
{
    string name;//名稱
    int lewgue;//理解
    int seve;//存在
    int inshin;//影響
    int monden;//錨定
    int see;//觀測
    int san;//理智
};
int main()
{
    int number = 1, player_cout;
    Data player[max_player];
    cin >> player_cout;
    cin >> player[number].name;
    cout << player[number].name;
}