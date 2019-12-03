#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main(int argc, char *file[]){
  int i;
  int len;
  char meirei[]={"show","insert","remove","swap","end"};
  char buffer;
  char n;
  char word[MAX];
  FILE *fpin, *fpout;

  //----File Open----
  fpin = fopen(file[1],"r");
  if(fpin == NULL){
    printf("Can't file open!\n");
    exit(1);
  }
  for(i=0; i<MAX; i++){
    if(fscanf(fpin,"%s",buffer)==-1){
      break;
    }
    len = strlen(*buffer);
    word = (char *)malloc((len+1) * sizeof(char));
    strcpy(word,buffer);
  }
  
  fpout = fopen(file[2],"w");
  if(fpin == NULL){
    printf("Can't file open!\n");
    fclose(file);
    exit(2);
  }
  //------------------

  while(1){
    scanf("%s",n);
    if(0==strcmp(n,"show"){
      return 0;
    }
  }
  return 0;
}
