#include<stdio.h>
#include<stdlib.h>
#define N 1000

int main(){

  FILE *fpin, *fpout;
  char c[N],ch;
  int i=0,j;
  fpin = fopen("data.in","r");
  if(fpin == NULL){
    printf("read file open error\n");
    exit(1);
  }

  fpout = fopen("prog02.out","w");

  if(fpout == NULL){
    printf("write file open error\n");
    fclose(fpin);
    exit(2);
  }
 
  while(fscanf(fpin, "%c",&c[i])!=EOF){
    ch=c[i];
    if('A'<= ch && ch <= 'Z'){
      ch = ch+32;
    }
    i++;
    fprintf(fpout, "%c",ch);
  }
  fprintf(fpout,"\n"); 

  
  for(j=0; j<i; j++){
    ch=c[j];
    if('a'<= ch && ch <= 'z'){
      ch = ch-32;
    }
    fprintf(fpout, "%c",ch);  
  }
   fprintf(fpout,"\n"); 

  for(j=0; j<i; j++){
    ch=c[j];
    if('A'<= ch && ch <= 'Z'){
      ch = ch+32;
    }else if('a'<= ch && ch <= 'z'){
      ch=ch-32;
    }
    fprintf(fpout,"%c",ch);  
  }

    /*if('a'<= ch && ch <= 'z'){
      ch = ch-32;
    }
    fprintf(fpout, "%c",ch);*/

  fclose(fpout);
  fclose(fpin);

  return 0;
}
