#include <stdio.h>
#include <math.h>

#define RAD M_PI_2

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_90_1(Point, Point);
void  rotate_90_2(Point, Point *);

int main(){
  Point pc = {4.0, 1.0}, p = {6.0, 4.0}, p1,p2;

  //----値をそのまま使う----
  p1 = rotate_90_1(pc, p);
  //----ポインタを使う----
  rotate_90_2(pc, &p);
  //----pが書き変わっているのでpを表示するp2へ代入----
  p2 = p;

  printf("rotate_90(1): %f %f\n",p1.x,p1.y);
  printf("rotate_90(2): %f %f\n",p2.x,p2.y);

  return 0;
}

Point rotate_90_1(Point center, Point p){
  Point ans;

  //---公式通りの計算----
  //----原点へ移動させて計算----
  ans.x = (cos(RAD)*(p.x-center.x)) + (-sin(RAD)*(p.y-center.y));
  ans.y = (sin(RAD)*(p.x-center.x)) + (cos(RAD)*(p.y-center.y));

  //----移動させた分だけもどす
  ans.x = ans.x+center.x;
  ans.y = ans.y+center.y;
  
  return ans;
}

void rotate_90_2(Point center, Point *p){
  Point temp;

  //----ポインタの書き換え誤爆防止のtempにコピー
  temp = *p;
  //----以下の計算原理はp1のときと同じ
  p->x = (temp.x-center.x)* cos(RAD) + (temp.y-center.y) * (-sin(RAD));
  p->y = (temp.x-center.x) * sin(RAD) + (temp.y-center.y) * cos(RAD);

  p->x = p->x + center.x;
  p->y = p->y + center.y;
}
