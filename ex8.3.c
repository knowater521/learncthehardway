#include <stdio.h>

int main(int argc,char *argv[])
{
  int areas[]={10,12,13,14,20};
  char name[]="Zed";


  areas[0]=name[0];
  printf("%d\n", areas[0]);
  return 0;
}
