#include <stdio.h>
#include <string.h>

int main(){
  int i, len;
  int start, stop;//抽出開始地点と終了地点
  char string[] = "to Advance Knowledge for Humanity";//文字列の初期宣言
  //----空白含め33文字----
  char *p, *q;//ポインタ！！
  
  len=strlen(string);//文字列の文字数カウント
  
  while(1){
    printf("Please input start and stop numbers (1 - %d, start <= stop): ", len);
    scanf("%d%d", &start, &stop);
    if(0<start && stop<=len){
      break;
    }
    printf("Over the input start or stop number!\nPlease retry.\n");
  }
  
  //データ位置の補正
  start = start-1;
  stop = stop-1;

  /* 通常の配列添字を使い、配列要素を順次参照する方法 */
  for(i = start; i<=stop; i++) {
    printf("%c",string[i]);
  }
  printf("\n");
  
  /* ポインタ演算で参照するアドレスを変えていく方法 */
  p = &string[0];
  for(i = start; i<=stop; i++) {
    printf("%c",string[i], *(p+1));
  }
  printf("\n");

  /* ポインタ変数に格納されているアドレスそのものを変えていく方法*/
  for(q = &string[start]; q <= &string[stop]; q++) {
    printf("%c",*q);
  }
  printf("\n");
 
  return 0;
}
