#include <stdio.h>
#define EOF -1

char vowelxchg(char);

int main(){
  int n;
  char c;
  while(1){
    n = scanf("%c",&c);
    c = vowelxchg(c);

    if(n==EOF || '\n'==c){
      break;
    }
  }
  return 0;
}

char vowelxchg(char c){
  char ch;

  if('A'<= c && c <= 'Z'){
  ch = c+32;
  }else ch=c-32;
  
  return ch;
}
