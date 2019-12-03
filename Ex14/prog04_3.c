//入力を代入
#include<stdio.h>
#include"prog04_1.h"
#ifdef TEST
int main(){
  InputTriangle(&abc[0]);


  return 0;
}
#endif


void InputTriangle(Point *trg){
  printf("1st vertex :");
  scanf("%lf%lf",&trg->ax,&trg->ay);
  printf("2nd vertex :");
  scanf("%lf%lf",&trg->bx,&trg->by);
  printf("3rd vertex :");
  scanf("%lf%lf",&trg->cx,&trg->cy);
}
