#include <stdio.h>

typedef struct{
  int  id;       /* ID    */
  char name[20]; /* 名前   */
  int  score;    /* 点数   */
  char grade;    /* 成績 　*/
} Record;

void PrintData1(Record);
void PrintData2(Record *);

int main(){
  int i;
  /* 以下の構造体の初期化はmain()の中に書くこと */
  Record person1={1250050, "Kumamoto", 50, 'C'}, person2={1259999, "Sample", 100, 'A'};
  
  PrintData1(person1);
  PrintData1(person2);

  PrintData2(&person1);
  PrintData2(&person2);
  
  return 0;
}

void PrintData1(Record p){
  printf("%d\t%-8s\t%d\t%c\n",p.id, p.name, p.score, p.grade);
}

void PrintData2(Record *p){
  printf("%d\t%-8s\t%d\t%c\n",p->id, p->name, p->score, p->grade);
}

