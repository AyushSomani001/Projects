//Contributor: @"Ayush Somani"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define black false
#define white true

int size(FILE *a){
  int temp,ct=0;
  while(fscanf(a," %d",&temp)!=EOF)
    ct++;
  return ct;
}
void absolute(FILE * , FILE *);
bool check(FILE *, FILE *,int,int);
void torelative(FILE *f, FILE *fw,int sz);

int main()
{
  FILE *f, *f1;
  int size1,size2;
  //FIRST FILE
	f=fopen("1.pgm", "r");
  f1 = fopen("abs1.txt", "w");
  absolute(f,f1);
  fclose(f);
  fclose(f1);
  f=fopen("abs1.txt", "r");
  size1=size(f);
  f=fopen("abs1.txt", "r");
  f1=fopen("rel1.txt","w");
  torelative(f,f1,size1);
  fclose(f);
  fclose(f1);
  //SECOND FILE
  f=fopen("2.pgm", "r");
  f1 = fopen("abs2.txt", "w");
  absolute(f,f1);
  fclose(f);
  fclose(f1);
  f=fopen("abs2.txt", "r");
  size2=size(f);
  f=fopen("abs2.txt", "r");
  f1=fopen("rel2.txt","w");
  torelative(f,f1,size2);
  fclose(f);
  fclose(f1);
  //CHECK
  f=fopen("rel1.txt","r");
  f1=fopen("rel2.txt","r");
  bool ans=false;
  if(size1==size2)
    ans = check(f,f1,size1,size2);
  if(ans)
  {
    printf("The objects are same\n");
  }
  else
  {
    printf("The objects are different\n");
  }
  return 0;
}

