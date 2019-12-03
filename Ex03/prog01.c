#include<stdio.h>
#include<stdlib.h>

int main(){

  FILE *fpin, *fpout;//ファイルポインタの宣言
  char c;//文字変数の宣言
  fpin = fopen("read.dat","r");//read.datのファイルを開けて、読み込みファイルポインタ"fpin"に割当
  if(fpin == NULL){//オープン失敗なら
    printf("read file open error\n");//ファイルが開けなかったことをプリントして
    exit(1);//強制終了させる
  }

  fpout = fopen("out.dat","w");//ファイル"out.dat"を開けて書き込むファイルとしてファイルポインタ"fpout"に割当

  if(fpout == NULL){//オープン失敗なら
    printf("write file open error\n");//エラーメッセージを表示して
    fclose(fpin);//読み込んだ"read.dat"をクローズして
    exit(2);//強制終了させる
  }
  //エラーもなにも起らずにこれたら
  while(fscanf(fpin, "%c",&c)!=EOF){//fpinのEOFが出ないあいだループし
    fprintf(fpout, "%c",c);//ファイルポインタfpoutのout.datに文字を書き込んでいく
  }

  fclose(fpout);//fpoutをファイルクローズ
  fclose(fpin);//fpinをファイルクローズ

  return 0;//戻り値を０にしてプログラム終了
}
