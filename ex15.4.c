#include <stdio.h>

int main(int argc,char*argv[])
{
  if(argc<=1)
  {
    printf("请输入起码一个参数\n");
    return 1;
  }

  char **test=argv;
  int i=0;

  for (i=1;i<argc;i++)
  {
    printf("%s\n",test[i]);
  }

  return 0;
}
