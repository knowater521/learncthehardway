#include <stdio.h>

int main(int argc,char *argv[])
{
  char name[]="Zed";
  char full_name[]={
    'Z','e','d',
    ' ','A','.',' ',
    'S','h','a','w','\0'
  };

  name[0]='f';        /*超过一个字符的话，打印出来的第一个字母是这里的最后一个字母*/
  printf("%s\n", name);
  full_name[0]='v';
  printf("%s\n", full_name);

  return 0;
}
