#include <stdio.h>
#define N 10

int func(int);

int main()
{
  int n,r;

  while(1) {
    printf("数値を入力して下さい（正：格納、負：取出）-> ");
    scanf("%d",&n);
    if (n==0) break;
    r=func(n);/* スタックに格納または取出*/
    func(0); /* スタックを表示 */
    if (r>0) printf("取り出したデータ: %d\n",r); /* 取得データの表示 */
    else if (r==-1) printf("エラー（データがありません）\n"); 
    else if (r==-2) printf("エラー（オーバーフロー）\n");
  }
  return 0;
}

int func(int x)
{
  static int stack[N]; /* スタック本体 */
  static int num=0;  /* データ数 */
  /* numはデータ数であると同時に、スタックの、次にデータを
  　 入れる場所を指している（最初はデータがまだ格納されて
     いないので、初期値は０になる）。
  */
  int i;//counter
  int out;//スタックから取り出してmainへ返す値

  printf("stack内x=%d num=%d\n",x,num);
  if(x>0){
    if(num>=N){//オーバーフロー判定
      return -2;
    }
    stack[num]=x;
    num++;
    return 0;
  }else if(x<0){
    if(num<=0){
      return -1;
    }
    out=stack[num-1];
    num--;
    
    return out;
  }else{
    printf("num=[");
    for(i=0; i<num; i++){
      printf("%d ",stack[i]);
    }
    printf("]\n");
  }

}
