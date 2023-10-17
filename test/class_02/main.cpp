#include <stdio.h>
int main()
{
  char ch;
  printf("input \ or '");
  scanf("%c", &ch);
  if(ch == '\')
    printf("\");
  else if(ch == ''')
    printf("'");
  else
  {
    printf("please retry");
    main();
  }
}
