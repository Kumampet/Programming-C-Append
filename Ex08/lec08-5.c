#include <stdio.h>
#include <stdlib.h>

int main()
{
  int **arr;
  int tate,yoko,i,j;

  printf("tate yoko -> ");
  scanf("%d%d",&tate,&yoko);

  arr = malloc(sizeof(int *) * tate);

  for(i = 0; i < tate; i++)
    arr[i] = malloc(sizeof(int) * yoko);

  for(i = 0; i < tate; i++)
    for(j = 0; j < yoko; j++)
      arr[i][j] = i + j + 1;

  printf("size : %d\n",sizeof(arr));
  for(i = 0; i < tate; i++){
    for(j = 0; j < yoko; j++)
      printf("%2d ",arr[i][j]);
    printf("\n");
  }
  
  for(i = 0; i < tate; i++) free(arr[i]);
  free(arr);

  return 0;
}

