#include <stdio.h>

int main(int argc,char*argv[])
{
  int i=0;

  if(argc==2)
  {
    printf("You only have one argument.You suck.\n");
  }
  else if(argc>2&&argc<4)
  {
    printf("Here's your arguments:\n");

    for(i=0;i<argc-1;i++)
    {
      printf("%s ", argv[i+1]);
    }
    printf("\n");
  }
  else if(argc>=10)
  {
    printf("You input more than 9 arguments!!!\n");
  }
  else
  {
    printf("You have too many arguments.You suck.\n");
  }
  return 0;
}
