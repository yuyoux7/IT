#include <iostream>
#include <windows.h>
#include<cstdlib>
#include<ctime>
/*#include <fstream>
#include <windows.data.json.h>*/
#define max_player 6 //0號位不使用
#define die_line -100
#define false 0
#define true 1
#define cls system("cls");
int atk_dem = NULL, number = 1, turn = 3, run = 1;
int win = false, game_over = false;
using namespace std;
struct Data
{
    string name;//使用者名稱
    int live;//是否活著
    int move;//
    int winner;//是否獲勝
    int lewgue;//理解 6d*2
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
int def(int monden, int zundun)
{
    if (zundun != 5)
        return (monden - 100);
    else
        return 0;
}
int atk_1(int mod_dan, int mod_dff)
{
    return (mod_dan + mod_dff);
}
int atk_int(int atk, int def)
{
    if (atk - def > 0)
        return (atk - def) / 2;
    else
        return 0;
}
int main()
{
    int d = NULL;//骰子數值
    int atk_n = NULL, def_n = NULL, mod = NULL;
    int other_number = NULL, zundun = NULL, fn1 = NULL, add = NULL;
    char ch = NULL;
    srand((unsigned)time(NULL));
    int player_count = NULL, out = NULL;
    Data player[max_player];
    cout << "玩家人數:";
    cin >> player_count;
    if (player_count >= max_player)
    {
        player_count = max_player - 1;
    }
    else if (player_count <= 1)
    {
        player_count = 1;
    }
    cls;
    for (number = 1; number != player_count + 1; number++)
    {
        cout << "玩家名稱:";
        cin >> player[number].name;
        cout << "種族 1.宇宙人族 2.宇宙神族 3.原始妖族 4.域外居民 5.思維體族" << endl << "選擇種族:NO._\b";
        cin >> zundun;
        if (zundun >= 5)
        {
            zundun = 5;
        }
        else if (zundun <= 1)
        {
            zundun = 1;
        }
        player[number].zundun = zundun;
        cout << "六面骰子點數:";
        cin >> d;
        if (d >= 6)
        {
            d = 6;
        }
        else if (d <= 1)
        {
            d = 1;
        }
        cout << "玩家編號:" << number;
        player[number].live = 1;
        player[number].move = 0;
        if (player[number].zundun == 2)
        {
            player[number].lewgue = 2 * d + 5;
        }
        else
        {
            player[number].lewgue = 2 * d;
        }
        if (player[number].zundun == 3)
        {
            player[number].inshin = d + 5;
        }
        else
        {
            player[number].inshin = d;
        }
        if (player[number].zundun == 5)
        {
            player[number].monden = 50;
        }
        else
        {
            player[number].monden = 100;
        }
        if (player[number].zundun == 4)
        {
            player[number].san = 50;
        }
        else
        {
            player[number].san = 100;
        }
        if (player[number].zundun == 1)
        {
            player[number].see = 5;
        }
        else
        {
            player[number].see = 0;
        }
        player[number].seve = 2 * d;
        player[number].winner = false;
        Sleep(2000);
        cls;
    };
    for (out = false; out != true;)
    {
        cout << "\033[6;50H剩餘輪次:" << turn - 1;
        cout << "\033[1;1H輸入玩家編號:";
        cin >> number;
        if (number >= max_player)
            number = max_player - 1;
        else if (number <= 1)
            number = 1;
        if (player[number].inshin <= die_line)
        {
            player[number].live = 0;
        }
        if (player[number].seve <= die_line)
        {
            player[number].live = 0;
        }
        if (player[number].lewgue <= die_line)
        {
            player[number].live = 0;
        }
        cout << "玩家名稱:" << player[number].name << endl;
        switch (player[number].zundun)
        {
        case 1:
            cout << "種族:宇宙人族" << endl;
            break;
        case 2:
            cout << "種族:宇宙神族" << endl;
            break;
        case 3:
            cout << "種族:原始妖族" << endl;
            break;
        case 4:
            cout << "種族:域外居民" << endl;
            break;
        case 5:
            cout << "種族:思維體族" << endl;
            break;
        }
        if (player[number].live)
        {
            cout << "存在狀態:存在" << endl;
            cout << "1.存在值:" << player[number].seve << endl;
            cout << "2.影響值:" << player[number].inshin << endl;
            cout << "3.錨定值:" << player[number].monden << endl;
            cout << "4.理解值:" << player[number].lewgue << endl;
            cout << "5.觀測值:" << player[number].see << endl;
            cout << "6.理智值:" << player[number].san << endl;
            if (player[number].winner == false)
            {
                for (zundun = false; zundun != true;)
                {
                    cout << "沒有數值修改請輸入0" << endl << "需要修改的數值:NO._\b";
                    cin >> fn1;
                    if (fn1 >= 6)
                        fn1 = 6;
                    else if (fn1 <= -1)
                        fn1 = 0;
                    switch (fn1)
                    {
                    case 0:
                        zundun = true;
                        break;
                    case 1:
                        cout << "存在修改值:";
                        cin >> add;
                        player[number].seve += add;
                        break;
                    case 2:
                        cout << "影響修改值:";
                        cin >> add;
                        player[number].inshin += add;
                        break;
                    case 3:
                        cout << "錨定修改值:";
                        cin >> add;
                        player[number].monden += add;
                        break;
                    case 4:
                        cout << "理解修改值:";
                        cin >> add;
                        player[number].lewgue += add;
                        break;
                    case 5:
                        cout << "觀測修改值:";
                        cin >> add;
                        player[number].see += add;
                        break;
                    case 6:
                        cout << "理智修改值:";
                        cin >> add;
                        player[number].san += add;
                        break;
                    }
                    if (fn1 != 0)
                    {
                        cout << "是否繼續修改數值[Y/N]:";
                        cin >> ch;
                        if (ch == 'y' || ch == 'Y')
                        {
                            zundun = false;
                        }
                        else
                        {
                            zundun = true;
                        }
                    }
                }
                if (player[number].move != 0)
                {
                    cout << "是否攻擊玩家[Y/N]:";
                    cin >> ch;
                    if (ch == 'y' || ch == 'Y')
                    {
                        for (fn1 = false; fn1 != true;)
                        {
                            cout << "輸入玩家編號為自身編號，取消攻擊" << endl << "選擇玩家編號:NO._\b";
                            cin >> other_number;
                            if (other_number == number)
                            {
                                fn1 = true;
                                cout << "無法攻擊自己，攻擊失敗。";
                            }
                            cout << "選擇攻擊力判定" << endl << "1.影響值+觀測值" << endl << "2.理解值+觀測值" << endl << "3.理解值+影響值" << endl << "選擇攻擊力判定方式:_\b";
                            cin >> mod;
                            cout << "選擇攻擊對方數值" << endl << "1.存在值" << endl << "2.影響值" << endl << "3.理解值" << endl << "4.觀測值" << endl << "選擇攻擊判定數值:_\b";
                            cin >> add;
                            cout << "是否持有無視防禦[Y/N]:_\b";
                            cin >> ch;
                            if (other_number != number && other_number <= player_count && other_number >= 1)
                            {
                                switch (mod)
                                {
                                case 1:
                                    atk_n = atk_1(player[number].inshin, player[number].see);
                                    break;
                                case 2:
                                    atk_n = atk_1(player[number].lewgue, player[number].see);
                                    break;
                                case 3:
                                    atk_n = atk_1(player[number].inshin, player[number].lewgue);
                                    break;
                                }
                                if (ch == 'y' || ch == 'Y')
                                    def_n = def(player[other_number].monden, player[other_number].zundun);
                                else
                                    def_n = 0;
                                atk_dem = atk_int(atk_n, def_n);
                                if (atk_dem <= 0 || player[other_number].winner == true)
                                {
                                    cout << "攻擊失敗" << endl;
                                    fn1 = true;
                                }
                                else
                                {
                                    cout << "發動攻擊" << endl << "對" << player[other_number].name << "造成傷害:" << -atk_dem << endl;
                                    switch (add)
                                    {
                                    case 1:
                                        player[other_number].seve -= atk_dem;
                                        break;
                                    case 2:
                                        player[other_number].inshin -= atk_dem;
                                        break;
                                    case 3:
                                        player[other_number].lewgue -= atk_dem;
                                        break;
                                    case 4:
                                        player[other_number].see -= atk_dem;
                                        break;
                                    }
                                    fn1 = true;
                                }
                            }
                            else if (other_number == number)
                            {
                                fn1 = true;
                            }
                            else
                                cout << "查無此人，請重新輸入" << endl;
                        }
                    }
                }
            }
            else if (player[number].winner)
            {
                cout << "已獲勝" << endl;
            }
        }
        else
        {
            cout << "存在狀態:消失" << endl;
        }
        if (player[number].inshin <= die_line)
        {
            cout << player[number].name << "對世界影響力消失";
            Sleep(1000);
        }
        if (player[number].seve <= die_line)
        {
            cout << player[number].name << "的存在完全消失";
            Sleep(1000);
        }
        if (player[number].lewgue <= die_line)
        {
            cout << player[number].name << "被世界厭惡而排斥到虛空中";
            Sleep(1000);
        }
        if (run == player_count)
        {
            turn--;
            run = 0;
        }
        player[number].move += 1;
        if (player[number].winner == false || player[number].live == 1)
        {
            run++;
        }
        Sleep(2000);
        cls;
        if(player[number].san <= -100 || player[number].lewgue >= 100 || player[number].inshin >= 100 || turn == 0)
        { 
            if (turn != 0)
            {
                player[number].winner = true;
                win = true;
            }
            if (turn == 0)
            {
                game_over = true;
            }
        }
        if (player[number].monden <= -100 || player[number].seve >= 100 || player[number].see >= 100)
        {
            player[number].winner = true;
        }
        if (win == true || game_over == true)
        {
            out = true;
        }
    }
    cout << "遊戲結束";
}
