#include <stdio.h>

int main(int argc,char*argv[])
{
  int i=0;
  char*states[]={"California","Oregon",
  "Washington","Texas"};
  while(i<argc)
  {
    states[i]=argv[i+1];
    i++;
  }
  for(i=0;i<5;i++)   /*好像states字符串数组不能扩容，要是打印超过第五位的话就会报错*/
  {
  printf("%s\n", states[i]);
  }
}
