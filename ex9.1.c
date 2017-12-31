#include <stdio.h>

int main(int argc, char *argv[])
{
  int numbers[4]={0};

  numbers[1]='a';
  numbers[2]='d';

  printf("%d\n", numbers[0]);
  printf("%c\n", numbers[1]);
  printf("%c\n", numbers[2]);
  printf("%d\n", numbers[3]);
}
