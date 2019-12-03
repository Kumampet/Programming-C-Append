#include <stdio.h>
#include <stdlib.h>

int main(int elem, char *score_char[]){
  int i;
  int score;//得点を'数値'として保管する変数

  //printf("elem = %d\n",elem);//要素数確認用
  
  for(i=1; i<elem; i++){//得点毎に比較
    score = atoi(score_char[i]);
    
    if(0<=score && score<35){
      printf("[%d]Point %d: F\n",i,score);
    }else if(35<=score && score<50){
      printf("[%d]Point %d: D\n",i,score);
    }else if(50<=score && score<65){
      printf("[%d]Point %d: C\n",i,score);
    }else if(65<=score && score<80){
      printf("[%d]Point %d: B\n",i,score);
    }else if(80<=score && score<100){
      printf("[%d]Point %d: A\n",i,score);
    }
  }
}
