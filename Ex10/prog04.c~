#include <stdio.h>
#include <math.h>

struct xy {
  double  x; /* x座標 */
  double  y; /* y座標 */
};

struct rect {
  struct xy p1;
  struct xy p2;
};

int main()
{
  struct rect  rect1 = {{1.0,5.0},{4.0,1.0}};
  double area, diag, high, width;

  //縦
  high = (double)fabs(rect1.p1.y - rect1.p2.y);
  printf("縦の長さ:%f\n",high);
  //横
  width = (double)fabs(rect1.p1.x - rect1.p2.x);
  printf("横の長さ:%f\n",width);
  //対角線
  diag = pow(high,2)+pow(width,2);
  diag = sqrt(diag);
  printf("対角線の長さ:%f\n",diag);
  //面積
  area = (double)fabs((rect1.p1.x - rect1.p2.x) * 
                     (rect1.p1.y - rect1.p2.y));
  printf("面積:%f\n",area);

  return 0;
}
