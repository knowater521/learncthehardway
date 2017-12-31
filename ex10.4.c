#include <stdio.h>

int main(int argc, char*argv[])
{
  int i=0;
  char *states[]={"California","Oregon",
  "Washington","Texas"};
  argv[1]=states[1];

  // go through each string in argv
  // why am I skipping argv[0]?因为argv的第一位（即argv[0]）是程序名称
  for(i=1;i<argc;i++)    //argc指argv数组中参数的数量
  {
    printf("arg %d:%s\n", i,argv[i]);
  }

  states[2]=argv[1];   //假如没传递参数的话，states[2]等于程序名

  int num_states=4;

  for(i=0;i<num_states;i++)
  {
    printf("state %d:%s\n", i,states[i]);
  }

  return 0;
}
