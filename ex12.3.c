#include <stdio.h>

int main(int argc, char*argv[])
{
  int i=0;

  // go through each string in argv
  // why am I skipping argv[0]?因为argv的第一位（即argv[0]）是程序名称
  for(i=1;i<argc;i++)    //argc指argv数组中参数的数量
  {
    printf("arg %d:%s\n", i,argv[i]);
  }

  // let's make our own array of strings
  char *states[]={"California","Oregon",
  "Washington","Texas"};
  int num_states=4;

  for(i=0;i<num_states;i++)
  {
    printf("state %d:%s\n", i,states[i]);
    if(i>2)
      break;
  }

  return 0;
}
