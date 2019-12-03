#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLACK '1'
#define WHITE '0'

#define PI 3.14159265358979323846264338
#define XMAX   240  /* 画像の幅   */
#define YMAX   180  /* 画像の高さ */
#define VNUM   5    /* 星の頂点数 */
#define VSKP   2    /* つなぐ頂点の間隔 */
#define RADIUS 50   /* 星の大きさ */

//char  *odata;
char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
void   pbm_fill(char **, int, int, char);
void   pbm_write(char **, int, int);
void   pbm_line(char **, int, int, int, int, int, int, char);

int main(){
  char **pbm;
  int i;
  double sx[VNUM], sy[VNUM];

  /* 240x180の画像を確保する */
  pbm = pbm_alloc(XMAX,YMAX);
  pbm_fill(pbm, XMAX, YMAX, WHITE);

  /* VNUM(=5)角形の頂点の座標を求める       */
  /* 中心(XMAX/2, YMAX/2)、　               */
  /* 半径RADIUSの円を                       */
  /* 360/VNUM度ずつ角度を進めて頂点を求める */
  for(i=0; i<VNUM; i++){
    sx[i] = (int)(XMAX/2.0+RADIUS*sin(2.0*PI/VNUM*i)+0.5);
    sy[i] = (int)(YMAX/2.0-RADIUS*cos(2.0*PI/VNUM*i)+0.5);
  }
  /* 五(VNUM)芒星を書くために    */
  /* VSKP(=2)個先の頂点と線を引く*/
  for(i=0;i<VNUM;i++){
    pbm_line(pbm,XMAX,YMAX,sx[i],sy[i],
             sx[(i+VSKP)%VNUM],sy[(i+VSKP)%VNUM],BLACK);
  }
  /* 画像を書きだす */
  pbm_write(pbm,XMAX,YMAX);
  /* 画像領域の解放 */
  pbm_free(pbm,XMAX,YMAX);
  return 0;
}

char **pbm_alloc(int x, int y){//書き換え対象
  char **data;
  int i;
  //* ２次元配列の作成 */
  //data = malloc(sizeof(char *) * y);
  //if(data == NULL){
  //  return NULL;
  //}
  //odata = malloc(sizeof(char) * x * y);
  ///* 画素数が多すぎる場合 */
  //if (odata == NULL){
  //  free(data);
  //  return NULL;
  //}
  ///* ２次元配列の設定 */
  //for(i = 0; i < y; i++){
  //  data[i] = odata + i * x;
  //}
  data = (char **)malloc(x * y * sizeof(char));
  if(data==NULL){
    pbm_free;
    return NULL;
  }
  for(i=0; i < y; i++){
    data[i] = (char *)malloc(x * sizeof(char));
  }
  return data;
}

void  pbm_free(char **pbm, int x, int y){//書き換え対象
  free(pbm);
  //free(odata);
}

void pbm_fill(char **pbm, int x, int y, char col){
  int i,j;
  for(i=0;i<y;i++)
    for(j=0; j<x; j++)
      pbm[i][j]=col;
}

void   pbm_write(char **pbm, int x, int y){
  int i, j;

  /* 最初にP1とx,yの画素数を出力 */
  printf("P1\n");
  printf("%d %d\n", x, y);

  /* 実際のデータ出力 */
  for (i = 0; i < y; i++){
    for (j = 0; j < x; j++){
      printf("%c", pbm[i][j]);
    }
    printf("\n");
  }
}

/* 画像に線分を引く                         */
/* 始点と終点は画像の範囲を超えてはならない */
void   pbm_line(char **pbm, int x, int y,
                int x1, int y1, int x2, int y2, char col){
  int dx, dy, sign, i;
  float d;

  dx = x2 - x1;
  dy = y2 - y1;
  /* 点のとき */
  if(dx==0 && dy==0){
    pbm[y1][x1] = col;
    return;
  }
  /* 長いほうを基準に線を引く。傾きは１以下になる。*/
  if(abs(dx)>abs(dy)){
    d = (float)dy/dx;
    sign = (dx>0)-(dx<0);
    for(i=x1; i!=x2+sign; i+=sign)
      pbm[(int)(y1+d*(i-x1))][i]=col;
  } else {
    d = (float)dx/dy;
    sign = (dy>0)-(dy<0);
    for(i=y1; i!=y2+sign; i+=sign){
      pbm[i][(int)(x1+d*(i-y1))]=col;
    }
  }
}

/*
 ●変更の概要
ハンドアウト（４）の方式は、２次元配列の保持に(char *)型と(char **)型の二つの変数が必要である。 一方でハンドアウト（３）の方式は、mallocの回数が増えるものの２次元配列の保持を一つの変数でできるため、 配列の管理が簡単になる。ハンドアウトlec8-7とlec08-5.cを参考にして、 テンプレートprog03_template.cのpbm_alloc関数とpbm_free関数を ハンドアウト（３）の方式になるよう変更せよ。 また、メモリの確保に失敗した場合は、エラーを表示せずに、それまでに確保したメモリを解放し、戻り値にNULLを返すようにせよ。

また、書き換える部分と関連する変数を抜粋すると以下のようになる。

char   *odata;
char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);

char **pbm_alloc(int x, int y){
  char **data;
  /* ここを書き換える 
  return data;
}

void  pbm_free(char **pbm, int x, int y){
  /* ここを書き換える 
}

*/
