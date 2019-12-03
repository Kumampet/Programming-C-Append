#include <stdio.h>
#include <string.h> /* 文字列操作関数用ヘッダファイル */

int main()
{
  /*比較する単語２つを文字配列に格納する*/
  char wrd_1[] = "university"   /* 文字配列wrd_1を"university"で初期化 */,wrd_2[] = "japan";   /* 文字配列wrd_2を"japan"で初期化 */
  char buf[100];  /* 単語読み取り用の文字配列 */
  int i=0;

  /* 文字列の読み取りと置き換え        */
  /* 読取に成功している間は処理  FILE *fpin,*fpout;

  を続ける */
  while (scanf("%s",buf)==1){
    /*置き換え対象の文字と入力を比較し、
      一致したら先頭の文字を置き換える*/
    if (strcmp(buf,wrd_1)==0){
      strcpy(buf,"University");
    }
    else if (strcmp(buf,wrd_2)==0){
      strcpy(buf,"Japan");
    }
    printf( "%s ", buf );   /* 単語の間にスペースをひとつ入れて出力 */
  }
  printf("\n");

  return 0;
}
