#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 4

void rev(char *);

int main(){
  char *array[NUM] = {"University","of","Aizu","Japan"};
  int i;

  for(i = 0; i < NUM; i++){
    printf("[%2d] : %s -> ",i,array[i]);
    //   printf("%p\n",array[i]);
    rev(array[i]);
    printf("\n");
  }

  return 0;
}

void rev(char *st){

  //printf("%p\n",st);
  if(*st==NULL){
    return;
  }else{
    rev(st+1);
  }
  printf("%c",*st);
}

