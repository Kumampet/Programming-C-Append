#include <stdio.h>

int myatoi(char *);

int main()
{
  char str2[20],ad;
  int ival, i;
  
  printf("和暦(H11など)：");
  scanf("%c%s",&ad,str2);
  ival = myatoi( str2 );
  if(ad=='H'){
    ival=1989+ival-1;  
  }else if(ad=='S'){
    ival=1926+ival-1;
  }else if(ad=='T'){
    ival=1912+ival-1;
  }else if(ad=='M'){
    ival=1868+ival-1;
  }
  
  printf("Year(A.D.):%d\n",ival);
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
