#include <stdio.h>

int main(){
   int i;
   int array[] = {11,22,33,44};
   long l_array[] = {123,234,345,456};
   char c_array[] = {'a','b','c','d'};
   char *str_array[] = {"A","BC","DEF","GHIJKLMN"};
   double d_array[] = {1e-3, 2e-4, 3e-5, 4e-6};
   char array_2dc[][10] = {"a","bcdef","ghi","jk"};

   /*----整数型(int)は一つが4バイトなので、
     変数ひとつにつき4バイト分のアドレスが確保されるので、
     変数ごとのアドレスの差は「4」----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %d\n",i,&array[i],array[i]);
   }
   printf("\n%p\n\n",array);

   /*----long型はひとつが4バイトなので、
    変数ひとつにつきint型同様4バイトのメモリ領域が確保されるので、
   変数ごとのアドレスの差は「4」----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %d\n",i,&l_array[i],l_array[i]);
   }
   printf("\n%p\n\n",l_array);

   /*----char型はひとつが1バイトなので、
    変数ひとつにつき1バイトのメモリ領域が確保されるので、
    変数ごとのアドレスの差は「1」----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %c\n",i,&c_array[i],c_array[i]);
   }
   printf("\n%p\n\n",c_array);

   /*----char型はひとつが1バイト、
    また「文字列」であるから文字数+NULL文字の数だけメモリ領域が確保されるので、
    通常は変数ごとのアドレスの差は文字数+NULL文字分の差分になるが、
    文字列配列をポインタの配列として表示させることによって、
    一次元配列の書式のままで表示させることができ、かつひとつの変数の差は4バイト----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %s\n",i,&str_array[i],str_array[i]);
   }
   printf("\n%p\n\n",str_array);

   /*----double型はひとつが8バイトなので、
    変数ひとつにつき8バイトのメモリ領域が確保されるので、
    変数ごとのアドレスの差は「8」----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %f\n",i,&d_array[i],d_array[i]);
   }
   printf("\n%p\n\n",d_array);

   /*----char型はひとつが1バイトなので、
    変数ひとつにつき1バイトのメモリ領域が確保されるが、
    文字列配列の二次元配列によりひとつの文字列の最大文字数が10文字まで確保されているので、
    変数ごとのアドレスの差は「10」----*/
   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %s\n",i,&array_2dc[i],array_2dc[i]);
   }
   printf("\n%p\n\n",array_2dc);



   return 0;
}
