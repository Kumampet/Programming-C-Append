#include <stdio.h>
#include <stdlib.h>
#include "prog03.h"

int input_planet (Planet *planet){
  FILE *fp;
  int i;

  fp = fopen("planet.txt","r");
  if(fp==NULL){
    printf("planet.txt reed error!\n");
    return -1;
  }
  for (i = 0; i < NPLANETS; i++) {
    if(4!=fscanf(fp,"%s%lf%lf%lf",&planet[i].name,&planet[i].radius,
		 &planet[i].density,&planet[i].orbital_radius)){
      return -1;
    }
  }
  return 0;
}
