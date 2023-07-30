#include<iostream>
#include<windows.h>
#include<conio.h>
#define clin scanf_s("%*[^\n]"); scanf_s("%*c");
#define cls system("cls");
#define LV_max 5
using namespace std;
int LV = 1;
int a, b = 3, c = 2, b_up, c_up, step = 0, m = 0;
int point_c1 = 0, point_c2 = 0, point_c3 = 0;
int ip_a_a, ip_a_b, ip_b_a, ip_b_b, ip_c_a, ip_c_b;
int end_point_1_a, end_point_1_b, end_point_2_a, end_point_2_b, end_point_3_a, end_point_3_b;
int ip_a_a1, ip_a_b1, ip_b_a1, ip_b_b1, ip_c_a1, ip_c_b1;
int ip_3_2, ip_3_3, ip_3_4, ip_3_5, ip_3_6, ip_3_7;
int ip_5_2, ip_5_3, ip_5_4, ip_5_5, ip_5_6, ip_5_7;
int ip_7_2, ip_7_3, ip_7_4, ip_7_5, ip_7_6, ip_7_7;
int ip_9_2, ip_9_3, ip_9_4, ip_9_5, ip_9_6, ip_9_7;
int ip_11_2, ip_11_3, ip_11_4, ip_11_5, ip_11_6, ip_11_7;
int ip_13_2, ip_13_3, ip_13_4, ip_13_5, ip_13_6, ip_13_7;
void gotoxy(int x, int y);
int  color(int c);
void show();								//邊界
void IP_OBSTACLE();							//障礙及點位(障礙ip位置為"1"時啟用)
void STAR_IP_BOX();							//初始點
void IP_BACK();								//碰撞
void END_POINT();							//檢查
void Blocks_With_Letters_On();				//主架構
int color(int c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
    return 0;
}
void gotoxy(int x, int y)
{
    COORD c{};
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void show()
{
    int x, y;
    for (x = 0; x <= 17; x++)
    {
        for (y = 0; y <= 9; y++)
        {
            gotoxy(x, y);
            if (y == 0 || y == 9)
            {
                cout << "-";
            }
            else if (x == 0 || x == 17)
            {
                cout << "|";
            }
        }
    }
    for (x = 1; x <= 15; x = x + 2)
    {
        for (y = 1; y <= 8; y++)
        {
            gotoxy(x, y);
            if (y == 1 || y == 8)
            {
                cout << "□";
            }
            else if (x == 1 || x == 15)
            {
                cout << "□";
            }
        }
    }
}
void IP_OBSTACLE()
{
    switch (LV)
    {
    case 1:
        end_point_1_a = 9;
        end_point_1_b = 2;
        end_point_2_a = 13;
        end_point_2_b = 2;
        end_point_3_a = 3;
        end_point_3_b = 7;
        ip_3_2 = 0;
        ip_3_3 = 0;
        ip_3_4 = 1;
        ip_3_5 = 1;
        ip_3_6 = 1;
        ip_3_7 = 0;
        ip_5_2 = 0;
        ip_5_3 = 0;
        ip_5_4 = 0;
        ip_5_5 = 0;
        ip_5_6 = 0;
        ip_5_7 = 0;
        ip_7_2 = 1;
        ip_7_3 = 0;
        ip_7_4 = 0;
        ip_7_5 = 1;
        ip_7_6 = 0;
        ip_7_7 = 0;
        ip_9_2 = 0;
        ip_9_3 = 0;
        ip_9_4 = 0;
        ip_9_5 = 0;
        ip_9_6 = 0;
        ip_9_7 = 0;
        ip_11_2 = 1;
        ip_11_3 = 0;
        ip_11_4 = 1;
        ip_11_5 = 0;
        ip_11_6 = 1;
        ip_11_7 = 0;
        ip_13_2 = 0;
        ip_13_3 = 0;
        ip_13_4 = 0;
        ip_13_5 = 0;
        ip_13_6 = 0;
        ip_13_7 = 0;
        break;
    case 2:
        end_point_1_a = 9;
        end_point_1_b = 4;
        end_point_2_a = 13;
        end_point_2_b = 3;
        end_point_3_a = 3;
        end_point_3_b = 7;
        ip_3_2 = 0;
        ip_3_3 = 0;
        ip_3_4 = 0;
        ip_3_5 = 0;
        ip_3_6 = 0;
        ip_3_7 = 0;
        ip_5_2 = 1;
        ip_5_3 = 0;
        ip_5_4 = 0;
        ip_5_5 = 0;
        ip_5_6 = 0;
        ip_5_7 = 1;
        ip_7_2 = 0;
        ip_7_3 = 0;
        ip_7_4 = 1;
        ip_7_5 = 0;
        ip_7_6 = 0;
        ip_7_7 = 1;
        ip_9_2 = 0;
        ip_9_3 = 0;
        ip_9_4 = 0;
        ip_9_5 = 1;
        ip_9_6 = 0;
        ip_9_7 = 1;
        ip_11_2 = 0;
        ip_11_3 = 1;
        ip_11_4 = 1;
        ip_11_5 = 1;
        ip_11_6 = 0;
        ip_11_7 = 0;
        ip_13_2 = 0;
        ip_13_3 = 0;
        ip_13_4 = 0;
        ip_13_5 = 0;
        ip_13_6 = 0;
        ip_13_7 = 0;
        break;
    case 3:
        end_point_1_a = 9;
        end_point_1_b = 3;
        end_point_2_a = 11;
        end_point_2_b = 5;
        end_point_3_a = 7;
        end_point_3_b = 6;
        ip_3_2 = 0;
        ip_3_3 = 1;
        ip_3_4 = 0;
        ip_3_5 = 0;
        ip_3_6 = 0;
        ip_3_7 = 0;
        ip_5_2 = 0;
        ip_5_3 = 0;
        ip_5_4 = 0;
        ip_5_5 = 1;
        ip_5_6 = 1;
        ip_5_7 = 0;
        ip_7_2 = 0;
        ip_7_3 = 1;
        ip_7_4 = 0;
        ip_7_5 = 0;
        ip_7_6 = 0;
        ip_7_7 = 0;
        ip_9_2 = 0;
        ip_9_3 = 0;
        ip_9_4 = 0;
        ip_9_5 = 0;
        ip_9_6 = 1;
        ip_9_7 = 0;
        ip_11_2 = 0;
        ip_11_3 = 1;
        ip_11_4 = 0;
        ip_11_5 = 0;
        ip_11_6 = 1;
        ip_11_7 = 0;
        ip_13_2 = 0;
        ip_13_3 = 0;
        ip_13_4 = 0;
        ip_13_5 = 0;
        ip_13_6 = 0;
        ip_13_7 = 0;
        break;
    case 4:
        end_point_1_a = 3;
        end_point_1_b = 5;
        end_point_2_a = 13;
        end_point_2_b = 6;
        end_point_3_a = 7;
        end_point_3_b = 7;
        ip_3_2 = 0;
        ip_3_3 = 1;
        ip_3_4 = 0;
        ip_3_5 = 0;
        ip_3_6 = 0;
        ip_3_7 = 1;
        ip_5_2 = 0;
        ip_5_3 = 0;
        ip_5_4 = 0;
        ip_5_5 = 0;
        ip_5_6 = 0;
        ip_5_7 = 0;
        ip_7_2 = 0;
        ip_7_3 = 0;
        ip_7_4 = 1;
        ip_7_5 = 0;
        ip_7_6 = 0;
        ip_7_7 = 0;
        ip_9_2 = 0;
        ip_9_3 = 0;
        ip_9_4 = 0;
        ip_9_5 = 1;
        ip_9_6 = 0;
        ip_9_7 = 0;
        ip_11_2 = 1;
        ip_11_3 = 0;
        ip_11_4 = 0;
        ip_11_5 = 0;
        ip_11_6 = 0;
        ip_11_7 = 0;
        ip_13_2 = 1;
        ip_13_3 = 1;
        ip_13_4 = 0;
        ip_13_5 = 1;
        ip_13_6 = 0;
        ip_13_7 = 0;
        break;
    case 5:
        end_point_1_a = 5;
        end_point_1_b = 3;
        end_point_2_a = 3;
        end_point_2_b = 7;
        end_point_3_a = 9;
        end_point_3_b = 5;
        ip_3_2 = 0;
        ip_3_3 = 0;
        ip_3_4 = 1;
        ip_3_5 = 0;
        ip_3_6 = 0;
        ip_3_7 = 0;
        ip_5_2 = 0;
        ip_5_3 = 0;
        ip_5_4 = 0;
        ip_5_5 = 0;
        ip_5_6 = 0;
        ip_5_7 = 1;
        ip_7_2 = 0;
        ip_7_3 = 0;
        ip_7_4 = 0;
        ip_7_5 = 1;
        ip_7_6 = 0;
        ip_7_7 = 0;
        ip_9_2 = 1;
        ip_9_3 = 0;
        ip_9_4 = 0;
        ip_9_5 = 0;
        ip_9_6 = 0;
        ip_9_7 = 1;
        ip_11_2 = 0;
        ip_11_3 = 0;
        ip_11_4 = 0;
        ip_11_5 = 0;
        ip_11_6 = 0;
        ip_11_7 = 0;
        ip_13_2 = 0;
        ip_13_3 = 0;
        ip_13_4 = 0;
        ip_13_5 = 0;
        ip_13_6 = 0;
        ip_13_7 = 0;
        break;
    }
    if (ip_3_2 == 1)
    {
        gotoxy(3, 2);
        cout << "□";
    }
    if (ip_3_3 == 1)
    {
        gotoxy(3, 3);
        cout << "□";
    }
    if (ip_3_4 == 1)
    {
        gotoxy(3, 4);
        cout << "□";
    }
    if (ip_3_5 == 1)
    {
        gotoxy(3, 5);
        cout << "□";
    }
    if (ip_3_6 == 1)
    {
        gotoxy(3, 6);
        cout << "□";
    }
    if (ip_3_7 == 1)
    {
        gotoxy(3, 7);
        cout << "□";
    }
    if (ip_5_2 == 1)
    {
        gotoxy(5, 2);
        cout << "□";
    }
    if (ip_5_3 == 1)
    {
        gotoxy(5, 3);
        cout << "□";
    }
    if (ip_5_4 == 1)
    {
        gotoxy(5, 4);
        cout << "□";
    }
    if (ip_5_5 == 1)
    {
        gotoxy(5, 5);
        cout << "□";
    }
    if (ip_5_6 == 1)
    {
        gotoxy(5, 6);
        cout << "□";
    }
    if (ip_5_7 == 1)
    {
        gotoxy(5, 7);
        cout << "□";
    }
    if (ip_7_2 == 1)
    {
        gotoxy(7, 2);
        cout << "□";
    }
    if (ip_7_3 == 1)
    {
        gotoxy(7, 3);
        cout << "□";
    }
    if (ip_7_4 == 1)
    {
        gotoxy(7, 4);
        cout << "□";
    }
    if (ip_7_5 == 1)
    {
        gotoxy(7, 5);
        cout << "□";
    }
    if (ip_7_6 == 1)
    {
        gotoxy(7, 6);
        cout << "□";
    }
    if (ip_7_7 == 1)
    {
        gotoxy(7, 7);
        cout << "□";
    }
    if (ip_9_2 == 1)
    {
        gotoxy(9, 2);
        cout << "□";
    }
    if (ip_9_3 == 1)
    {
        gotoxy(9, 3);
        cout << "□";
    }
    if (ip_9_4 == 1)
    {
        gotoxy(9, 4);
        cout << "□";
    }
    if (ip_9_5 == 1)
    {
        gotoxy(9, 5);
        cout << "□";
    }
    if (ip_9_6 == 1)
    {
        gotoxy(9, 6);
        cout << "□";
    }
    if (ip_9_7 == 1)
    {
        gotoxy(9, 7);
        cout << "□";
    }
    if (ip_11_2 == 1)
    {
        gotoxy(11, 2);
        cout << "□";
    }
    if (ip_11_3 == 1)
    {
        gotoxy(11, 3);
        cout << "□";
    }
    if (ip_11_4 == 1)
    {
        gotoxy(11, 4);
        cout << "□";
    }
    if (ip_11_5 == 1)
    {
        gotoxy(11, 5);
        cout << "□";
    }
    if (ip_11_6 == 1)
    {
        gotoxy(11, 6);
        cout << "□";
    }
    if (ip_11_7 == 1)
    {
        gotoxy(11, 7);
        cout << "□";
    }
    if (ip_13_2 == 1)
    {
        gotoxy(13, 2);
        cout << "□";
    }
    if (ip_13_3 == 1)
    {
        gotoxy(13, 3);
        cout << "□";
    }
    if (ip_13_4 == 1)
    {
        gotoxy(13, 4);
        cout << "□";
    }
    if (ip_13_5 == 1)
    {
        gotoxy(13, 5);
        cout << "□";
    }
    if (ip_13_6 == 1)
    {
        gotoxy(13, 6);
        cout << "□";
    }
    if (ip_13_7 == 1)
    {
        gotoxy(13, 7);
        cout << "□";
    }
    gotoxy(end_point_1_a, end_point_1_b);
    cout << "⊙";
    gotoxy(end_point_2_a, end_point_2_b);
    cout << "⊙";
    gotoxy(end_point_3_a, end_point_3_b);
    cout << "⊙";
}
void STAR_IP_BOX()
{
    switch (LV)
    {
    case 1:
        b = 3;
        c = 2;
        ip_a_a = 5;
        ip_a_b = 3;
        ip_b_a = 7;
        ip_b_b = 6;
        ip_c_a = 9;
        ip_c_b = 4;
        break;
    case 2:
        b = 3;
        c = 2;
        ip_a_a = 5;
        ip_a_b = 3;
        ip_b_a = 5;
        ip_b_b = 5;
        ip_c_a = 9;
        ip_c_b = 6;
        break;
    case 3:
        b = 3;
        c = 2;
        ip_a_a = 5;
        ip_a_b = 3;
        ip_b_a = 7;
        ip_b_b = 5;
        ip_c_a = 9;
        ip_c_b = 4;
        break;
    case 4:
        b = 3;
        c = 2;
        ip_a_a = 5;
        ip_a_b = 6;
        ip_b_a = 7;
        ip_b_b = 3;
        ip_c_a = 9;
        ip_c_b = 6;
        break;
    case 5:
        b = 3;
        c = 2;
        ip_a_a = 5;
        ip_a_b = 5;
        ip_b_a = 9;
        ip_b_b = 6;
        ip_c_a = 11;
        ip_c_b = 4;
        break;
    }
}
void IP_BACK()
{
    if (c <= 2)
    {
        c = 2;
    }
    if (c >= 7)
    {
        c = 7;
    }
    if (b <= 3)
    {
        b = 3;
    }
    if (b >= 13)
    {
        b = 13;
    }
    if (b == ip_a_a && c == ip_a_b)
    {
        m = 1;
        ip_a_a = ip_a_a1 + b - b_up;
        ip_a_b = ip_a_b1 + c - c_up;
        if (ip_a_a == ip_b_a && ip_a_b == ip_b_b)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            b = b_up;
            c = c_up;
        }
        if (ip_a_a == ip_c_a && ip_a_b == ip_c_b)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            b = b_up;
            c = c_up;
        }
    }
    if (b == ip_b_a && c == ip_b_b)
    {
        m = 1;
        ip_b_a = ip_b_a1 + b - b_up;
        ip_b_b = ip_b_b1 + c - c_up;
        if (ip_b_a == ip_a_a && ip_b_b == ip_a_b)
        {
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            b = b_up;
            c = c_up;
        }
        if (ip_b_a == ip_c_a && ip_b_b == ip_c_b)
        {
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            b = b_up;
            c = c_up;
        }
    }
    if (b == ip_c_a && c == ip_c_b)
    {
        m = 1;
        ip_c_a = ip_c_a1 + b - b_up;
        ip_c_b = ip_c_b1 + c - c_up;
        if (ip_c_a == ip_b_a && ip_c_b == ip_b_b)
        {
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
            b = b_up;
            c = c_up;
        }
        if (ip_c_a == ip_a_a && ip_c_b == ip_a_b)
        {
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
            b = b_up;
            c = c_up;
        }
    }
    if (ip_a_b <= 1)
    {
        ip_a_b = 2;
        c = c_up;
    }
    if (ip_a_b >= 8)
    {
        ip_a_b = 7;
        c = c_up;
    }
    if (ip_a_a <= 1)
    {
        ip_a_a = 3;
        b = b_up;
    }
    if (ip_a_a >= 15)
    {
        ip_a_a = 13;
        b = b_up;
    }
    if (ip_b_b <= 1)
    {
        ip_b_b = 2;
        c = c_up;
    }
    if (ip_b_b >= 8)
    {
        ip_b_b = 7;
        c = c_up;
    }
    if (ip_b_a <= 1)
    {
        ip_b_a = 3;
        b = b_up;
    }
    if (ip_b_a >= 15)
    {
        ip_b_a = 13;
        b = b_up;
    }
    if (ip_c_b <= 1)
    {
        ip_c_b = 2;
        c = c_up;
    }
    if (ip_c_b >= 8)
    {
        ip_c_b = 7;
        c = c_up;
    }
    if (ip_c_a <= 1)
    {
        ip_c_a = 3;
        b = b_up;
    }
    if (ip_c_a >= 15)
    {
        ip_c_a = 13;
        b = b_up;
    }
    if (ip_3_2 == 1 && ((b == 3 && c == 2) || (ip_a_a == 3 && ip_a_b == 2) || (ip_b_a == 3 && ip_b_b == 2) || (ip_c_a == 3 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_3_3 == 1 && ((b == 3 && c == 3) || (ip_a_a == 3 && ip_a_b == 3) || (ip_b_a == 3 && ip_b_b == 3) || (ip_c_a == 3 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_3_4 == 1 && ((b == 3 && c == 4) || (ip_a_a == 3 && ip_a_b == 4) || (ip_b_a == 3 && ip_b_b == 4) || (ip_c_a == 3 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_3_5 == 1 && ((b == 3 && c == 5) || (ip_a_a == 3 && ip_a_b == 5) || (ip_b_a == 3 && ip_b_b == 5) || (ip_c_a == 3 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_3_6 == 1 && ((b == 3 && c == 6) || (ip_a_a == 3 && ip_a_b == 6) || (ip_b_a == 3 && ip_b_b == 6) || (ip_c_a == 3 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_3_7 == 1 && ((b == 3 && c == 7) || (ip_a_a == 3 && ip_a_b == 7) || (ip_b_a == 3 && ip_b_b == 7) || (ip_c_a == 3 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_2 == 1 && ((b == 5 && c == 2) || (ip_a_a == 5 && ip_a_b == 2) || (ip_b_a == 5 && ip_b_b == 2) || (ip_c_a == 5 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_3 == 1 && ((b == 5 && c == 3) || (ip_a_a == 5 && ip_a_b == 3) || (ip_b_a == 5 && ip_b_b == 3) || (ip_c_a == 5 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_4 == 1 && ((b == 5 && c == 4) || (ip_a_a == 5 && ip_a_b == 4) || (ip_b_a == 5 && ip_b_b == 4) || (ip_c_a == 5 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_5 == 1 && ((b == 5 && c == 5) || (ip_a_a == 5 && ip_a_b == 5) || (ip_b_a == 5 && ip_b_b == 5) || (ip_c_a == 5 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_6 == 1 && ((b == 5 && c == 6) || (ip_a_a == 5 && ip_a_b == 6) || (ip_b_a == 5 && ip_b_b == 6) || (ip_c_a == 5 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_5_7 == 1 && ((b == 5 && c == 7) || (ip_a_a == 5 && ip_a_b == 7) || (ip_b_a == 5 && ip_b_b == 7) || (ip_c_a == 5 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_2 == 1 && ((b == 7 && c == 2) || (ip_a_a == 7 && ip_a_b == 2) || (ip_b_a == 7 && ip_b_b == 2) || (ip_c_a == 7 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_3 == 1 && ((b == 7 && c == 3) || (ip_a_a == 7 && ip_a_b == 3) || (ip_b_a == 7 && ip_b_b == 3) || (ip_c_a == 7 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_4 == 1 && ((b == 7 && c == 4) || (ip_a_a == 7 && ip_a_b == 4) || (ip_b_a == 7 && ip_b_b == 4) || (ip_c_a == 7 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_5 == 1 && ((b == 7 && c == 5) || (ip_a_a == 7 && ip_a_b == 5) || (ip_b_a == 7 && ip_b_b == 5) || (ip_c_a == 7 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_6 == 1 && ((b == 7 && c == 6) || (ip_a_a == 7 && ip_a_b == 6) || (ip_b_a == 7 && ip_b_b == 6) || (ip_c_a == 7 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_7_7 == 1 && ((b == 7 && c == 7) || (ip_a_a == 7 && ip_a_b == 7) || (ip_b_a == 7 && ip_b_b == 7) || (ip_c_a == 7 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_2 == 1 && ((b == 9 && c == 2) || (ip_a_a == 9 && ip_a_b == 2) || (ip_b_a == 9 && ip_b_b == 2) || (ip_c_a == 9 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_3 == 1 && ((b == 9 && c == 3) || (ip_a_a == 9 && ip_a_b == 3) || (ip_b_a == 9 && ip_b_b == 3) || (ip_c_a == 9 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_4 == 1 && ((b == 9 && c == 4) || (ip_a_a == 9 && ip_a_b == 4) || (ip_b_a == 9 && ip_b_b == 4) || (ip_c_a == 9 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_5 == 1 && ((b == 9 && c == 5) || (ip_a_a == 9 && ip_a_b == 5) || (ip_b_a == 9 && ip_b_b == 5) || (ip_c_a == 9 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_6 == 1 && ((b == 9 && c == 6) || (ip_a_a == 9 && ip_a_b == 6) || (ip_b_a == 9 && ip_b_b == 6) || (ip_c_a == 9 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_9_7 == 1 && ((b == 9 && c == 7) || (ip_a_a == 9 && ip_a_b == 7) || (ip_b_a == 9 && ip_b_b == 7) || (ip_c_a == 9 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_2 == 1 && ((b == 11 && c == 2) || (ip_a_a == 11 && ip_a_b == 2) || (ip_b_a == 11 && ip_b_b == 2) || (ip_c_a == 11 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_3 == 1 && ((b == 11 && c == 3) || (ip_a_a == 11 && ip_a_b == 3) || (ip_b_a == 11 && ip_b_b == 3) || (ip_c_a == 11 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_4 == 1 && ((b == 11 && c == 4) || (ip_a_a == 11 && ip_a_b == 4) || (ip_b_a == 11 && ip_b_b == 4) || (ip_c_a == 11 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_5 == 1 && ((b == 11 && c == 5) || (ip_a_a == 11 && ip_a_b == 5) || (ip_b_a == 11 && ip_b_b == 5) || (ip_c_a == 11 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_6 == 1 && ((b == 11 && c == 6) || (ip_a_a == 11 && ip_a_b == 6) || (ip_b_a == 11 && ip_b_b == 6) || (ip_c_a == 11 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_11_7 == 1 && ((b == 11 && c == 7) || (ip_a_a == 11 && ip_a_b == 7) || (ip_b_a == 11 && ip_b_b == 7) || (ip_c_a == 11 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_2 == 1 && ((b == 13 && c == 2) || (ip_a_a == 13 && ip_a_b == 2) || (ip_b_a == 13 && ip_b_b == 2) || (ip_c_a == 13 && ip_c_b == 2)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_3 == 1 && ((b == 13 && c == 3) || (ip_a_a == 13 && ip_a_b == 3) || (ip_b_a == 13 && ip_b_b == 3) || (ip_c_a == 13 && ip_c_b == 3)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_4 == 1 && ((b == 13 && c == 4) || (ip_a_a == 13 && ip_a_b == 4) || (ip_b_a == 13 && ip_b_b == 4) || (ip_c_a == 13 && ip_c_b == 4)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_5 == 1 && ((b == 13 && c == 5) || (ip_a_a == 13 && ip_a_b == 5) || (ip_b_a == 13 && ip_b_b == 5) || (ip_c_a == 13 && ip_c_b == 5)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_6 == 1 && ((b == 13 && c == 6) || (ip_a_a == 13 && ip_a_b == 6) || (ip_b_a == 13 && ip_b_b == 6) || (ip_c_a == 13 && ip_c_b == 6)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    if (ip_13_7 == 1 && ((b == 13 && c == 7) || (ip_a_a == 13 && ip_a_b == 7) || (ip_b_a == 13 && ip_b_b == 7) || (ip_c_a == 13 && ip_c_b == 7)))
    {
        if (m == 1)
        {
            ip_a_a = ip_a_a1;
            ip_a_b = ip_a_b1;
            ip_b_a = ip_b_a1;
            ip_b_b = ip_b_b1;
            ip_c_a = ip_c_a1;
            ip_c_b = ip_c_b1;
        }
        b = b_up;
        c = c_up;
    }
    m = 0;
}
void END_POINT()
{
    point_c1 = 0;
    point_c2 = 0;
    point_c3 = 0;
    if (end_point_1_a == ip_a_a && end_point_1_b == ip_a_b)
    {
        point_c1 = 1;
    }
    if (end_point_1_a == ip_b_a && end_point_1_b == ip_b_b)
    {
        point_c1 = 1;
    }
    if (end_point_1_a == ip_c_a && end_point_1_b == ip_c_b)
    {
        point_c1 = 1;
    }
    if (end_point_2_a == ip_a_a && end_point_2_b == ip_a_b)
    {
        point_c2 = 1;
    }
    if (end_point_2_a == ip_b_a && end_point_2_b == ip_b_b)
    {
        point_c2 = 1;
    }
    if (end_point_2_a == ip_c_a && end_point_2_b == ip_c_b)
    {
        point_c2 = 1;
    }
    if (end_point_3_a == ip_a_a && end_point_3_b == ip_a_b)
    {
        point_c3 = 1;
    }
    if (end_point_3_a == ip_b_a && end_point_3_b == ip_b_b)
    {
        point_c3 = 1;
    }
    if (end_point_3_a == ip_c_a && end_point_3_b == ip_c_b)
    {
        point_c3 = 1;
    }
    if ((point_c1 + point_c2 + point_c3) == 3)
    {
        LV = LV + 1;
        point_c1 = 0;
        point_c2 = 0;
        point_c3 = 0;
        a = 1100;
        ip_a_a = 0;
        ip_a_b = 0;
        ip_b_a = 0;
        ip_b_b = 0;
        ip_c_a = 0;
        ip_c_b = 0;
        if (LV <= LV_max)
        {
            step = 0;
            cls;
            Blocks_With_Letters_On();
        }
    }
}
void Blocks_With_Letters_On()
{
    int move = 0;
    STAR_IP_BOX();
    for (a = 0; a <= 1000; a++)
    {
        b_up = b;
        c_up = c;
        ip_a_a1 = ip_a_a;
        ip_a_b1 = ip_a_b;
        ip_b_a1 = ip_b_a;
        ip_b_b1 = ip_b_b;
        ip_c_a1 = ip_c_a;
        ip_c_b1 = ip_c_b;
        show();
        IP_OBSTACLE();
        gotoxy(ip_a_a, ip_a_b);
        cout << "⊕";
        gotoxy(ip_b_a, ip_b_b);
        cout << "⊕";
        gotoxy(ip_c_a, ip_c_b);
        cout << "⊕";
        gotoxy(50, 12);
        cout << "Game:Blocks With Letters On";
        gotoxy(50, 13);
        cout << "Level max:" << LV_max;
        gotoxy(50, 14);
        cout << "Level:" << LV;
        gotoxy(50, 15);
        cout << "Want to leave Please push [L]" << endl;
        gotoxy(50, 16);
        cout << "Want to retry Please push [R]" << endl;
        gotoxy(50, 17);
        cout << "Want to move Please push [W\\A\\S\\D\\↑\\←\\↓\\→]" << endl;
        gotoxy(50, 18);
        cout << "Max step:1000";
        gotoxy(b, c);
        cout << "■";
        gotoxy(50, 19);
        cout << "Step:" << step;
        gotoxy(50, 20);
        cout << b << "," << c << " " << ip_a_a << "," << ip_a_b << " " << ip_b_a << "," << ip_b_b << " " << ip_c_a << "," << ip_c_b;
        switch (move = _getch())
        {
        case 'A':
        case 'a':
        case 75:
            b = b - 2;
            step++;
            break;
        case 'D':
        case 'd':
        case 77:
            b = b + 2;
            step++;
            break;
        case 'S':
        case 's':
        case 80:
            c = c + 1;
            step++;
            break;
        case 'W':
        case 'w':
        case 72:
            c = c - 1;
            step++;
            break;
        case 'L':
        case 'l':
            a = 1100;
            break;
        case 'R':
        case 'r':
            a = 1100;
            step = 0;
            cls;
            Blocks_With_Letters_On();
            break;
        default:
            a--;
            break;
        }
        Sleep(20);
        IP_BACK();
        END_POINT();
        if (LV > LV_max)
        {
            gotoxy(50, 20);
            cout << "Congratulations";
            a = 1100;
            Sleep(2000);
        }
        cls;
    }
}
int main()
{
    Blocks_With_Letters_On();
}