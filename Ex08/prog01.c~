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
  /* [実行] */
  
  printf( "size of str3:    %d\n", sizeof(str3) );
  printf( "size of str4:    %d\n", sizeof(str4) );
  /* [考察]上2つの説明：str3=>ポインタ配列で3つあるので12バイト str4=>文字列配列で空き要素も含め、合計21バイト */
  /* [実行] */

  printf( "size of str3[1]: %d\n", sizeof(str3[1]) );
  printf( "size of str4[1]: %d\n", sizeof(str4[1]) );
  /* [考察]上2つの説明：                              */
  printf( "\n" );

  str5 = str4;        /* str5はstr4の先頭を指す */
  printf( "size of str5:    %d\n", sizeof(str5) );
  /* 説明：                                     */

  printf( "(*str5)[1]:      %c\n", (*str5)[1] );
  printf( "*str5[1]:        %c\n",  *str5[1] );
  /* 上2つの説明：                              */

  printf( "*(*str5+2):      %c\n", *(*str5+2) );
  printf( "**(str5+2):      %c\n", **(str5+2) );
  /* 上2つの説明：                              */
  printf( "\n" );

  arr2 = (int *) malloc( 5 * sizeof(int) );
  printf( "size of arr1:    %d\n", sizeof(arr1) );
  printf( "size of arr2:    %d\n", sizeof(arr2) );
  /* 上2つの説明：                              */

  free(arr2);
  return 0;
}
