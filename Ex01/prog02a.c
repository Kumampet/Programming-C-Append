#include <stdio.h>

int main(){
  char c;

  printf("一文字入力してください。\n");
  scanf("%c",&c);

  printf("入力された文字は %c です。\n",c);
  printf("入力された文字のアスキーコードは %d(0x%x) です。\n",c,c);
}
