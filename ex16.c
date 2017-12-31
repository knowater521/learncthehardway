#include <stdio.h>
#include <assert.h>    /*包含assert*/
#include <stdlib.h>     /*包含free，malloc*/
#include <string.h>    /*包含strdup*/

struct Person{
  char *name;
  int age;
  int height;
  int weight;
};

struct Peson *Person_create(char *name,int age,int height,int weight)  //创建了一个叫Person_create的函数
{
  struct Person *who=malloc(sizeof(struct Person));  //创建叫做who的指针，malloc返回指向Person的内存的指针
  assert(who!=NULL);    //验证获得的是不是有效的内存，NULL是无效指针

  who->name=strdup(name);     //strdup复制字符串，这几行用于赋值，我或许可以将它们理解为oop里的创建对象？
  who->age=age;
  who->height=height;
  who->weight=weight;

  return who;       //这里返回的who指针变量在下面使用时被赋值到另一个变量中，并作为参数传递到Person_destroy和Person_print函数
}

void Person_destroy(struct Person *who)
{
  assert(who!=NULL);

  free(who->name);        //用free来释放内存，为什么这里要另外释放name
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name:%s\n",who->name);
  printf("\tAge:%d\n",who->age);
  printf("\tHeight:%d\n",who->height);
  printf("\tWeight:%d\n",who->weight);
}

int main(int argc,char *argv[])
{
  struct Person *joe=Person_create("Joe Alex",32,64,140);     //将指针变量赋值给joe
  struct Person *frank=Person_create("Frank Blank",20,72,180);

  // print them out and where they are in memory
  printf("Joe is at memory location %p:\n",joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n",frank);
  Person_print(frank);

  // make everyone age 20 years and print them again
  joe->age+=20;
  joe->height-=2;
  joe->weight+=40;
  Person_print(joe);

  frank->age+=20;
  frank->weight+=20;
  Person_print(frank);

  // destroy them both so we clean up
  Person_destroy(joe);
  Person_destroy(frank);

  return 0;
}
