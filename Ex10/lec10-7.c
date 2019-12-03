#include <stdio.h>
#include <time.h>

#define LOOP 200000

struct test { /* 5000文字の文字配列がメンバーの構造体 */
  char  a[5000];
};

void fv(struct test);
void fr(struct test *);

int main(){
  int i;
  struct test testdata;
  time_t start,end;
  double keika;
    
  start = clock();
  for(i = 0; i < LOOP; i++) fv(testdata);     /* 関数呼び出し */
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by value   : %f sec\n",keika); /* 経過時間の表示 */

  start = clock();
  for(i = 0; i < LOOP; i++) fr(&testdata);    /* 関数呼び出し */
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by address : %f sec\n",keika); /* 経過時間の表示 */

  return 0;
}

/* 値渡しの関数 */
void fv(struct test t1) {
  t1.a[0] = 'A';
}

/* アドレス渡しの関数 */
void fr(struct test *t2) 
{
  t2->a[0] = 'A';
}
