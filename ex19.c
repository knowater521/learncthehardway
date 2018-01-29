#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "ex19.h"
#include <assert.h>

int Monster_attack(void *self,int damage)
{
  assert(self!=NULL);
  Monster *monster=self;

  printf("You attack %s!\n",monster->_(description));     //转换为monster->proto.description，这样就可以使用结构体Object的description

  monster->hit_points-=damage;

  if(monster->hit_points>0){
    printf("It is still alive.\n");
    return 0;
  }
  else{
    printf("It is dead!\n");
    return 1;
  }
}

int Monster_init(void *self)
{
  assert(self!=NULL);
  Monster *monster=self;
  monster->hit_points=10;      //初始化Monster中的hit_points
  return 1;
}

Object MonsterProto={
  .init=Monster_init,
  .attack=Monster_attack
};

void *Room_move(void *self,Direction direction)
{
  assert(self!=NULL);
  Room *room=self;
  Room *next=NULL;    //初始化next指针

  if(direction==NORTH && room->north){     //结构体Direction在object.h中
    printf("You go north,into:\n");
    next=room->north;
  }
  else if(direction==SOUTH && room->south){
    printf("You go south,into:\n");
    next=room->south;
  }
  else if(direction==EAST && room->east){
    printf("You go east,into:\n");
    next=room->east;
  }
  else if(direction==WEST && room->west){
    printf("You go west,into:\n");
    next=room->west;
  }
  else{
    printf("不存在这个房间\n");
    exit(1);
  }

  if(next){
    next->_(describe)(next);
  }
  else{
    printf("指针错误\n");
    exit(1);
  }

  return next;
}

int Room_attack(void *self,int damage)
{
  assert(self!=NULL);
  Room *room=self;
  Monster *monster=room->bad_guy;

  if(monster){
    monster->_(attack)(monster,damage);
    return 1;
  }
  else{
    printf("You flail in the air at nothing.Idiot.\n");
    return 0;
  }
}

Object RoomProto={              //创建结构体RoomProto
  .move=Room_move,
  .attack=Room_attack
};

void *Map_move(void *self,Direction direction)
{
  assert(self!=NULL);
  Map *map=self;
  Room *location=map->location;    //map->location实际就是指向结构体Room的指针
  Room *next=NULL;

  next=location->_(move)(location,direction);

  if(next){
    map->location=next;
  }
  else{
    printf("赋值出错\n");
    exit(1);
  }

  return next;
}

int Map_attack(void *self,int damage)
{
  assert(self!=NULL);
  Map *map=self;
  Room *location=map->location;

  assert(location!=NULL);
  return location->_(attack)(location,damage);
}

int Map_init(void *self)
{
  assert(self!=NULL);
  Map *map=self;

  // make some rooms for a small map
  Room *hall=NEW(Room,"The great Hall");
  Room *throne=NEW(Room,"The throne room");
  Room *arena=NEW(Room,"The arena,with the minotaur");
  Room *kitchen=NEW(Room,"Kitchen,you have the knife now");

  assert(hall!=NULL);
  assert(throne!=NULL);
  assert(arena!=NULL);
  assert(kitchen!=NULL);
  // put the bad guy in the arena
  arena->bad_guy=NEW(Monster,"The evil minotaur");
  assert(arena->bad_guy!=NULL);
  // setup the map rooms
  hall->north=throne;

  throne->west=arena;
  throne->east=kitchen;
  throne->south=hall;

  arena->east=throne;
  kitchen->west=throne;

  // start the map and the character off in the hall
  map->start=hall;
  map->location=hall;

  return 1;
}

Object MapProto={
  .init=Map_init,
  .move=Map_move,
  .attack=Map_attack
};

int process_input(Map *game)    //根据用户输入执行不同的函数
{
  assert(game!=NULL);
  printf("\n>");

  char ch=getchar();   //getchar读取用户输入的第一个字符，若出错会返回-1
  getchar();    //eat ENTER

  assert(ch=='n' || ch=='s' || ch=='e' || ch=='w' || ch=='a' || ch=='l');    //解决一开始输入fd等等的字符串后出现的各种bug
  int damage=rand()%4;      //rand()生成伪随机数
  assert(damage>0);

  switch(ch){
    case -1:
      printf("Giving up?You suck.\n");
      return 0;
      break;

    case 'n':
      game->_(move)(game,NORTH);
      break;

    case 's':
      game->_(move)(game,SOUTH);
      break;

    case 'e':
      game->_(move)(game,EAST);
      break;

    case 'w':
      game->_(move)(game,WEST);
      break;

    case 'a':
      game->_(attack)(game,damage);
      break;

    case 'l':
      printf("You can go:\n");
      if(game->location->north)
        printf("NORTH\n");
      if(game->location->south)
        printf("SOUTH\n");
      if(game->location->east)
        printf("EAST\n");
      if(game->location->west)
        printf("WEST\n");
      break;

    default:
      printf("What?:%d\n",ch);
  }

  return 1;
}

int main(int argc,char *argv[])
{
  // simple way to setup the randomness
  srand(time(NULL));      //用当前时间初始化随机数

  // make our map to work with
  Map *game=NEW(Map,"The Hall of the Minotaur.");
  assert(game!=NULL);

  printf("You enter the ");
  game->location->_(describe)(game->location);

  while(process_input(game)){
    }

  return 0;
}
