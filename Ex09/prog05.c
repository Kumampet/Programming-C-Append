#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NMAX 20                       /* maximum number of buses */
#define NSTOP 6                       /* number of bus stops in data file */
#define UNDEF -999                    /* value for undefined data */

typedef struct{
  char colstr1[8];
  char colstr2[8];
  char stopname[NSTOP][12];
}Tableinfo;
  
typedef struct{
  int number; //便名
  char company[8]; //運行会社
  int hour[NSTOP];
  int min[NSTOP];
}Businfo;

  
int main(int elm, char *argv[]){
  FILE *fp;
  int i,j;
  Tableinfo data[NMAX];
  
  //ファイル展開
  fp = fopen(argv[1],"r");
  if(fp==NULL){
    fprintf(stderr, "FILE OPEN ERROR!!\n");
    exit(0);
  }

  //数値代入
  for(i=0; i<8; i++){
    fscanf(fp,"%s",data[i].colstr1);
  }

  //デバッグ
  for(i=0; i<8; i++){
    printf("%s\t",data[i].colstr1);
  }
  
  return 0;
}
