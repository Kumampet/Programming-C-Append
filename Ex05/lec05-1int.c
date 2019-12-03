#include <stdio.h>
int main()
{
   int i;
   int array[] = {11,22,33,44};
   long l_array[] = {123,234,345,456};

   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %d\n",i,&array[i],array[i]);
   }
   printf("\n%p\n\n",array);

   for(i = 0 ; i < 4 ; i++){
     printf( "%d %p %d\n",i,&l_array[i],l_array[i]);
   }
   printf("\n%p\n\n",l_array);


   return 0;
}
