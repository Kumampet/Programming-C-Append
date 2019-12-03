#include <stdio.h>

/* マクロ定義 */
#define N 100
#define BLACK '1'
#define WHITE '0'

/* 外部変数の定義 */
char data[N][N];

/* 関数のプロトタイプ宣言 */
void init(void);
void draw(int, int);
void imgout(void);

int main() {
  int i,j;

  init();

  /* 
   * 実行例画像を作成する（ここを作成）
   * 直接配列を操作せず、draw関数を使って配列にアクセスすること
   */
  for(i=0;i<N/2;i++){//左上
    for(j=0;j<N/2;j++){
      if(i >= j){
	draw(i,j);
      }
    }
  }
  for(i=N/2;i<N;i++){//右下
    for(j=N/2;j<N;j++){
      if(i <= j){
	draw(i,j);
      }
    }
  }
  for(i=N/2;i<N;i++){//左下
    for(j=0;j<N-1-i;j++){
      if(i >= j){
	draw(i,j);
      }
    }
  }
  for(i=0;i<N/2;i++){//右上
    for(j=N/2;j<N;j++){
      if(j >= N-i){
	draw(i,j);
      }
    }
  }

  imgout();
  return 0;
}

/* (0,0)から(N-1,N-1) すべての点を白くする  */
void init(void){
  /* 
   * ここを作成
   */
  int i,j;
  
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      data[i][j]=WHITE;
    }
  }
  
}

/* 引数で指示された座標を黒くする */
void draw(int x, int y){
  /* 
   * ここを作成
   */
  data[x][y]=BLACK; 
}

/* Plain PBM形式で画像データを出力する */
void imgout(void)
{
  int i, j;

  /* PBM形式のためのおまじない */
  printf("P1\n");
  printf("%d %d\n", N, N);

  /* 
   * データ出力（ここを作成）
   */
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      printf("%c",data[i][j]);
    }
    printf("\n");
  }
  
}
