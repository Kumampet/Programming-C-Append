//３点が三角形を成すかどうかを判定する関数 IsTriangle の作成（prog04_4.c） //
//3点が三角形を成すのであれば0が返り、そうでなければ-1が返ります。//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "prog04_1.h"

int IsTriangle(Point *);

//デバッグエリア//
#ifdef TEST
int main(){
  Point a;
  int judge;

  a.ax=1;
  a.ay=1;
  a.bx=1;
  a.by=3;
  a.cx=4;
  a.cy=1;

  judge=IsTriangle(&a);
  
  if(judge==0){
    printf("与えられた点は三角形を作れます。\n");
  }else printf("与えられた点では三角形は作れません。\n");
  
  return 0;
}
#endif
//デバッグエリア終了//

int IsTriangle(Point *t){
  double dis[3];//三辺の距離を格納

  //三辺の長さの計算//
  //A-B間//
  dis[0]=sqrt(pow(t->bx-t->ax ,2)+pow(t->by-t->ay ,2));
  //B-C間//
  dis[1]=sqrt(pow(t->cx-t->bx ,2)+pow(t->cy-t->by ,2));
  //C-A間//
  dis[2]=sqrt(pow(t->ax-t->cx ,2)+pow(t->ay-t->cy ,2));

  /*
    長辺をAとすると、A<B+Cが成り立てば三角形が作れるらしいので
    それぞれの辺A,B,Cが長い場合で考えて、どれかにマッチングすれば
    三角形が作れるフラグの0を返す。
  */

  if((dis[0]>dis[1])&&(dis[0]>dis[2])){//A-Bが長い時//
    if(dis[0]<dis[1]+dis[2]){
      return 0;
    }
  }else if((dis[1]>dis[0])&&(dis[1]>dis[2])){//B-Cが長い時//
    if(dis[1]<dis[0]+dis[2]){
      return 0;
    }
  }else if((dis[2]>dis[0])&&(dis[2]>dis[1])){//C-Aが長い時//
    if(dis[2]<dis[0]+dis[1]){
      return 0;
    }
  }
  return -1;
}

