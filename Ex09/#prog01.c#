#include <stdio.h>
#include <string.h>
//----構造体宣言----
struct record {      /* 個人レコード                          */
  char name[20];     /* 名前（簡単のため、姓だけ）            */
  int  birthday[3];  /* 誕生日（要素0:西暦 要素1:月 要素2:日）*/
  int  gender;       /* 性別 (0:男性, 1:女性)                 */
};

int main(){
  //----構造体定義----
  struct record data;

  //----データ入力----
  printf("データを入力してください\n");
  printf("名前（姓）: \t-->");
  scanf("%s", &data.name);
  printf("生れた年（西暦）: \t-->");
  scanf("%d", &data.birthday[0]);
  printf("生れた月: \t-->");
  scanf("%d", &data.birthday[1]);
  printf("生れた日: \t-->");
  scanf("%d", &data.birthday[2]);
  printf("性別(0=男性 1=女性): \t-->");
  scanf("%d", &data.gender);

  //----データ出力----
  printf("名前（姓）: %s\n",&data.name);
  printf("生年月日: %d年 %d月 %d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  if(data.gender==0){
    printf("(男性)\n");
  }else printf("(女性)\n");
  

  //--------
  return 0;
}
