#include <stdio.h>
#include <string.h>

int checkString(char *);

int main(){
  int i;
  char newsstring[7][15]={"Good News", "Cool News", "Bad News",
              "Sweet News", "Sad News", "Happy News", "Wonderful News"};

  for(i = 0; i < 7; i++) {
    /* If a string contains the patterns "Bad" or "Sad", 
       replace it with the new string "COOL News". */
    if(1 == checkString(newsstring[i])){
      strcpy(newsstring[i],"COOL News");
    }
  }
  /* Print out the result */
  printf("--\n");
  for(i = 0; i < 7; i++){
    printf("%2d %s\n",i ,newsstring[i]);
  }
  printf("--\n");
  
  return 0;
}


/* Check whether a string contains the patterns "Bad" or "Sad" 
   at the first 3 characters using strncmp function */
/* Refer to the command "man strcmp" for the strncmp function. */
int checkString(char *str)
{
  int jadge=0;
  
  if(0 == (strncmp(str, "Bad", 3))||0 == (strncmp(str, "Sad", 3))){
    jadge = 1;
  }

   /* ここを作成する */  

  return jadge;

}
