#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NF 128
#define NB 100

int main(int argc, char *argv[]){
  FILE *fp; /* ファイルポインタの宣言 */
  int i, n, c; /* n:行数 c:読み出した文字 */
  char infile[NF] = "in.txt"; /* 入力ファイルの初期値 */
  char buf[NB]; /* 一行分のファイル読み出しデータ */
  if(argc == 2) { /* ファイル名がコマンドラインで指定されている */
    if(strlen(argv[1]) + 1 > NF){ /* ファイル名が長すぎる */
      fprintf(stderr, "File name: %s is too long\n", argv[1]);
      exit(6);
    }
    strcpy(infile, argv[1]); /* 指定された入力ファイル名を設定 */
  }
  if((fp = fopen(infile, "r")) == NULL){ /* ファイルオープンとエラー処理 */
    fprintf(stderr, "%s open error\n", infile);
    exit(7);
  }

    for(n = 1; ;n++){ /* nをカウントアップする無限ループ */
      for(i = 0; i < NB; i++){ /* 1行読み込みループ */
	c = fgetc(fp); /* 一文字読み込み */
	if(c == EOF || c == '\n') { /* ファイル終端または改行判定 */
	  buf[i] = '\0' ; /* 文字列の終端文字を代入 */
	  break; /* ループ脱出 */
	}
	buf[i] = (char)c; /* 通常の場合は読み出した文字をbufに格納 */
      }
      if(i == NB){ /* 一行の行数がbufの大きさを超えた */
	fprintf(stderr, "Buffer overflow!\n");
	exit(8);
      }
      printf("%3d %3d %s\n", n, strlen(buf), buf); /* 行番号、長さ、行内容表示 */
      if(c == EOF) break; /* ファイルの終端の場合はループ脱出 */
    }
  fclose(fp); /* ファイルクローズ */
  return 0;
}
