#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100000
#define LOOP 50000

typedef struct{
  int data[N];//N個の要素を持つ配列
  int maxdata;//データの最大値
  int mindata;//データの最小値
  double avedata;//データの平均値
}Data_array;

void find_member(Data_array *);
void find_max(Data_array *);
void find_min(Data_array *);
void culc_ave(Data_array *);
void find_member2(Data_array);

int main(){
  Data_array A;
  time_t start,end;
  int i;
  double keika;
  
  srand((unsigned int)time(NULL));//乱数初期値に現在時刻を与える
  //乱数をN個の要素にすべて入れる
  for(i=0; i<N; i++){
    A.data[i]=rand()%1001;
  }

  start = clock();
  for(i=0; i<LOOP; i++){
    find_member(&A);
  }
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by address \t: %f sec\n",keika);

  start = clock();
  for(i=0; i<LOOP; i++){
    find_member2(A);
  }
  end = clock();
  keika = (end-start)/(double)CLOCKS_PER_SEC;
  printf("Call by value \t: %f sec\n",keika);
  
  return 0;
}

//各種要素探索
void find_member(Data_array *A){
  int i;
  
  //最大値を求める
  find_max(A);
  //printf("MAX : %d\n", A->maxdata);
  //最小値を求める
  find_min(A);
  //printf("Min : %d\n", A->mindata);
  //平均を求める
  culc_ave(A);
  //printf("Ave : %f\n", A->avedata);
}

void find_member2(Data_array A){
  int i,cur_max=0,cur_min,sum=0;
  double ave;

  for(i=0; i<N; i++){
    if(cur_max<A.data[i]){
      A.maxdata = A.data[i];
    }
  }
  cur_min = A.maxdata;
  for(i=0; i<N; i++){
    if(cur_min>A.data[i]){
      cur_min = A.data[i];
    }
  }
  for(i=0; i<N; i++){
    sum+=A.data[i];
  }
  ave = (double)sum/(double)N;
}

//最大値検索
void find_max(Data_array *A){
  int i,current_max=0;

  for(i=0; i<N; i++){
    if(current_max<A->data[i]){
      A->maxdata = A->data[i];
    }
  }
}

//最小値検索
void find_min(Data_array *A){
  int i,current_min=A->maxdata;

  for(i=0; i<N; i++){
    if(current_min>A->data[i]){
      A->mindata = A->data[i];
    }
  }
}

//平均計算
void culc_ave(Data_array *A){
  int i,sum;

  for(i=0; i<N; i++){
    sum+=A->data[i];
  }

  A->avedata = (double)sum/(double)N;
}
