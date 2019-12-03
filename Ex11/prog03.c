#include <stdio.h>
#include <stdlib.h>
#include "stulist.h"

NodePointer oldnode;

int main(){
  FILE *fp;
  int i=0;  
  Record record;
  
  //head定義
  head = make_1node(record, NULL);
  oldnode = head;
  //File open
  fp = fopen("Student1.dat","r");
  if(fp == NULL){
    printf("File read ERROR!\n");
    exit(0);
  }

  //読み込み
  while(1){
    //EOFになるまで読み込ませる
    if(EOF!=fscanf(fp, "%d%s%d%d%d", &record.id, &record.name,
		   &record.scorep[0], &record.scorep[1], &record.scorep[2])){
      if (insert(record) == NULL){//----データ挿入関数へジャンプ----
	printf("\nData %s(%d) is already on the list\n", record.name, record.id);
      }
    }else{
      //終端まで行ったらBreak
      break;
    }
  }
  //listで一覧を吐かせる
  listprint();

  while(1){
    //----各種データ入力----
    printf("Insert new data: (ID name score1 score2 score3) ->");
    //----Record型構造体の中身の入力----
    if(5==(scanf("%d%s%d%d%d", &record.id, &record.name, &record.scorep[0], &record.scorep[1], &record.scorep[2]))){
      if (insert(record) == NULL){//----データ挿入関数へジャンプ----
	printf("\nData %s(%d) is already on the list\n", record.name, record.id);
      }
      listprint();
    }
  }

  fclose(fp);
  
  return 0;
}
NodePointer insert(Record d){
  NodePointer newnode;
  //static NodePointer oldnode = head;

  if (finditem(d.id) == NULL){//該当IDを参照してすでになければ新規ノード作成。あればNULL返し
    newnode = make_1node(d, NULL);
    oldnode->next = newnode;
    oldnode = newnode;

    return newnode;
  }
  else return NULL;
}

void listprint(void){
  NodePointer n;

  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next){
    printf("%d\t%-14s%3d %3d %3d\n",n->data.id, n->data.name,
	   n->data.scorep[0], n->data.scorep[1], n->data.scorep[2]);
  }
  printf("\n");
}

NodePointer finditem(int keyid){
  NodePointer n;

  for (n = head; n->next != NULL; n = n->next) {
    if (n->next->data.id == keyid){//参照するIDが見付かればそのノードポインタを返す
      return n;
    }
  }

  return NULL;
}

NodePointer make_1node(Record key, NodePointer p){
  NodePointer n;

  if ((n = (NodePointer)malloc(sizeof(struct node))) == NULL) {
    printf("Error in memory allocation\n");
    exit(8);
  }

  n->data = key;
  n->next = p;

  return n;
}
