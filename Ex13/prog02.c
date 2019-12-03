#include <stdio.h>
#include <math.h>

#define RAD M_PI_2

typedef struct {
  double  x; /* x座標 */
  double  y; /* y座標 */
} Point;

Point rotate_90_1(Point, Point);
void  rotate_90_2(Point, Point *);
Point rotate_90_3(Point *);
void rotate_90_4(Point *);
void rotate_90_5(Point, Point);

Point p5;

int main(){
  Point pc = {4.0, 1.0}, p = {6.0, 4.0}, p1,p2,p3,p4;
  Point p_before[3];

  //----各座標を配列に代入
  p_before[0] = pc;
  p_before[1] = p;

  //----値をそのまま使う----
  p1 = rotate_90_1(pc, p);
  //----ポインタを使う----
  p2 = p;
  rotate_90_2(pc, &p2);
  //----pが書き変わっているのでpを表示するp2へ代入----
  //----p3の処理
  p3 = rotate_90_3(p_before);
  //----p4
  rotate_90_4(p_before);
  p4 = p_before[2];
  //----p5
  printf("%f %f\n",pc.x, p.x);
  rotate_90_5(pc, p);

  printf("rotate_90(1): %f %f\n",p1.x,p1.y);
  printf("rotate_90(2): %f %f\n",p2.x,p2.y);
  printf("rotate_90(3): %f %f\n",p3.x,p3.y);
  printf("rotate_90(4): %f %f\n",p4.x,p4.y);
  printf("rotate_90(5): %f %f\n",p5.x,p5.y);

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


Point rotate_90_3(Point *p){
  Point ans;

  ans.x = (cos(RAD) * (p[1].x - p[0].x)) + (-sin(RAD) * (p[1].y - p[0].y));
  ans.y = (sin(RAD) * (p[1].x - p[0].x)) + (cos(RAD) * (p[1].y - p[0].y));

  ans.x = ans.x+p[0].x;
  ans.y = ans.y+p[0].y;
  
  return ans;
}

void rotate_90_4(Point *p){
  Point temp[2];

  temp[0] = p[0];
  temp[1] = p[1];

  //temp[1].x = (p[1].x-p[0].x)* cos(RAD) + (p[1].y-p[0].y) * (-sin(RAD));
  //temp[1].y = (p[1].x-p[0].x) * sin(RAD) + (p[1].y-p[0].y) * cos(RAD);

  p[2].x = (p[1].x-p[0].x)* cos(RAD) + (p[1].y-p[0].y) * (-sin(RAD)) + temp[0].x;
  p[2].y = (p[1].x-p[0].x) * sin(RAD) + (p[1].y-p[0].y) * cos(RAD) + temp[0].y;
}

void rotate_90_5(Point pc, Point p){
  p5.x = (cos(RAD)*(p.x-pc.x)) + (-sin(RAD)*(p.y-pc.y));
  p5.y = (sin(RAD)*(p.x-pc.x)) + (cos(RAD)*(p.y-pc.y));

  p5.x = p5.x+pc.x;
  p5.y = p5.y+pc.y;
}
