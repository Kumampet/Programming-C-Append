#include <stdio.h>
#include <string.h>

int
main()
{
 char a[4];
 char b[5];

 a[0] = 'a';
 a[1] = 'b';
 a[2] = 'c';
 a[3] = '\0';

 b[0] = 'a';
 b[1] = 'b';
 b[2] = 'Z';
 b[3] = '5';
 b[4] = '\0';

 if (strncmp(a, b, 2) == 0) {
   printf("same\n");
 } else {
   printf("different\n");
 }

 return 0;
}
