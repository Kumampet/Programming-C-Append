#include <stdio.h>
#include <stdlib.h>

#define BLACK '1'
#define WHITE '0'

char **pbm_alloc(int, int);
void   pbm_free(char **,int, int);
char **pbm_read(int *, int *);
void   pbm_write(char **, int, int);
char **pbm_erode(char **, int, int);
char **pbm_dilate(char **, int, int);

int main(){
  char **pbm1, **pbm2;
  int ix,iy;

  //printf("[0] Welcome to Tokyo DisneyLand(?)\n");//デバッグ用
  //----標準入力から入力された画像に合わせて領域を確保し読み込む----;
  pbm1 = pbm_read(&ix,&iy);
  //printf("[1] complete read picture...\n");//デバッグ用
  //----入力エラー処理----
  if(pbm1==NULL){
    fprintf(stderr,"Invlid image format.");
    exit(1);
  }

  //--------
    #ifdef ERODE
  //printf("[2]Go to ERODE\n");//デバッグ用
  pbm2=pbm_erode(pbm1,ix,iy);
  //printf("[3]Finished ERODE\n");//デバッグ用
  pbm_free(pbm1,ix,iy);
  //printf("[4]Complete Free pbm1\n");//デバッグ用
    #elif DILATE
  pbm2=pbm_dilate(pbm1,ix,iy);
  pbm_free(pbm1,ix,iy);
    #else
  pbm2=pbm1;
    #endif

  /* 画像を書きだす */
  pbm_write(pbm2,ix,iy);
  //printf("[5]complete output\n");//デバッグ用
  /* 画像領域の解放 */
  pbm_free(pbm2,ix,iy);
  //printf("[6]finished All\n");//デバッグ用
  return 0;
}

char **pbm_read(int *x, int *y){
  int i, j;
  char **data;

  //データ形式の判定
  if(getchar() != 'P' || getchar() != '1'){
    fprintf(stderr, "データの形式が違います！(Not type'P1')\n");
    exit(1);
  }

  //----縦横の画素数を得る----
  scanf("%d",x);
  scanf("%d",y);
  //----二次元配列の生成---
  data = pbm_alloc(*x, *y);
  //----中身の読み込み----
  for(i=0; i<*y; i++){
    for(j=0; j<*x; j++){
      scanf(" %c", &data[i][j]);
    }
  }
  return data;
}

char **pbm_alloc(int x, int y){//書き換え対象
  char **data;
  int i;

  data = (char **)malloc(x * y * sizeof(char));

  if(data==NULL){
    pbm_free(data, x, y);
    return NULL;
  }
  for(i=0; i < y; i++){
    data[i] = (char *)malloc(x * sizeof(char));
  }
  return data;
}

void  pbm_free(char **pbm, int x, int y){//書き換え対象
  free(pbm);
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

char **pbm_erode(char **pbm, int x, int y){//エロージョン
  int i,j;
  char **data;

  //printf("Welcome to ERODE\n");//デバッグ用
  for(i=0; i<y; i++){//行を見る
    for(j=0; j<x; j++){//列を見る
      //printf("data[%d][%d]\n",i,j);//デバッグ用
      printf("[OK]\n");
      if(i==0 || j==x-1){//０行目、もしくは最端の場合の処理
	data[i][j] = pbm[i][j];
      }else{
	if((data[i-1][j])==(data[i][j-1])==(data[i][j+1])
	   ==(data[i+1][j])==BLACK){//着目点の四方が黒だと黒を返す
	  data[i][j]=BLACK;
	  //printf("[OK]\n");//debug
	}else{
	  data[i][j]=WHITE;
	}
      }
    }
  }
  return data;
}

/*
char **pbm_dilate(char **pbm, int x, int y){//ダイレーション
  int i,j;
  char **data;

  return data;
}
*/
