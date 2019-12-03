#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define UPPER 1
#define LOWER 0

int isAlpha(char c);
int isUpper(char c);

int main(){
  char c,alpha,upper;

  printf("文字入力してください。\n");
  while(1){
    scanf("%c",&c);//文字入力
    
    if(c == '\n'){//改行判定
      break;
    }
    
    printf("入力された文字[%c]のアスキーコードは %d(0x%x) で、",c,c,c);//アスキーコード表示

    alpha = isAlpha(c);//アルファベット判定
    if(alpha == TRUE){
      printf("アルファベット");
      upper = isUpper(c);//大小判定
      if(upper == TRUE){
	printf("大文字です。\n");
      }else{
	printf("小文字です。\n");
      }
    }else{
      printf("アルファベットではありません。\n");
    }
  }
  return 0;
}

int isAlpha(char c){
  int a;

  if((('A' <= c)&&(c <='Z'))||(('a' <= c)&&(c <= 'z'))){
    return TRUE;
  }
  return FALSE;
}

int isUpper(char c){
  int a;

  if(('A' <= c)&&(c <='Z')){
    return TRUE;
  }
  return FALSE;
}
