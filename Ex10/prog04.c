#include <stdio.h>
#include <math.h>

//#define PI 3.1415926535;

//struct xy {
//double  x; /* x座標 */
//double  y; /* y座標 */
//};

//struct rect {
//struct xy p1;
//struct xy p2;
//};

//球体の中心座標
typedef struct{
  double x;
  double y;
  double z;
}Point;

//球体の表面を覆う点の座標
typedef struct{
  Point center;
  Point p;
}Sphere;

double RD(Point, Sphere);//半径算出関数
void space(double);//表面積算出＆表示
void vol(double);//体積算出＆表示
//正直関数にしなくてもいい気がするけど････


int main(){
  double value;//体積
  double r;//半径
  Point c;
  Sphere s;
  
  //球の中心座標の入力
  printf("球の中心座標(x,y,z)を入力してください\n");
  scanf("%lf%lf%lf",&c.x, &c.y, &c.z);
  //球の表面上の1点の入力
  printf("球の表面座標(x,y,z)を入力してください\n");
  scanf("%lf%lf%lf",&s.center.x, &s.center.y, &s.center.z);

  //半径算出
  r = RD(c, s);
  printf("r = %f\n",r);

  //表面積＆体積算出
  space(r);
  vol(r);
  
  //printf("%f%f%f\n",c.x, c.y, c.z);
  //面積
  //area = (double)fabs((rect1.p1.x - rect1.p2.x) * 
  //                   (rect1.p1.y - rect1.p2.y));
  //printf("面積:%f\n",area);
  return 0;
}

double RD(Point c, Sphere s){
  double r;
  double x,y,z;//中心と指定点までの3方向の距離の絶対値

  x = (double)fabs(c.x - s.center.x);
  y = (double)fabs(c.y - s.center.y);
  z = (double)fabs(c.z - s.center.z);
  //もっと簡略化できるけど、自分がわからなくなるので････

  r = pow(x,2)+pow(y,2)+pow(z,2);
  r = sqrt(r);

  return r;
}

void space(double r){
  double s;

  s = pow(r,2)*4*M_PI;

  printf("表面積: %f\n",s);
}

void vol(double r){
  double v;

  v = pow(r,3)*4*M_PI;
  v = v/3;
  //身の上に心配ア～ルので参上ｗｗ
  printf("体積: %f\n",v);
}
