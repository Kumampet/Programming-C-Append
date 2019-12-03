#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog01.h"

#define Y 2017
#define M 10
#define D 1

//----構造体宣言----
//struct record {      /* 個人レコード                          */
//  char name[20];     /* 名前（簡単のため、姓だけ）            */
//  int  birthday[3];  /* 誕生日（要素0:西暦 要素1:月 要素2:日）*/
//  int  gender;       /* 性別 (0:男性, 1:女性)                 */
//};
Record input(void);
void output(Record);
int getage(Record);

int main(){
  //----構造体定義----
  //Record data(Record, Record, Record, Record, Record);
  Record data[2];
  int i=0;
    printf("----データ入力----\n");
  while(i<2){
  data[i] = input();

  i++;
  }
  i=0;
    printf("----データ出力----\n");
  while(i<2){
  output(data[i]);
  getage(data[i]);
  i++;
  }
  
  return 0;
}

Record input(){
  Record data;
  static int i=1;
  

  printf("%d人目のデータを入力してください\n",i);
  printf("名前（姓）: \t-->");
  scanf("%s", data.name);
  printf("生れた年（西暦）: \t-->");
  scanf("%d", &data.birthday[0]);
  printf("生れた月: \t-->");
  scanf("%d", &data.birthday[1]);
  printf("生れた日: \t-->");
  scanf("%d", &data.birthday[2]);
  printf("性別(0=男性 1=女性): \t-->");
  scanf("%d", &data.gender);

  i++;
  return data;
}

void output(Record data){

  printf("名前（姓）: %s\n",data.name);
  printf("生年月日: %d年 %d月 %d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  if(data.gender==0){
    printf("(男性)\n");
  }else printf("(女性)\n");
}

int getage(Record data){
  int age;

  while(1){
    //----西暦計算----
    age = Y-data.birthday[0];
    if(age<0){
      age = abs(age);
    }else if(Y==data.birthday[0]){
      break;
    }
    //----月計算----
    if((M-data.birthday[1])<=0){
      age--;
    }else break;
    //----日計算----
    if((D-data.birthday[2])>=0){
      age--;
      break;
    }
  }
  printf("年齢: %d\n",age);

  return 0;
}
