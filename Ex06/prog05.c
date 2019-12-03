#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(){
  char init[]="[Aizu]"; /* 初期データ用文字列 */
  char *str;                      /* 文字列を保持するバッファ１ */
  char *str2;                     /* 文字列を保持するバッファ２ （作業に使う）*/
  int n;//挿入箇所
  char input[BUFSIZE];            /* 入力用文字列バッファ */
  /* その他の変数を宣言 */
  int len,len2;
  /* strの初期化を記述する
   * strlen,malloc,strcpyを使いstrにinitの内容のコピーを保持させる
   */
  len = strlen(init);//初期文字列の文字数数え
  str = (char *)malloc(len+1 * sizeof(char));//STRに初期文字数分のバッファを確保する
  strcpy(str,init);//strに初期文字列をコピる

  //printf("%s\n",str);//デバッグ用
  
  while (1) {
    printf( "%s\n", str );//現在バッファに登録されている文字列
    len = strlen(input);//現在のバッファの文字列の文字数を記録
    if( scanf("%d %s", &n, input) != 2 ){//終了するかの判定
      printf("Bye!\n");
      break;//無限ループからの脱出
    }else if(n>len){
      printf("文字数大きすぎ)\n");
    }else{
      len2 = strlen(input);//入力された文字列の文字数を記録
      str2 = (char *)malloc(len+1 * sizeof(char));
      strcpy(str2,str);//現在の文字列を退避
      printf("str2 => %s\n",str2);//デバッグ用
      str = (char *)malloc(len+len2 * sizeof(char));//表示用バッファの結合後文字列分のバッファを確保
      strcpy(str,str2);
      strcpy(str2,str+n);
      printf("str => %s\n",str);
      str[n]='[';
      strcpy(str+n+1,input);
      str[n+1+len2]=']';
      strcpy(str+n+1+len2+1,str2);
      printf("%s\n",str);
    }
  }
  free(str);
    
  return 0;
}
