#include <stdio.h>

void swap(int *, int *);

int main(){
  int a = 987, b = 321;

  printf("-Before-\n");  
  printf("start: a=%d\tb=%d\n", a, b);
  printf("Address: a=%p\t b=%p\n\n",&a,&b);
  
  swap(&a, &b);//値渡しするための関数へ飛す
  
  printf("-After-\n");
  printf("Address: a=%p\t b=%p\n",&a,&b);
  printf("end: a=%d\tb=%d\n", a, b);
  
  return 0;
}

void swap(int *x, int *y){
  
  int temp;

  printf("-Change-\n");
  printf("*x=%d\t *y=%d\n",*x,*y);
  printf("Address: x=%p\t y=%p\n",x,y);
  
  temp = *x;
  *x = *y;  
  *y = temp;

  printf("*x=%d\t *y=%d\n",*x,*y);
  printf("Address: x=%p\t y=%p\n\n",x,y);
}
