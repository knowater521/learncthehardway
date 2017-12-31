#include <stdio.h>

int main(int argc, char *argv[])
{
  char name[4]={'a'};

  name[1]=1;
  name[2]=2;

  printf("%c\n", name[0]);
  printf("%d\n", name[1]);
  printf("%d\n", name[2]);
  printf("%d\n", name[3]);
}
