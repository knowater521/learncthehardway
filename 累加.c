#include <stdio.h>

int main()
{
  int a,i;
  int b=1;
  printf("你想要1到几的累加\n");
  scanf("%d",&a);
  for(i=1;i<=a;i++)
  {
    b=b+i;
  }
  printf("根据输入的数字，累加结果为：%d\n", b-1);
}
