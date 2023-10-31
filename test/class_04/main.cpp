#include <stdio.h>
int add(int a,int b)
{
   return (a + b);
}
int main()
{
   int a;
   printf("Enter a number:");
   scanf("%d", &a);
   a = add(a, 10);
   printf("x+10=%d", a);
   return 0;
}