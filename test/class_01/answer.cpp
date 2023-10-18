#include <stdio.h>
int x, y, i; char z;
int main(void){
  for(i = 0;i <= 1;i++){
    printf("switch x/y"); scanf("%s", &z);
    if(z == 'x' || z == 'X') {
      printf("set x:"); scanf("%d", &x);}
    else if(z == 'y' || z == 'Y') {
      printf("set y:"); scanf("%d", &y);}}
  printf("x=%d,y=%d", x > 10 ? 1 : 0, y > 10 ? 1 : 0);}
