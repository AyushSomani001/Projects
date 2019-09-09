//MAKING MIRROR IMAGES OF GIVEN PPM FILE
//Authors: Madhur Chauhan, Abhishek Tyagi, Utkarsh Aggarwal
#include<stdio.h>
int main()
{
  FILE *f,*fw;int i,j;
  f=fopen("blackbuck.ascii.ppm","r");
  fw=fopen("op.pgm","w");
  char format[3];
  fscanf(f,"%s",format);
  fprintf(fw,"%s",format);
  int r,c,b;
  fscanf(f,"%d %d %d",&r,&c,&b);
  fprintf(fw,"%d %d %d ",r,c,b);
  int rcb[c][3];
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      fscanf(f,"%d %d %d",&rcb[j][0],&rcb[j][1],&rcb[j][2]);
    }
    for(j=c-1;j>=0;j--)
    {
      fprintf(fw,"%d %d %d ",rcb[j][0],rcb[j][1],rcb[j][2]);
    }
  }
  return 0;
}