void absolute(FILE *f, FILE *f1)
{
  char format[3];
  fscanf(f, "%s",format);
	int r, c, b, ulx, uly, urx, ury, llx, lly, lrx, lry, count1 =0, count2=0;
  fscanf(f, "%d %d %d", &r, &c, &b);
	bool mat[r+2][c+2];
  for(int i=0; i<=r+1; i++)
  {
		for(int j=0; j<=c+1; j++)
    {
      mat[i][j]=true;
    }
  }
	for(int i=1; i<=r; i++)
  {
		for(int j=1; j<=c; j++)
    {
			int temp;
      fscanf(f,"%d", &temp);
      mat[i][j] = (temp==255?true:false);
		}
	}
	for(int i=1; i<=r && count1!=1; i++)
  {
		for(int j=1; j<=c; j++)
    {
			if(count1==0&&mat[i][j]==0)
      {
				uly = i;
        ulx = j;
        count1 =1;
        break;
			}
		}
		for(int j=c; j>0; j--)
    {
			if(count2==0&&mat[i][j]==0)
      {
				ury = i;
        urx = j;
        count2 =1;
        break;
			}
		}
	}
	count1=0;
  count2=0;
	for(int i=r; i>0 && count1!=1; i--)
  {
		for(int j=1; j<=c; j++)
    {
			if(count1==0 && mat[i][j]==0)
      {
				lly = i;
        llx = j;
        count1 =1;
        break;
			}
		}
		for(int j=c; j>0; j--)
    {
			if(count2==0 && mat[i][j]==0)
      {
				lry = i;
        lrx = j;
        count2 =1;
        break;
			}
		}
	}
	//UPPER TO LOWER
	int px=ulx,py=uly;
	for(int i=uly+1;i<=lly;++i)
  {
		int tx;
    for(int j=0;;++j)
    {
      if(mat[i][j]==black)
      {
        tx=j;
        break;
      }
    }
		if(abs(tx-px)<=1)
    {
			if(tx<px)
       fprintf(f1, "5\n");
			else if(tx==px)
       fprintf(f1, "6\n");
			else
       fprintf(f1, "7\n");
		}
		else
    {
			if(mat[px][i+1]==black)
      {
				fprintf(f1, "6\n");
				if(tx>px)
        {
          for(int tt=0;tt<tx-px;++tt)
           fprintf(f1, "0\n");
         }
				else
        {
          for(int tt=0;tt<px-tx;++tt)
            fprintf(f1, "4\n");
        }
			}
			else
      {
				if(tx>px)
        {
           fprintf(f1, "7\n");
           for(int tt=1;tt<tx-px;++tt)
            fprintf(f1, "0\n");
        }
				else
        {
          fprintf(f1, "5\n");
          for(int tt=1;tt<px-tx;++tt)
          fprintf(f1, "4\n");
        }
		  }
	 }
   px=tx;
  }
	//FROm lower left to lower right
	for(int i= llx;i<lrx;i++ )
    fprintf(f1, "0\n");
	//LOWER TO UPPER
	px=lrx;
  py=lry;
	for(int i=lry-1;i>=ury;--i)
  {
		int tx;
    for(int j=c;;--j)
     if(mat[i][j]==black)
     {
       tx=j;
       break;
     }
		if(abs(tx-px)<=1)
    {
			if(tx>px)
      fprintf(f1, "1\n");
			else if(tx==px)
      fprintf(f1, "2\n");
			else
      fprintf(f1, "3\n");
		}
		else
    {
			if(mat[px][i-1]==black)
      {
				fprintf(f1, "2\n");
				if(tx<px)
        {
          for(int tt=0;tt<px-tx;++tt)
            fprintf(f1, "4\n");
        }
				else
        {
          for(int tt=0;tt<tx-px;++tt)
            fprintf(f1, "0\n");
        }
			}
			else
      {
				if(px>tx)
        {
          fprintf(f1, "3\n");
          for(int tt=1;tt<tx-px;++tt)
            fprintf(f1, "4\n");
        }
				else
        {
          fprintf(f1, "1\n");
          for(int tt=1;tt<tx-px;++tt)
            fprintf(f1, "0\n");
        }
			}
		}
		px=tx;
	}
	//FROM upper right to upper left
	for(int j=urx; j>ulx; j--)
    fprintf(f1, "4\n");
}
bool check(FILE *a, FILE *b,int size1,int size2){   //ASSUMES FRESH FILES AND SIZES
  int arr1[size1], arr2[size2];
  for(int i=0;i<size1;++i)
    fscanf(a," %d",&arr1[i]);
  for(int i=0;i<size2;++i)
    fscanf(b," %d",&arr2[i]);
  for(int i=0;i<size1;++i)
  {
    if(arr1[i]==arr2[0])
    {
      int j=0;
      bool stop=false;
      for(;j<size2;++j)
      {
        if(arr2[j]!=arr1[(j+i)%size1])
        {
          stop=true;
          break;
        }
      }
      if(!stop) return true;
    }
  }
  return false;
}
void torelative(FILE *f,FILE *f1,int size)
{
	int v[size], temp=0;
  while(fscanf(f," %d\n",&v[temp])!=EOF)
    temp++;
  int p=v[temp-1],c=v[0];
  for(int i=0;i<size; ++i)
  {
    int c=v[i];
    switch(c)
    {
      case 0:
      {
          switch(p)
          {
            case 0: {
              fprintf(f1,"2 \n");
              break;
            }
            case 1: {
              fprintf(f1,"3 \n");
              break;
            }
            case 2: {
              fprintf(f1,"4 \n");
              break;
            }
            case 3: {
              fprintf(f1,"5 \n");
              break;
            }
            case 4: {
              fprintf(f1,"6 \n");
              break;
            }
            case 5: {
              fprintf(f1,"7 \n");
              break;
            }
            case 6: {
              fprintf(f1,"0 \n");
              break;
            }
            case 7: {
              fprintf(f1,"1 \n");
              break;
            }
          }

        } break;
      case 1 :{
          switch(p){
            case 0: fprintf(f1,"1 \n");
              break;
            case 1: fprintf(f1,"2 \n");
              break;
            case 2: fprintf(f1,"3 \n");
              break;
            case 3: fprintf(f1,"4 \n");
              break;
            case 4: fprintf(f1,"5 \n");
              break;
            case 5: fprintf(f1,"6 \n");
              break;
            case 6: fprintf(f1,"7 \n");
              break;
            case 7: fprintf(f1,"0 \n");
              break;
          }
        } break;
      case 2 :
      {
          switch(p)
          {
            case 0: fprintf(f1,"0 \n");
             break;
            case 1: fprintf(f1,"1 \n");
              break;
            case 2: fprintf(f1,"2 \n");
              break;
            case 3: fprintf(f1,"3 \n");
              break;
            case 4: fprintf(f1,"4 \n");
              break;
            case 5: fprintf(f1,"5 \n");
              break;
            case 6: fprintf(f1,"6 \n");
              break;
            case 7: fprintf(f1,"7 \n");
              break;
          }

        } break;
      case 3 :
      {
        switch(p)
          {
            case 0: fprintf(f1,"7 \n");
              break;
            case 1: fprintf(f1,"0 \n");
              break;
            case 2: fprintf(f1,"1 \n");
              break;
            case 3: fprintf(f1,"2 \n");
              break;
            case 4: fprintf(f1,"3 \n");
              break;
            case 5: fprintf(f1,"4 \n");
              break;
            case 6: fprintf(f1,"5 \n");
              break;
            case 7: fprintf(f1,"6 \n");
              break;
          }

        } break;
      case 4 :{
        switch(p)
          {
            case 0: fprintf(f1,"6 \n");
              break;
            case 1: fprintf(f1,"7 \n");
              break;
            case 2: fprintf(f1,"0 \n");
              break;
            case 3: fprintf(f1,"1 \n");
              break;
            case 4: fprintf(f1,"2 \n");
              break;
            case 5: fprintf(f1,"3 \n");
              break;
            case 6: fprintf(f1,"4 \n");
              break;
            case 7: fprintf(f1,"5 \n");
              break;
          }

        } break;
      case 5 :{
        switch(p)
          {
            case 0: fprintf(f1,"5 \n");
              break;
            case 1: fprintf(f1,"6 \n");
              break;
            case 2: fprintf(f1,"7 \n");
              break;
            case 3: fprintf(f1,"0 \n");
              break;
            case 4: fprintf(f1,"1 \n");
              break;
            case 5: fprintf(f1,"2 \n");
              break;
            case 6: fprintf(f1,"3 \n");
              break;
            case 7: fprintf(f1,"4 \n");
              break;
          }

        } break;
      case 6 :{
        switch(p)
          {
            case 0: fprintf(f1,"4 \n");
              break;
            case 1: fprintf(f1,"5 \n");
              break;
            case 2: fprintf(f1,"6 \n");
              break;
            case 3: fprintf(f1,"7 \n");
              break;
            case 4: fprintf(f1,"0 \n");
              break;
            case 5: fprintf(f1,"1 \n");
              break;
            case 6: fprintf(f1,"2 \n");
              break;
            case 7: fprintf(f1,"3 \n");
              break;
          }

        } break;
      case 7 :{
        switch(p)
          {
            case 0: fprintf(f1,"3 \n");
              break;
            case 1: fprintf(f1,"4 \n");
              break;
            case 2: fprintf(f1,"5 \n");
              break;
            case 3: fprintf(f1,"6 \n");
              break;
            case 4: fprintf(f1,"7 \n");
              break;
            case 5: fprintf(f1,"0 \n");
              break;
            case 6: fprintf(f1,"1 \n");
              break;
            case 7: fprintf(f1,"2 \n");
              break;
          }

        } break;
    }
    p=c;
  }
}
