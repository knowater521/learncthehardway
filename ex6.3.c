#include <stdio.h>

int main(int argc,char *argv[])
{
  int one=155;
  int two=999;
  float three=561.32;
  int four=-500;
  float five=55.315654;
  double six=25.30283925;
  printf("%o\n",one);   /*有符号8进制*/
  printf("%u\n",two);   /*无符号10进制*/
  printf("%X\n",one);   /*无符号16进制*/
  printf("%e\n",three);  /*科学表示格式的浮点数*/
  printf("%g\n",three);
  printf("%d\n",four);
  printf("%f\n",five);
  printf("%g\n",five);
  printf("%f\n",six);
  printf("%e\n",six);
  printf("%g\n",six);
  return 0;
}
