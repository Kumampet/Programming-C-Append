#include <stdio.h>

double seqavg(double,int);

int i=1;

int main(){
  int status;
  double n,avg;

  while(1){
    printf("数値を入力してください：");
    status = scanf("%lf",&n);
    if(status != 1){
      break;
    }
    avg = seqavg(n,i);
    printf("入力回数：%d 回 ",i);
    printf("ここまでの平均=%lf\n",avg);
    i++;
  }

  printf("\n最終的な平均値は%lfです。\n",avg);

  return 0;
}

double seqavg(double n, int i){
  static double avg;
  avg = (avg*((double)i-1)+n)/(double)i;
  return avg;
}
