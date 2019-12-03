#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

//----構造体宣言*定義----
typedef struct{
  char  sid[8];
  char  sname[10];
  int   score[4];
  char  grade;
  double ave;
} Record;

//---プロトタイプ宣言----
Record input(FILE *);
void output(Record);
void getave(Record *);
char grade(Record);
void kensaku(Record, char *);

//----main関数----
int main(int elm, char *in[]){
  FILE *fp;
  int i,n=0;
  char who[10];
  Record data[MAX];
  //----ファイルない時のエラー処理----
  
  if(elm!=2){
    fprintf(stderr, "Error!  Usage: ./a.out datafilename\n");
    exit(0);
  }
  if((fp = fopen(in[1], "r"))==NULL){
    fprintf(stderr, "Error! Can't file open....\n");
    fclose(fp);
    exit(1);
  }

  //----データ入力----
  while(1){
    data[n]=input(fp);
    if(data[n].score[3]==-1){
      break;
    }
    n++;
  }

  //----平均点計算----
  for(i=0; i<n; i++){
    getave(&data[i]);
  }

  //----評定算出----
  for(i=0; i<n; i++){
    data[i].grade = grade(data[i]);
  }
  
  //----データ出力----
  for(i=0; i<n; i++){
    output(data[i]);
  }

  fclose(fp);

  //----検索----
  while(1){
    printf("誰のデータを参照しますか？(氏名or学籍番号)\n");
    if(scanf("%s",who)!=EOF){
      if(97<=who[0]&&who[0]<=122){//もし頭文字に小文字が入力された時の補正
	who[0]=who[0]-32;
      }
      for(i=0; i<n; i++){
	kensaku(data[i], who);//構造体内の各要素ずつ関数へ飛ばして照合
      }
    }
  }
  printf("END\n");  
  
  return 0;
}

//---------------------------------------------------------------
//---------------------------データ入力関数------------------------
//---------------------------------------------------------------
Record input(FILE *fp){
  Record data;

  fscanf(fp, "%s %s %d %d %d",data.sid, data.sname,
	&data.score[0], &data.score[1], &data.score[2]);
  if(fscanf(fp, "%d",&data.score[3])==EOF){
    data.score[3]=-1;
  }
  
  return data;
}
//---------------------------------------------------------------
//---------------------------平均点計算関数------------------------
//---------------------------------------------------------------
void getave(Record *data){
  data->ave = (double)(data->score[0]+data->score[1]+data->score[2]+data->score[3])/4;
}
//---------------------------------------------------------------
//----------------------------評定算出関数-------------------------
//---------------------------------------------------------------
char grade(Record data){
  if(data.ave>=80){
    return 'A';
  }else if(65<=data.ave&&data.ave<80){
    return 'B';
  }else if(50<=data.ave&&data.ave<65){
    return 'C';
  }else if(35<=data.ave&&data.ave<50){
    return 'D';
  }else return 'F';
}
//---------------------------------------------------------------
//---------------------------データ出力関数------------------------
//---------------------------------------------------------------
void output(Record data){
  printf("%s %-8s %-d %-d %-d %-d %-4.1f %c\n",data.sid, data.sname, data.score[0],
	 data.score[1],data.score[2], data.score[3], data.ave, data.grade);
}
//---------------------------------------------------------------
//---------------------------検索--------------------------------
//---------------------------------------------------------------
void kensaku(Record data, char *who){
  if((strcmp(who, data.sname)==0)||(strcmp(who, data.sid)==0)){//名前か学籍番号が一致すれば該当生徒の成績を表示
    printf("%s %-8s %-d %-d %-d %-d %-4.1f %c\n",data.sid, data.sname,
	   data.score[0], data.score[1],data.score[2],
	   data.score[3], data.ave, data.grade);
  }
}
