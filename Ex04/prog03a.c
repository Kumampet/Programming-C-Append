#include <stdio.h>
#define N 100

int main(){
  char str_1[N], str_2[N];//文字列用バッファ
  int i=0;
  
  //----入力処理----
  printf("Input : ");
  scanf("%s",str_1);

  //----コピー処理----
  while(1){
    str_2[i]=str_1[i];
    if(str_1[i]=='\0'){
	  break;
    }
    i++;
  }

  //----出力処理----
  printf("{%s}\n",str_2);

  return 0;
}
