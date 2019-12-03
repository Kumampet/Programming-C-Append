#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prog01.h"

#define MAX 20
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
  Record data[MAX];
  int i=0,j=0;
  //printf("----データ入力----\n");
  while(1){
    data[i]=input();
    if(data[i].gender==-1){
      break;
    }
    i++;
  }
  printf("----データ出力----\n");
  for(j=0; j<i; j++){
    printf("%2d人目:",j+1);
    output(data[j]);

  }
  
  return 0;
}

Record input(){
  Record data;  
  //  printf("%d人目のデータを入力してください\n",i);
  //printf("名前（姓）: \t-->");
  scanf("%s", data.name);
  //printf("生れた年（西暦）: \t-->");
  scanf("%d", &data.birthday[0]);
  //printf("生れた月: \t-->");
  scanf("%d", &data.birthday[1]);
  //printf("生れた日: \t-->");
  scanf("%d", &data.birthday[2]);
  //printf("性別(0=男性 1=女性): \t-->");
  if(scanf("%d", &data.gender)==EOF){
    data.gender=-1;
  }
  
  return data;
}

void output(Record data){

  printf("名前（姓）: %-10s",data.name);
  printf("\t%-d年 %2d月 %2d日",data.birthday[0],data.birthday[1],data.birthday[2]);
  getage(data);
  if(data.gender==0){
    printf(" 男性\n");
  }else printf(" 女性\n");
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
    if((M-data.birthday[1])<0){
      age--;
      if((D-data.birthday[2])<=0){
      age--;
      break;
      }
    }break;
    //----日計算----
    
  }
  printf("年齢: %-d",age);

  return 0;
}
