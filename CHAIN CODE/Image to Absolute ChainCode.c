//Contributor @"Ayush Somani"

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define black false
#define white true
int main(){
  FILE *f, *f1;
	f = fopen("FINAL.pgm", "r");
  f1 = fopen("op.txt", "w");
	char format[3];
  fscanf(f, "%s",format);
	int r, c, b, ulx, uly, urx, ury, llx, lly, lrx, lry, count1 =0, count2=0;
  fscanf(f, "%d %d %d", &r, &c, &b);
	bool mat[r+2][c+2];
  for(int i=0; i<=r+1; i++){
		for(int j=0; j<=c+1; j++){
      mat[i][j]=true;
    }
  }
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			int temp; fscanf(f,"%d", &temp); mat[i][j] = (temp==255?true:false);
		}
	}
	for(int i=1; i<=r && count1!=1; i++){
		for(int j=1; j<=c; j++){
			if(count1==0&&mat[i][j]==0){
				uly = i; ulx = j; count1 =1; break;
			}
		}
		for(int j=c; j>0; j--){
			if(count2==0&&mat[i][j]==0){
				ury = i; urx = j; count2 =1; break;
			}
		}
	}
	count1=0; count2=0;
	for(int i=r; i>0 && count1!=1; i--){
		for(int j=1; j<=c; j++){
			if(count1==0 && mat[i][j]==0){
				lly = i; llx = j; count1 =1; break;
			}
		}
		for(int j=c; j>0; j--){
			if(count2==0 && mat[i][j]==0){
				lry = i; lrx = j; count2 =1; break;
			}
		}
	}
	//UPPER TO LOWER
	int px=ulx,py=uly;
	for(int i=uly+1;i<=lly;++i){
		int tx;for(int j=0;;++j) if(mat[i][j]==black) {tx=j; break;}
		if(abs(tx-px)<=1){
			if(tx<px) fprintf(f1, "5\n");
			else if(tx==px) fprintf(f1, "6\n");
			else fprintf(f1, "7\n");
		}
		else{
			if(mat[px][i+1]==black){
				fprintf(f1, "6\n");
				if(tx>px){ for(int tt=0;tt<tx-px;++tt) fprintf(f1, "0\n");}
				else { for(int tt=0;tt<px-tx;++tt) fprintf(f1, "4\n");}
			}
			else{
				if(tx>px){ fprintf(f1, "7\n"); for(int tt=1;tt<tx-px;++tt) fprintf(f1, "0\n");}
				else { fprintf(f1, "5\n"); for(int tt=1;tt<px-tx;++tt) fprintf(f1, "4\n");}
		}
		px=tx;
	 }
  }
	//FROm lower left to lower right
	for(int i= llx;i<lrx;i++ ) fprintf(f1, "0\n");
	//LOWER TO UPPER
	px=lrx,py=lry;
	for(int i=lry-1;i>=ury;--i){
		int tx;for(int j=c;;--j) if(mat[i][j]==black) {tx=j; break;}
		if(abs(tx-px)<=1){
			if(tx>px) fprintf(f1, "1\n");
			else if(tx==px) fprintf(f1, "2\n");
			else fprintf(f1, "3\n");
		}
		else{
			if(mat[px][i-1]==black){
				fprintf(f1, "2\n");
				if(tx<px){ for(int tt=0;tt<px-tx;++tt) fprintf(f1, "4\n");}
				else { for(int tt=0;tt<tx-px;++tt) fprintf(f1, "0\n");}
			}
			else{
				if(px>tx){fprintf(f1, "3\n"); for(int tt=1;tt<tx-px;++tt) fprintf(f1, "4\n");}
				else { fprintf(f1, "1\n"); for(int tt=1;tt<tx-px;++tt) fprintf(f1, "0\n");}
			}
		}
		px=tx;
	}
	//FROM upper right to upper left
	for(int j=urx; j>ulx; j--) fprintf(f1, "4\n");
	return 0;
}
