#include <stdio.h>

struct roll {
  char name[30];
  int  birth;
  char address[80];
  int gender; /* 0:man, 1:woman */
};

int main()
{
  int i;
  struct roll *p, *q, meibo[2] = {
    {"Aizu Taro",19801011,"Aizu Wakamatsu",0},
    {"Fukushima Hanako",19850825,"Fukushima city",1},
  };

  p = meibo;

  for(i = 0; i < 2; i++){
    printf("%s\n", (*(p + i)).name);
    printf("%d\n", (*(p + i)).birth);
    printf("%s\n", (*(p + i)).address);
    printf("%d\n", (*(p + i)).gender);
  }

  for(i = 0; i < 2; i++){
    printf("%s\n", (p + i)->name);
    printf("%d\n", (p + i)->birth);
    printf("%s\n", (p + i)->address);
    printf("%d\n", (p + i)->gender);
  }

  for(q = p; q < p + 2; q++){
    printf("%s\n", (*q).name);
    printf("%d\n", (*q).birth);
    printf("%s\n", (*q).address);
    printf("%d\n", (*q).gender);
  }

  for(q = p; q < p + 2; q++){
    printf("%s\n", q->name);
    printf("%d\n", q->birth);
    printf("%s\n", q->address);
    printf("%d\n", q->gender);
  }
  return 0;
}
