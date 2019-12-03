#include <stdio.h>

int myatoi(char *);

int main()
{
  char str2[][20]={"  123.45"," -13A","+12 345","A123","123-45","+-123",""};
  int ival, i;

  for ( i=0; str2[i][0]!='\0'; i++ ){
    ival = myatoi( str2[i] );
    printf("文字列:%s\n", str2[i]);
    printf("読み取り値:%d\n", ival);
  }
  return 0;
}
/* この後に関数 myatoi を作成する */

int myatoi(char *ctoi){
  int i,j=0,n,flag=0;
  int no=0;
  char c;

  //条件選定
  for(i=0; i<20;i++){
    if(ctoi[i]==' '&&no==0){//スペース
      continue;
    }
    else if(ctoi[i]=='+'&&no==0){
      if(flag==2){
	return j=-j;
      }else flag=1;
    }
    else if(ctoi[i]=='-'&&no==0){
      if(flag==1){
	return j;
      }else flag=2;
    }
    else if('0'<=ctoi[i]&&ctoi[i]<='9'){
      no=1;
      n = ctoi[i]-48;
      j=j*10+n;
    }else break;
  }
  if(flag==1){
    return j;
  }else if(flag==2){
    j = j*-1;
  }
  return j;
  
}
