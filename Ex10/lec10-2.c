#include <stdio.h>

struct roll {
  char name[30];
  int  birth;
  char address[80];
  int gender; /* 0:man, 1:woman */
};

int main()
{
  struct roll *p, meibo[2] = {
    {"Aizu Taro",19801011,"Aizu Wakamatsu",0},
    {"Fukushima Hanako",19850825,"Fukushima city",1},
  };

  p = &meibo[0]; /* p = meibo; でも良い */
  printf("meibo[0]: %p %p\n", p, &meibo[0]);
  p++;
  printf("meibo[1]: %p %p\n", p, &meibo[1]);
  printf("sizeof(meibo) = %d , sizeof(meibo[1]) = %d\n",
          sizeof(meibo), sizeof(meibo[1]));

  return 0;
}
