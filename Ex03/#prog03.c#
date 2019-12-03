#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10

int main(){
  double point_x[N],point_y[N],point_z[N],dist[N];
  double max_x=0.0,max_y=0.0,max_z=0.0,max_dist=0.0;
  int i=0,max_i;
  FILE *fpin,*fpout;

  fpin=fopen("coord.in","r");
  if(fpin==NULL){
    printf("read file open error\n");
    exit(1);
  }

  fpout = fopen("coord.out","w");
  if(fpout==NULL){
    printf("write file open error\n");
    fclose(fpin);
    exit(2);
  }

  while(fscanf(fpin, "%lf%lf%lf",&point_x[i],&point_y[i],&point_z[i])!=EOF){
    dist[i] = point_x[i]*point_x[i]+point_y[i]*point_y[i]+point_z[i]*point_z[i];
    dist[i] = sqrt(dist[i]);
    if(max_dist< dist[i]){
      max_x=point_x[i];
      max_y=point_y[i];
      max_z=point_z[i];
      max_dist=dist[i];
      max_i=i;
    }
    i++;
  }
  fprintf(fpout,"%3.1f %3.1f %3.1f (%3.1f)\n",max_x,max_y,max_z,max_dist);

  fclose(fpout);
  fclose(fpin);

  return 0;
}



