#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int main(){
  char buf1[MAX],buf2[MAX];
  int i,n,c1,c2;
  FILE *fpin1,*fpin2;

  //----file open----
  fpin1 = fopen("mydata.out","r");
  if(fpin1 == NULL){
    printf("Cannot open file \n");
    exit(2);
  }
  fpin2 = fopen("data.out","w");
  if(fpin2==NULL){
    printf("Cannot open file \n");
    exit(2);
  }

  //----data input----
  for(n=0; n<MAX ;n++){
    fscanf(fpin1, "%c",&c1);
    if(c1==EOF){
      break;
    }
    buf1[n]=(char)c1;
  }
  if(n>MAX){
    printf("Bufer overflow!!\n");
    exit(3);
  }
    for(n=0; n<MAX ;n++){
    fscanf(fpin2, "%c",&c2);
    if(c2==EOF){
      break;
    }
    buf2[n]=(char)c2;
  }
  if(n>MAX){
    printf("Bufer overflow!!\n");
    exit(3);
  }
  //----compere file----
  for(i=0; i<MAX; i++){
    if(buf1[i] != buf2[i]){
      printf("Two files are different at %d byte.\n",i+1);
      break;
    }else{
      printf("Two files are identical.\n");
    }
  }
  //----file close----
  fclose(fpin1);
  fclose(fpin2);
  
  return 0;
}
