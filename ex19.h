#ifndef _ex19_h
#define _ex19_h

#include "object.h"

struct Monster{       //定义结构体Monster
  Object proto;
  int hit_points;
};

typedef struct Monster Monster;    //创建结构体变量Monster

int Monster_attack(void *self,int damage);
int Monster_init(void *self);

struct Room{
  Object proto;       //令Object_new函数可以调用Object结构体的变量，关键在于结构体嵌套，结构体Room里包含结构体Object

  Monster *bad_guy;

  struct Room *north;
  struct Room *south;
  struct Room *east;
  struct Room *west;
};

typedef struct Room Room;

void *Room_move(void *self,Direction direction);
int Room_attack(void *self,int damage);
int Room_init(void *self);

struct Map{
  Object proto;
  Room *start;
  Room *location;
};

typedef struct Map Map;

void *Map_move(void *self,Direction direction);
int Map_attack(void *self,int damage);
int Map_init(void *self);

#endif
