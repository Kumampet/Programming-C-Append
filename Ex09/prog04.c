#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* マクロ定義 */
#define N     256//キャンバスサイズ
#define RD    64//半径
#define BLACK '1'
#define WHITE '0'

/* 構造体宣言 */
typedef struct{
  int    x;
  int    y;
} XYdata;

/* 関数のプロトタイプ宣言 */
void init(void);
void rev(XYdata);
void circle(XYdata);
void imgout(void);

/* 外部変数の定義 */
char data[N][N];//画素データ

int main(int argc, char *argv[])
{
  XYdata cent;
  int ncent, i;
  
  /* コマンドラインから円の中心座標を何組か入力される */
  
  /* 入力された中心座標が何組あるか計算 */
  ncent = (argc-1)/2 ;
  
  /* 画像初期化関数(すべて白くする)を呼ぶ */
  init();
  
  /* 座標の組の数だけ繰返し… */
  for(i=0; i<ncent; i++){
    cent.x=atoi(argv[2*i+1]);
    cent.y=atoi(argv[2*i+2]);
    /* 円の内部を白黒反転する */
    circle(cent);
  }
  
  /* 表示 */
  imgout();
}

/* すべての点を白に初期化する関数 */
void init(void){
  int i,j;
  for(i=0; i<N; i++){
    for(j=0; j<N; j++){
      data[j][i]=WHITE;
    }
  }
}


/* 引数で指示された座標を中心に,半径 RD 以内の点を白黒反転する関数 */
void circle(XYdata c){
  int i,j;
  
  for(i=c.x-RD; i<=c.x+RD; i++){
    for(j=c.y-RD; j<=c.y+RD; j++){
      if(i>=0&&j>=0&&i<N&&j<N){
	if(pow(RD,2)>=(pow(c.x-i,2)+pow(c.y-j,2))){
	  if(data[i][j]==WHITE){
	    data[i][j]=BLACK;
	  }else data[i][j]=WHITE;
	}
      }
    }
  }
}

/* Plain PBM形式で画像データを出力する関数 */
void imgout(void){
  int i,j;

  //P1と画素数出力
  printf("P1\n");
  printf("%d %d\n",N,N);

  //実際のデータ出力
  for(j=0; j<N; j++){
    for(i=0; i<N; i++){
      printf("%c ",data[i][j]);
    }
    printf("\n");
  }
}
