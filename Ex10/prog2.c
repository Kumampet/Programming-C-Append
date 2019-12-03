#include <stdio.h>

typedef struct{
  int  id;
  char name[20];
  int  score;
  char grade;
} Record;


int main(){
  /* 以下の構造体の初期化はmain()の中に書くこと */
  Record data[2]={
    {1250050, "Kumamoto", 90, 'A'},
    {1259999, "Sample", 100, 'A'},
  };
  Record *p=data,*q;
  int i;

  printf("1.ポインタ変数の値は維持した上でポインタ演算を行い，間接演算子と.演算子を用いる場合\n");
  for(i = 0; i < 2; i++){
    printf("%d\t", (*(p + i)).id);
    printf("%-8s\t", (*(p + i)).name);
    printf("%d\t", (*(p + i)).score);
    printf("%c\n", (*(p + i)).grade);
  }
  
  printf("2. ポインタ変数の値は維持した上でポインタ演算を行い，アロー演算子を用いる場合\n");
  for(i = 0; i < 2; i++){
    printf("%d\t", (p + i)->id);
    printf("%-8s\t", (p + i)->name);
    printf("%d\t", (p + i)->score);
    printf("%c\n", (p + i)->grade);
  }
  
  printf("3. ポインタ変数の値をポインタ演算で変えながら間接演算子と.演算子を用いる場合\n");
  for(q = p; q < p + 2; q++){
    printf("%d\t", (*q).id);
    printf("%-8s\t", (*q).name);
    printf("%d\t", (*q).score);
    printf("%c\n", (*q).grade);
  }

  printf("4. ポインタ変数の値をポインタ演算で変えながらアロー演算子を用いる場合\n");
  for(q = p; q < p + 2; q++){
    printf("%d\t", q->id);
    printf("%-8s\t", q->name);
    printf("%d\t", q->score);
    printf("%c\n", q->grade);
  }

  printf("dataとdata[1]のアドレスとサイズを表示\n");
  printf("data(data[0]): %p\n",&data);
  printf("data[1]: %p\n",&data[1]);
  printf("sizeof(data)= %d, sizeof(data[1])= %d\n",sizeof(data), sizeof(data[1]));
  return 0;
}
