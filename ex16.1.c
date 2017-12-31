#include <stdio.h>

struct Person
{
  char *name;
  int age;
  int height;
  int weight;
};



int main(int argc,char *argv[]) {
  struct Person joe;
  joe.name="Joe Alex";
  joe.age=32;
  joe.height=64;
  joe.weight=140;
  printf("Name:%s\n", joe.name);
  printf("Age:%d\n", joe.age);
  printf("Height:%d\n", joe.height);
  printf("Weight:%d\n", joe.weight);
  return 0;
}
