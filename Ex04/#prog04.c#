/*単語のスペルが正しいか否かを判定するプログラムを作成する。

標準入力から一つ単語を入力し、そのスペルが正しいかを判定する。 判定は Ctrl-D が入力されるまで繰り返す。
判定は、辞書ファイル /home/course/prog1/public_html/2017/ex/ex04/words.txt にその単語が存在する場合に限り、スペルが正しいと判定することとする（辞書ファイルの内容を各自で確認せよ）。
また、ファイル読み込みは、一度読み込んでしまうと前に戻ることは できないので、ファイルクローズした後、再度オープンすることで、 最初から読み込むことが可能となる。あるいは、rewind()関数を使うことでも 同様なことが可能である。 なお、この問題では strcmp などの関数を使ってもよい。
実行例をリスト４-1に示しておく。
(ヒント）

(提出ファイル名: prog04.c)
リスト4-1

% ./a.out 
Input a word: zoo
The word "zoo" is found.

Input a word: fruit
The word "fruit" is found.

Input a word: aizu
The word "aizu" is not found.

Input a word: Ctrl-D
% 

[注意]
ダブルクォート(")で囲った文字列の中に ダブルクォートをいれたい場合には、文字列中の ダブルクォート(")の前に バックスラッシュ(\)を入れる
例： printf("Use \"man string\"\n");*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define W 25200

int main(){
  char buf[20];//単語読取り
  char static dic[W];//辞書の単語ぶちこむ

  FILE *fpin;//辞書ファイルのファイルポインタ

  int i,cmp;

  

  while(1){
    fpin = fopen("words.txt","r");//辞書ファイルの開封（？）
    if(fpin == NULL){
      printf("Can't open this file\n");
      exit(1);
    }
  
    printf("Input a word:");
    cmp = scanf("%s",buf);
    if(cmp==-1)
      printf("END\n");
      break;
    cmp=0;

    
    for(i=0; i<W; i++){
      if(fscanf(fpin, "%s",dic)!=EOF){//辞書ファイルの中身を変数へ格納
	if(strcmp(dic,buf)==0){
	  cmp=1;
	  break;
	}
      }
    }
    if(cmp==1){
      printf("The word \"%s\" is found.\n\n",buf);	 
    }else{
      printf("The word \"%s\" is not found.\n\n",buf);
    }
  fclose(fpin);
  }
  
  return 0;
}
