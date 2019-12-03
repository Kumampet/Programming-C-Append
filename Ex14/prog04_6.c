#include<stdio.h>
#include"prog04_1.h"

#ifdef TEST
int main(){

  abc[0].ax=1.0;
  abc[0].ay=1.0;
  abc[0].bx=1.0;
  abc[0].by=1.0;
  abc[0].cx=1.0;
  abc[0].cy=1.0;

  
  CalcTriangleCentroid(&abc[0]);


  return 0;
}
#endif


void CalcTriangleCentroid(Point *trg){

 trg->x=(trg->ax+trg->bx+trg->cx)/3;
 trg->y=(trg->ay+trg->by+trg->cy)/3;
}
