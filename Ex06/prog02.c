#include <stdio.h>
#include <ctype.h> /* 関数toupperを使うため */

void printFavoriteVehicle(char []);//配列の引数を利用

int main() {
  char *vehicles[]={"car", "motorbike", "train"};//ポインンタ配列で文字列ごとに文字数分の要素を取得
  int i;//範囲判定

  /*----質問文表示&乗物番号読取り----*/
  printf("Suppose that we now have (0) %s, (1) %s, (2) %s.\n",vehicles[0],vehicles[1],vehicles[2]);
  printf("Which do you like?\n");
  printf("Input 0, 1, or 2: ");
  scanf("%d",&i);
  /*------------------------------*/
  
  if(0 <= i && i <= 2) { /* i が 0-2 の範囲になければエラーを避けるため何もしない */
    printFavoriteVehicle(vehicles[i]);//乗物番号に合致する文字列を含んだ配列を置換する関数へとばす
  }  
  return 0;
}

void printFavoriteVehicle(char vehicle[]) {//配列の要素形式の表記
  
  printf("%c",toupper(vehicle[0])); /* 最初の文字を大文字で出力。一文字だけなので%cで出力*/
  printf("%s",&vehicle[1]); /* 二文字目以降を出力 */
  printf(" is your favorite vehicle!\n");
  
}
