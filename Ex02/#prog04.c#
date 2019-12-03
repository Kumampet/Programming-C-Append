#include <stdio.h>
#include <stdlib.h>

#define QLEN 5
#define QEMP -1
#define QFUL -1

int enq(int);
int deq(void);
void listq(void);

int count;
int que[QLEN];
/* キューに使用する配列、その他外部変数の宣言 */

int main(){
  int n=0;

  while(1){

  /* 処理の入力 */
  /* 入力に従って関数を呼ぶ */
  /* なお、enq()の場合は呼ぶ前に引数入力 */
  /* deq()の場合は呼んだ後にデータ出力   */
    while(1){
      printf("1=enQ,2=deQ,othre=END >>");
      scanf("%d",&n);
      if(n==1){
	printf("Enter enQ data ==>");
	count++;
	enq(count);
      }else if(){
	deq();
      }else{
	return 0;
      }
    }
  return 0;
}

void listq(void){
  int i;
  if(count>0){
    printf("Queue=");
    for(i=0; i<count; i++){
      printf("%d ",i);
    }else{
      printf("Queue empty!\n");
    }
  }
  printf("\n");
  /* キューが空なら"Queue empty!\n"表示 */
  /* 空じゃない場合は並んでいる個数分データ表示 */
}

int enq(int data){
  int judge;
  if(judge > QLEN){
    return QFUL;
  }else{
    que[count]=data;
    count++;
  }
  /* キューが満杯ならQFULをreturn*/
  /* そうでないならキューの最後尾にdataを追加 */
}

int deq(void){
  if(count<=0){
    return QEMP;
  }
  /* キューが空ならQEMPをreturn*/
  /* そうでないならキューの最前列のdataを変数に入れ */
  /* 後続のデータを一つづつ前に移動させ、変数の値をリターンする */
}
