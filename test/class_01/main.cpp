#include<stdio.h>
int x, y;
char z; 
void enter();
void found();
void output();
void enter()
{
    if(z == 'x')
    {
        printf("set x:");
        scanf("%d", x);
    }
    else if(z == 'y')
    {
        printf("set y:");
        scanf("%d", y);
    }
    else if(z == 'X')
    {
        printf("set x:");
        scanf("%d", x);
    }
    else if(z == 'Y')
    {
        printf("set y:");
        scanf("%d", y);
    }
    else
    {
        printf("switch x/y:");
        scanf("%s", z);
    }
    z = 0;
    scanf("%[^\n]"); scanf("%c");
}
void found()
{
    if(x > 10)
    x = 1;
    else
    x = 0;
    if(y > 10)
    y = 1;
    else
    y = 0;
}
void output()
{
    printf("x=%d,y=%d", x, y);
}
int main(void)
{
    int item = 0;
    for(item = 0;item >3;item++)
    {
        enter();
    }
    found();
    output();
}
