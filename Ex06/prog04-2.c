#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int data, char *text[]){//コマンドラインで入力
  int i,j;
  int len;//文字数
  char *array;
  char *adr;
  char out[]=".out";

  for(i=1; i<data; i++){
    len = strlen(text[i]);//i個目の文字列の文字数を調べてlenへ退避
    //printf("%s 's length is %d\n",text[i],len);//該当の文字列の文字数を表示。確認用
    printf("%s ==> ",text[i]);
    adr = strstr(text[i],".in\0");//text文字列の中に[.in\0]が含まれていれば、先頭のアドレスを返す。
    if(adr == NULL){//なかった場合
      //printf("Not include [.in]\n");//デバッグ用
      array = (char *)malloc((len + 4) * sizeof(char));//追加の配列要素数は元の要素数の+1

      printf("%s%s\n",text[i],out);
      break;
    }
    //printf("Lookup address = %p\n",&adr);//デバッグ用
    array = (char *)malloc((len + 1) * sizeof(char));//追加の配列要素数は元の要素数の+1
    strcpy(array, text[i]);
    for(j=0; j<len-3; j++){
      printf("%c",array[j]);
    }
    printf("%s\n",out);

    free(array);//メモリ解放！！
  }

  //printf("よくぞ戻ってきなっ！！\n");
  return 0;
}
