#include <stdio.h>
#define func(x) ((x)*(x)*(x)-4*(x)+3)

int main()
{
  int a=3;
  double b=1.5;

  //a,bの表示
  printf("a=%d, b=%f\n",a,b);

  //マクロ関数を使った計算
  printf("func(a)=%d\n",func(a));
  printf("func(a+2)=%d\n",func(a+2));
  printf("func(a)*4=%d\n",func(a)*4);
  printf("func(b)=%f\n",func(b));
  printf("func(b+2.5)=%f\n",func(b+2.5));
  return 0;
}
