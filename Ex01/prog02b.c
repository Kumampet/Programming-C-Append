#include <stdio.h>

int main(){
  char c;

  printf("文字入力してください。\n");
  while(1){
    scanf("%c",&c);
    if(c == '\n'){
      break;
    }
    printf("入力された文字[%c]のアスキーコードは %d(0x%x) です。\n",c,c,c);
  }
  return 0;
}
