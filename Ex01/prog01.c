#include <stdio.h>

int main(){
  char c[20];
  short s[20];
  int i[20];
  long l[20];

  double d[20];

  printf("変数単体の大きさ\n");
  printf("sizeof(char):%d\n",sizeof(c[0]));
  printf("sizeof(short):%d\n",sizeof(s[0]));
  printf("sizeof(int):%d\n",sizeof(i[0]));
  printf("sizeof(long):%d\n",sizeof(l[0]));
  printf("sizeof(double):%d\n",sizeof(d[0]));  
  printf("配列全体の大きさ\n");
  printf("sizeof(char):%d\n",sizeof(c));
  printf("sizeof(short):%d\n",sizeof(s));
  printf("sizeof(int):%d\n",sizeof(i));
  printf("sizeof(long):%d\n",sizeof(l));
  printf("sizeof(double):%d\n",sizeof(d));

  return 0;
}
