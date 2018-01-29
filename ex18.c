#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/** Our old friend die from ex17. */
void die(const char *message)
{
  if(errno){
    perror(message);
  }
  else{
    printf("ERROR:%s\n", message);
  }
  exit(1);
}

// a typedef creates a fake type, in this
// case for a function pointer
typedef int(*compare_cb)(int a,int b);

/**
* A classic bubble sort function that uses the
* compare_cb to do the sorting.
*/
int *bubble_sort(int *numbers,int count,compare_cb cmp)
{
  int temp=0;
  int i=0;
  int j=0;
  int *target=malloc(count * sizeof(int));

  if(!target)
    die("Memory error.");

  memcpy(target,numbers,count * sizeof(int));  //memcpy复制内存内容，遇到"/0"不会结束，返回指向target的void指针

  for(i=0;i<count;i++){
    for(j=0;j<count-1;j++){
      if(cmp(target[j],target[j+1])>0){
        temp=target[j+1];
        target[j+1]=target[j];
        target[j]=temp;
      }
    }
  }
  return target;
}

int sorted_order(int a,int b)         //创建返回整数a-b的函数sorted_order
{
  return a-b;
}

int reverse_order(int a,int b)      //创建返回整数b-a的函数reverse_order
{
  return b-a;
}

int strange_order(int a,int b)       //创建返回整数的函数strange_order，用来取余
{
  if(a==0||b==0){
    return 0;
  }
  else{
    return a%b;
  }
}

/**
* Used to test that we are sorting things correctly
* by doing the sort and printing it out.
*/
void test_sorting(int *numbers,int count,compare_cb cmp)    //第三个参数意味着可以接受函数作为参数
{
  int i=0;
  int *sorted=bubble_sort(numbers,count,cmp);    //创建数组，进行冒泡排序

  if(!sorted)
    die("Fail to sort as requested.");

  for(i=0;i<count;i++){
    printf("%d ",sorted[i]);
  }
  printf("\n");

  free(sorted);

  unsigned char *data=(unsigned char *)cmp;    //进行类型转换

  for(i=0;i<25;i++){
    printf("%02x:\n",data[i]);
  }

  printf("\n");
}

int main(int argc,char *argv[])
{
  if(argc<2)
    die("USAGE: ex18 4 3 1 5 6");

  int count=argc-1;
  int i=0;
  char **inputs=argv+1;

  int *numbers=malloc(count*sizeof(int));   //malloc申请输入参数的内存，count是输入参数的数量，乘与sizeof(int)得到所需要的内存
  if(!numbers)
    die("Memory error.");

  for(i=0;i<count;i++){
    numbers[i]=atoi(inputs[i]);      //用atoi将输入的字符串转化为整数，此处有bug，没对参数进行类型检查
  }

  test_sorting(numbers,count,sorted_order);
  test_sorting(numbers,count,reverse_order);
  test_sorting(numbers,count,strange_order);

  free(numbers);

  return 0;
}
