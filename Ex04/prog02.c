#include <stdio.h>
int main()
{
  int x=4, y=7; /* この行は変更しない */
  int *p, *q;

  p = &x;
  q = &y;

  /* 課題では以下のprintf()の中をx,yを使わない形に書き換える */
  /* printf(" Value x: %d  (%p)\n", x, &x );
  printf(" Value y: %d  (%p)\n", y, &y );
  printf(" Sum:     %d\n", x+y );
  printf(" Product: %d\n", x*y );
  */

  printf(" Value x: %d  (%p)\n", *p, p );
  printf(" Value y: %d  (%p)\n", *q, q );
  printf(" Sum:     %d\n", *p+*q );
  printf(" Product: %d\n", *p**q );
  return 0;
}
