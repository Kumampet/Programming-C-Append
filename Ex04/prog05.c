#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUF 1024

int main(){
  int p,n,m,i,frag=0;
  int k=0;
  char c[MAX_BUF],buf[MAX_BUF] = "[Wakamatsu]";//初期バッファ宣言

  while(1){
    //----現時点まで何文字あるかのカウント&現在バッファに入力されている文字列の出力----
    printf("\n現在入力されている文字は：\n");
    for(i=0; buf[i]>0; i++){
      printf("%c",buf[i]);
    }
    printf("\n");
    //printf("文字数([]含む)=%d\n",i);//文字カウントデバッグ用です！

    //----挿入ポイントの入力----
    while(frag==0){
      printf("文字を挿入したい文字数を入力してください。");
      scanf("%d",&p);
      if(p<=i){
	frag=1;
	break;
      }else{
	printf("ERROR!!\n");
	printf("[原因]：指定した挿入ポイントが現時点での最高文字数より大きいです。\n");
	printf("現在の最大文字数：%d 文字\n",i);
      }
    }
    
    //----挿入文字の入力&カッコの付随----
    printf("挿入したい文字列をカッコ抜きで入力してください。");
    scanf("%s",c);
    n = strlen(c);
    for(i=n; i>=0; i--){
      c[i+1]=c[i];
    }
    c[n+1]="]";
    c[0]="[";
    printf("%s",c);
    n = strlen(c);//最終の入力文字の文字数
    
    //----文字の挿入作業----
    m = strlen(buf);
    for(i=m; i>=p; i--){
      buf[i+n]=buf[i];
    }
    for(i=p; i<=m+n; i++){
      buf[i]=c[k];
      k++;
    }
  }
  return 0;
}
