#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 4

char *rev(char *);

main(){
  char *array[NUM] = {"University","of","Aizu","Japan"};
  char *a_rev[NUM];
  int i;

  //文字列の引き渡し
  for(i=0; i<NUM; i++){
    a_rev[i] = rev(array[i]);
  }
  
  //置換文字列書き出し
  for(i=0; i<NUM; i++){
    printf("[%d] : %s -> %s\n",i,array[i],a_rev[i]);
  }
  

  return 0;
}

char *rev(char *r){
  char *tern;
  int i,len;

  len = strlen(r);
  //逆転文字列の確保　NULL文字分も1つ多く確保
  tern = (char *)malloc(1 + len  * sizeof(char));

  for(i=0; i<len; i++){
    tern[i] = r[len-1- i];
    tern[len+1]='\0';
  }

  return tern;
}
