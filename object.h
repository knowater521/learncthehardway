#ifndef _object_h      //如果没有定义_object_h，那么就定义它，假如已经有定义的话就跳过
#define _object_h

typedef enum{                             //enum是枚举类型
  NORTH,SOUTH,EAST,WEST       //“创建”了枚举类型的变量Direction（typedef只是起别名而已），包含未定义常量NORTH,SOUTH,EAST,WEST
}Direction;

typedef struct{              //“创建”结构体变量Object
  char *description;
  int (*init)(void *self);   //几个函数指针
  void (*describe)(void *self);
  void (*destroy)(void *self);
  void *(*move)(void *self,Direction direction);
  int (*attack)(void *self,int damage);
}Object;

int Object_init(void *self);    //声明函数
void Object_destroy(void *self);
void Object_describe(void *self);
void *Object_move(void *self,Direction direction);   //函数名前的星号代表会返回指针
int Object_attack(void *self,int damage);
void *Object_new(size_t size,Object proto,char *description);

#define NEW(T, N) Object_new(sizeof(T), T##Proto, N)  //预处理指令（宏），作用是将NEW(T,N)替换为右边的形式
#define _(N) proto.N       //同上面的作用，将_(N)替换为proto.N

#endif
