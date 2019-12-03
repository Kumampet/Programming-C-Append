#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int x;        /* アリの位置（横） */
  int y;        /* アリの位置（縦） */
  char dr;      /* 'R':右向き  'D':下向き */
  int in;       /* 1:アリは盤上にいる 0:既に盤外に出ている */
}AntPos;

int main(int argc, char *argv[])
{
  int w, h, n;  /* 幅、高さ、初期状態でのアリの数 */
  int t=0;      /* 時間ステップのカウンタ */
  int i=0, j, num;
  AntPos *ant;
  FILE *fp;

  if (argc < 2) {
    printf( "error: input file name is required!\n");
    exit(1);
  }
  //----ファイルオープン----
  fp = fopen(argv[1], "r");
  if(fp == NULL){
    fprintf(stderr, "File Open Error.\n");
  }
  
  //----ファイルの1行目から盤の幅w、高さh、アリの数nを読み込む----
  if(3!=fscanf(fp, "%d%d%d",&w,&h,&n)){
    //----エラー＝処理----
    printf("File scan Error!!\n");
    exit(0);
  }
  //----読み込んだ盤面情報とアリの数を表示----
  printf("横幅:%d 高さ:%d アリの数:%d\n",w,h,n);
  num = n;//変数numにアリの合計数を複製しておく
  //----アリの情報を収めておく構造体配列を動的に確保----
  ant = (AntPos *)malloc(sizeof(AntPos *) * n);
  
  //----ファイルから各アリの位置と向きを読み込む。----
  for(i=0; i<n; i++){
    //----アリ情報の読み込み。アリの数だけブン回す。----
    if(EOF==fscanf(fp, "%d%d %c",&ant[i].x,&ant[i].y,&ant[i].dr)){
      //----エラー処理も一応----
      printf("File read Error!!\n");
      exit(1);
    }
    //----デフォの位置が盤上なら盤内フラッグを立てる----
    if(ant[i].x<=w&&ant[i].y<=h){
      ant[i].in=1;
    }else{
      //----最初から外にいれば外扱いにする----
      ant[i].in=0;
    }
  }
  //----読み込めたら、確認のため読んだ情報を一度出力しておく----
  for(i=0; i<n; i++){
    printf("Ant No.%d default point(%d,%d) and direction:%c In or Out:%d\n",
	   i+1,ant[i].x,ant[i].y,ant[i].dr,ant[i].in);
  }

  //----1ステップごとのループ。盤上にいるアリの数が0になったら終了----  
  while(1){
    //----時間の更新----
    t++;
    //----アリの座標の更新----
    //----一回すべてのアリを動かす----
    for(i=0; i<num; i++){
      //----すでに盤外に出ているのであればそのアリは読み飛ばす----
      if(ant[i].in==0){
	continue;
      }else{
	//----向きに応じた１ステップ分の動きをさせる----
	if(ant[i].dr=='D'){//下方向
	  ant[i].y++;
	}else if(ant[i].dr=='R'){//右方向
	  ant[i].x++;
	}
      }
    }
    //----アリが盤の外に出たかどうかのチェックと表示
    for(i=0; i<num; i++){
      if(ant[i].x>w){
	ant[i].in=0;//----盤外に出たら盤内判定を更新----
	//----盤外に出ると同時に状況報告----
	printf("Step%d :Ant No.%d has gone out to (%d.%d).\n",
	       t ,i+1, ant[i].x, ant[i].y);
	//アリの総数を削減
	n--;
      }else if(ant[i].y>h){
	ant[i].in=0;//----盤外に出たら盤内判定を更新----
	//----盤外に出ると同時に状況報告----
	printf("Step%d :Ant No.%d has gone out to (%d.%d).\n",
	       t ,i+1, ant[i].x, ant[i].y);
	//アリの総数を削減
	n--;
      }
    }
    //----2匹のアリが同じマスにいるかどうかのチェックと（必要なら）向きの更新
    for(i=0; i<num; i++){
      for(j=i+1; j<num; j++){
	//----まずは二つのアリが同じマスにいるか判定----
	if((ant[i].x==ant[j].x)&&(ant[i].y==ant[j].y)){
	  //----重複したマスが白か黒かの判定----
	  //----要するにマスのX,Yがどちらも奇数なら白マスであり、方向転換が必要である----
	  if((ant[i].x%2!=0)&&(ant[i].y%2!=0)){
	    if(ant[i].dr=='D'){
	      ant[i].dr='R';
	      ant[j].dr='D';
	    }else{
	      ant[i].dr='D';
	      ant[j].dr='R';
	    }
	  }
	}
      }
    }
  }
  
  //最後の処理
  fclose(fp);
  free(ant);
  
  return 0;
}
