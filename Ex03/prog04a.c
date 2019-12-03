#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(){
  char buf[MAX];
  int i,n,c;
  FILE *fpin,*fpout;

  //----file open----
  fpin = fopen("data.in","r");
  if(fpin == NULL){
    printf("Cannot open file \n");
    exit(2);
  }
  fpout = fopen("mydata.out","w");
  if(fpout==NULL){
    printf("Cannot open file \n");
    fclose(fpin);
    exit(2);
  }

  //----data input----
  for(n=0; n<MAX ;n++){
    fscanf(fpin, "%c",&c);
    if(c==EOF){
      break;
    }
    buf[n]=(char)c;
  }
  if(n>MAX){
    printf("Bufer overflow!!\n");
    exit(3);
  }
  //----data output 逆順に出力----
  for(i=n-2;i>=0;i--){
    fprintf(fpout, "%c",buf[i]);
  }
  fprintf(fpout,"\n");
  //----file close----
  fclose(fpin);
  fclose(fpout);
  
  return 0;
}
