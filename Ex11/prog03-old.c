#include <stdio.h>
#include <stdlib.h>
#include "stulist.h"

int main(){
  FILE *fp;
  int i;  
  Record record;
  
//----ファイル操作----
  if(NULL==(fp = fopen("Student1.dat","r"))){
    printf("File open error!\n");
    exit(0);
  }
  //----ノードヘッダーの初期化？----
  head = make_1node(record, NULL);
  printf("1-head reset OK\n");
  //----要素の読み出し＆書き出し----
  while(1){
    fscanf(fp,"%d%s%d%d%d", &record.id, &record.name,
	   &record.scorep[0], &record.scorep[1], &record.scorep[2]);
    printf("2-data read ok\n");
    if (insert(record) == NULL){//----データ挿入関数へジャンプ----
      printf("\nData %s(%d) is already on the list\n", record.name, record.id);
    }
  }  
  //----ノードヘッダーの初期化？----
  //head = make_1node(record, NULL);
  //----初期値の書き出し----
  //if (insert(record) == NULL){//----データ挿入関数へジャンプ----
  //  printf("\nData %s(%d) is already on the list\n", record.name, record.id);
  //}
  listprint();
//////////////////////////////////////////////////////////////////////////////////////
  
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
  return 0;
}
NodePointer insert(Record d){
  NodePointer newnode;

  if (finditem(d.id) == NULL){//該当IDを参照してすでになければ新規ノード作成。あればNULL返し
    newnode = make_1node(d, head->next);
    head->next = newnode;//headノードの次のノードを新規作成

    return newnode;
  }
  else return NULL;
}

void listprint(void){
  NodePointer n;

  printf("Head -\n");
  for (n = head->next; n != NULL; n = n->next) {
    printf("%d\t%-14s%3d %3d %3d\n",n->data.id, n->data.name, n->data.scorep[0], n->data.scorep[1], n->data.scorep[2]);
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
