#include <stdio.h>

#define N 5

int main()
{
  /*
  int data[N];//比較データ保管配列
  int tmp;
  int min_idx;
  int i,j;//カウンタ変数
  */
  
  int data[N];//比較データ保管配列
  int tmp;
  int *p,*q,*min_ptr;
  
  printf("Please input %d numbers\n", N);
  for(p = &data[0]; p < &data[N]; p++){//ポインタ変数に格納されているアドレスそのものを指定して更新する
    scanf("%d",&*p);//*pで間接指定し、&で入力
  }

  for(p = &data[0]; p < &data[N]; p++){//アドレス指定
      min_ptr = p;
      //printf("min_ptr=%d\n",*min_ptr);
      for(q = p+1; q < &data[N]; q++){
	//printf("p=%d\n",*q);//p+1アドレスのqへの代入成功
	if(*q < *min_ptr){
	  tmp = *p;
	  //printf("tmp=%d\n",tmp);
	  *p = *q;
	  *q = tmp;
	}
      }
  }
  
  printf("Sorted data\n");
  for(p = &data[0]; p < &data[N]; p++){
    printf("%d\n",*p);
  }
  /*
  for(i = 0; i < N; i++){
    scanf("%d", &data[i]);//比較対象の入力
  }//入力の回数はマクロで指定した入力個数分入力し配列に保管
  
  for(i = 0; i < N - 1; i++){
    min_idx = i;//現在の試行回数番目の配列に格納されている値をとりあえず最小とみなす
    for(j = i + 1; j < N; j++){//現在の試行回数番目以降の数を参照し、
      if(data[j] < data[min_idx]) min_idx = j;//現在参照している数値より小さければその値を最小とする
    }
    tmp = data[i];//i番目の値を一旦退避
    data[i] = data[min_idx];//i番目での最小値を入れ替える
    data[min_idx] = tmp;//最小値にする
  }

  printf("Sorted data\n");
  for(i = 0; i < N; i++) {
    printf("%d\n", data[i]);
  }
  */
  return 0;
}
