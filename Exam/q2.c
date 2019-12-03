#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 15

int main()
{
  char str1[][N] = {"Mercury", "Venus", "Jupiter"};
  char *str2[] = {"Saturn", "Uranus", "Neptune"};
  char *ptr1;
  char (*ptr2)[N];
  int i;
  printf("(1) %d\n", (int)sizeof(str1));
  printf("(2) %d\n", (int)sizeof(str2));
  ptr1 = &str2[1][2];
  printf("(3) %c\n", *ptr1 + 1);
  printf("(4) %c\n", *(ptr1 + 1));
  printf("(5) %s\n", ptr1 + 1);
  ptr2 = malloc(3*N*sizeof(char));
  for(i = 0; i < 3; i++) strcpy(ptr2[i],str2[i]);
  printf("(6) %s\n", &ptr2[2][4]);
  printf("(7) %c\n", ptr2[2][1] + 1);
  printf("(8) %s\n", ptr2[0] + 1);
  free(ptr2);
  return 0;
}
