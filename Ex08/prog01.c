#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *str1= "EXAMINATION";
  char str2[]="examination";
  char *str3[]={"WXYZ","mnopqr","ABC"};
  char str4[3][7]={"wxyz","MNOPQR","ABC"};
  char (*str5)[7];
  int  arr1[5];
  int  *arr2;

  printf( "size of str1:    %d\n", sizeof(str1) );
  printf( "size of str2:    %d\n", sizeof(str2) );
  /* [考察]上2つの説明：str1=>ポインタなので4バイト, str2=>char型の11文字+\0で12バイト  */
  
  printf( "size of str3:    %d\n", sizeof(str3) );
  printf( "size of str4:    %d\n", sizeof(str4) );
  /* [考察]上2つの説明：str3=>ポインタ配列が3つあるので12バイト str4=>文字列配列で空き要素も含め、合計21バイト */

  printf( "size of str3[1]: %d\n", sizeof(str3[1]) );
  printf( "size of str4[1]: %d\n", sizeof(str4[1]) );
  /* [考察]上2つの説明： str3=>３つあるポインタ配列のうちひとつをさすので４バイト 
     str4=>文字列配列のうち一つめの文字列("wxyz")の合計なので空き要素含め7バイト   */
  printf( "\n" );

  str5 = str4;        /* str5はstr4の先頭を指す */
  printf( "size of str5:    %d\n", sizeof(str5) );
  /* 説明：str5=>str4の行数をみている。つかわれていない３行要素もカウントしている*/

  printf( "(*str5)[1]:      %c\n", (*str5)[1] );
  printf( "*str5[1]:        %c\n",  *str5[1] );
  /* 上2つの説明：(*str5)[1]=>str5=*str4かつ%cで文字を出力する様になっているので、str4の[1]要素の文字を表示  
     *str5[1]=>str4の２つめの文字列の先頭のアドレスを示すのでMが出力される*/

  printf( "*(*str5+2):      %c\n", *(*str5+2) );
  printf( "**(str5+2):      %c\n", **(str5+2) );
  /* 上2つの説明：str4の先頭から2番目のアドレスを指示。 
     二次元配列のstr4をポインタのポインタを使い文字列ごとに見て、str4[3][0]のアドレスを指示 */
  printf( "\n" );

  arr2 = (int *) malloc( 5 * sizeof(int) );
  printf( "size of arr1:    %d\n", sizeof(arr1) );
  printf( "size of arr2:    %d\n", sizeof(arr2) );
  /* 上2つの説明：arr1は４バイトのint型で５つの要素があるから合計で20バイト。
     arr2はひとつのint型ポインタだから４バイト。 */

  free(arr2);
  return 0;
}
