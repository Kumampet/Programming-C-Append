#include <stdio.h>
#define EOF -1
char grade_char(int);
int char_point(char);


int main(){
  int score=0,tani,tani2=0,point=0,point2=0,n=0,i=1;
  char c;
  double avg;
  while(1){
    printf("点数と単位数を入力してください\n");
    n = scanf("%d%d",&score,&tani);
    c =  grade_char(score);
    point = char_point(c);
    if(n==EOF){
      break;
    }
    printf("%d 点の評価は %c で、評点は %d 点です。( %d 単位)\n\n",score,c,point,tani);
    tani2=tani2+tani;
    point2=point+point2;
    i++;
  }
  
  avg = (double)point/(double)i;
  printf("評定平均（GPA）：%lf , 単位数：%d\n",avg,tani2);
  return 0;
}

char grade_char(int score){
  char c;
  if(0<=score && score<35){
    return 'F';
  }else if(35<=score && score<50){
    return 'D';
  }else if(50<=score && score<65){
    return 'C';
  }else if(65<=score && score<80){
    return 'B';
  }else if(80<=score && score<100){
    return 'A';
  }else{
    printf("Error\n");
  }
}
int char_point(char c){
  int a;
  if(c=='F'){
    return 0;
  }else if(c=='D'){
    return 0;
  }else if(c=='C'){
    return 2;
  }else if(c=='B'){
    return 3;
  }else{
    return 4;
  }
}
