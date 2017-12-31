#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*这堆代码需要修正*/
// forward declarations
int can_print_it(char ch);
void print_letters(char arg[],int x);

void print_arguments(int argc,char*argv[])
{
  int i=0;

  for(i=0;i<argc;i++)
  {
    int x=strlen(argv[i]);
    print_letters(argv[i],x);
  }
}

void print_letters(char arg[],int x)
{
  int i=0;

  for(i=0;arg[i]!='\0';i++)
  {
    char ch=arg[i];

    if(can_print_it(ch)&&x==2)    //只处理有仅含两个字母的参数
    {
      printf("'%c' == %d", ch,ch);
    }
  }
  printf("\n");
}

int can_print_it(char ch)
{
  return isalpha(ch)||isblank(ch);
}

int main(int argc,char*argv[])
{
  print_arguments(argc,argv);
  return 0;
}
