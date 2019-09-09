/*
*Title:     INVERTING A GIVEN PGM IMAGE
*Authors:   Ayush Somani.
*Institute: Indian Institute of Technology (ISM), Dhanbad
*Remark:    Input and Output files must be in same directory with name changed in souce code.
*/
#include<stdio.h>
int main()
{
  FILE *f,*fw; int i,j;
  f=fopen("mona_lisaascii.pgm","r");
  fw=fopen("monalisaoutput.pgm","w");
  char format[10];
  fscanf(f," %s",format);
  fprintf(fw,"%s\n",format);
  fscanf(f," %s",format);
  fprintf(fw,"%s\n",format);
  int r,c,b;
  fscanf(f," %d %d %d",&r,&c,&b);
  fprintf(fw,"%d %d\n%d\n",r,c,b);
  int rcb[c];
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      fscanf(f,"%d ",&rcb[j]);
      fprintf(fw,"%d ",b-rcb[j]) ;
    }
    fprintf(fw, "\n");
  }
  fclose(f); fclose(fw);
  return 0;
}
