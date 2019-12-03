#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXDATA 1024 //最大データ数
#define LENIP  16 //IPアドレスの最長文字数+1
#define LENHOST 256 //最長文字数+1

int main(){
  int i,j;
  FILE *fp;
  int numdata;
  char ipadr[MAXDATA][LENIP];//データごとのアドレス
  char host [MAXDATA][LENHOST];//データごとのホスト名
  char query[LENHOST];//照会する入力文字配列
  /* その他必要な変数を定義して良い */
  int flag;//合致単語が見つからない場合０
  int len;//入力文字の文字数
  
  /*** データの読み出し処理 ***/
  /* ファイルのオープン */
  fp = fopen("stdhosts.txt","r");
  if (fp == NULL) {
    printf("Cannot open file.\n");
    exit(1);
  }
  /* データの読み出し */
  for( i=0 ; i < MAXDATA ; i++ ){
    /* ２項目読めなければループをぬける */
    if (fscanf(fp,"%s %s",ipadr[i],host[i]) != 2) break;
  }
  numdata=i;//総データ数

  /*** 問合せの処理 ***/
  
  while(scanf("%s",query)!=EOF){
    flag=0;
    len=strlen(query);
   /* 文字列の配列の使用方法に注意  
      host[xxx]でxxx番目の文字列を示す*/
    for(i=0; i<numdata; i++){
      if(strncmp(host[i],query,len)==0){
	flag=1;
	printf("%s %s\n",host[i],ipadr[i]);
      }
    }  
    if(flag==0){
      printf("%s is not found!\n",query);
    }
  }
  
  return 0;
}
