#include <stdio.h>
#include "prog04_1.h" /* (1) */
 /* 必要に応じてプログラムを追加、修正 */


 int main () { /* (2) */
   while(1)
     {
       printf("Input triangle 1:\n");
       /* １番目の三角形の３点を入力する */
       InputTriangle(&abc[0]);
       
       if(IsTriangle(&abc[0])==0) break;
       /* IsTriangleの結果を元に先へ進むか，InputTriangleで再入力へ */
       else printf("These points can not form a triangle!\n");
     }

   printf("Vertex #1: (%lf, %lf)\nVertex #2: (%lf, %lf)\nVertex #3: (%lf, %lf)\n",abc[0].ax,abc[0].ay,abc[0].bx,abc[0].by,abc[0].cx,abc[0].cy);
   
   while(1)
     {
       printf("Input triangle 2:\n");
       /* ２番目の三角形の３点を入力する */
       InputTriangle(&abc[1]);
       
       if(IsTriangle(&abc[1])==0) break;
       /* IsTriangleの結果を元に先へ進むか，InputTriangleで再入力へ */
       else printf("These points can not form a triangle!\n");
     }
   
   printf("Vertex #1: (%lf, %lf)\nVertex #2: (%lf, %lf)\nVertex #3: (%lf, %lf)\n",abc[1].ax,abc[1].ay,abc[1].bx,abc[1].by,abc[1].cx,abc[1].cy);
   
   GetTriangleArea(&abc[0]);
   GetTriangleArea(&abc[1]);
   
   printf("Area 1: %.6lf   Area 2: %.6lf\n",abc[0].s,abc[1].s);
   
   /* 面積の大きい方を表示 */
   if(abc[0].s>abc[1].s) printf("Triangle 1 is larger than triangle 2!\n");
   else printf("Triangle 2 is larger than triangle 1!\n");
   
   CalcTriangleCentroid(&abc[0]);
   CalcTriangleCentroid(&abc[1]);
   printf("Centroid 1: (%.6lf, %.6lf)   Centroid 2: (%.6lf, %.6lf)\n",abc[0].x,abc[0].y,abc[1].x,abc[1].y);
   return 0;
 }

#ifdef TEST
void InputTriangle(Point *p)
{
  p->ax=1.0;
  p->ay=1.0;
  p->bx=1.0;
  p->by=1.0;
  p->cx=1.0;
  p->cy=1.0;
}

int IsTriangle(Point *p)
{
  return 0;
}

void GetTriangleArea(Point *p)
{
  p->s=2.0;
}

void CalcTriangleCentroid(Point *p)
{
  p->x=3.0;
  p->y=4.0;
}

#endif
