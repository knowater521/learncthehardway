#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "object.h"
#include <assert.h>

void Object_destroy(void *self)
{
  Object *obj=self;

  if(obj){
    if(obj->description)
      free(obj->description);
    free(obj);
  }
}

void Object_describe(void *self)
{
  assert(self!=NULL);
  Object *obj=self;
  printf("%s\n",obj->description);
}

int Object_init(void *self)
{
  //do nothing really
  return 1;
}

void *Object_move(void *self,Direction direction)
{
  printf("You can't go that direction.\n");
  return NULL;
}

int Object_attack(void *self,int damage)
{
  printf("You can't attack that.\n");
  return 0;
}

void *Object_new(size_t size,Object proto,char *description)
{
  assert(description!=NULL);
  // setup the default functions in case they aren't set
  if(!proto.init)                    //让函数指针指向对应函数，除了Object_destroy,Object_init,Object_describe外都是为了应付莫名其妙的输入
    proto.init=Object_init;
  if(!proto.describe)
    proto.describe=Object_describe;
  if(!proto.destroy)
    proto.destroy=Object_destroy;
  if(!proto.attack)
    proto.attack=Object_attack;
  if(!proto.move)
    proto.move=Object_move;

  // this seems weird, but we can make a struct of one size,
  // then point a different pointer at it to "cast" it
  Object *el=calloc(1,size);     //在内存中动态地分配 1个长度为 size 的连续空间，并将每一个字节都初始化为 0
  assert(el!=NULL);
  *el=proto;       //在el指向的内存中存放结构体proto，例如Room，然后可以把结构体Room当作结构体Object使用

  // copy the description over
  el->description=strdup(description);

  // initialize it with whatever init we were given
  if(!el->init(el)){      //没有正确初始化的话返回空指针
    // looks like it didn't initialize properly
    el->destroy(el);
    return NULL;
  }
  else{
    // all done, we made an object of any type
    assert(el!=NULL);
    return el;
  }
}
