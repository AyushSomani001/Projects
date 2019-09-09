//Contributor @"Ayush Somani"

#include<bits/stdc++.h>
#define black false
#define white true
using namespace std;
int main(){
	freopen("FINAL.pgm", "r", stdin);  //freopen("op.txt", "w", stdout);
	string s; getline(cin,s);
	int r, c, b, ulx, uly, urx, ury, llx, lly, lrx, lry, count1 =0, count2=0; cin>>r>>c>>b;
	bool mat[r+2][c+2]; memset(mat, true, sizeof(mat));
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			int temp; cin>>temp; mat[i][j] = (temp==255?true:false);
		}
	}
	for(int i=1; i<=r && count1!=1; i++){
		for(int j=1; j<=c; j++){
			if(count1==0 && mat[i][j]==0){
				uly = i; ulx = j; count1 =1; break;
			}
		}
		for(int j=c; j>0; j--){
			if(count2==0 && mat[i][j]==0){
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
	//LOWER BOUND, UPPER
	//UPPER TO LOWER
	if(true){int px=ulx,py=uly;
	for(int i=uly+1;i<=lly;++i){
		int tx;for(int j=0;;++j) if(mat[i][j]==black) {tx=j; break;}
		if(abs(tx-px)<=1){
			if(tx<px) cout<<"5\n";
			else if(tx==px) cout<<"6\n";
			else cout<<"7\n";
		}
		else{
			if(mat[px][i+1]==black){
				cout<<"6\n";
				if(tx>px){ for(int tt=0;tt<tx-px;++tt) cout<<"0\n";}
				else { for(int tt=0;tt<px-tx;++tt) cout<<"4\n";}
			}
			else{
				if(tx>px){ cout<<"7\n"; for(int tt=1;tt<tx-px;++tt) cout<<"0\n";}
				else { cout<<"5\n"; for(int tt=1;tt<px-tx;++tt) cout<<"4\n";}
			}
		}
		px=tx;
	}
	//FROm lower left to lower right
	for(int i= llx;i<lrx;i++ ) cout<<"0\n";
	//LOWER TO UPPER
	px=lrx,py=lry;
	for(int i=lry-1;i>=ury;--i){
		int tx;for(int j=c;;--j) if(mat[i][j]==black) {tx=j; break;}
		if(abs(tx-px)<=1){
			if(tx>px) cout<<"1\n";
			else if(tx==px) cout<<"2\n";
			else cout<<"3\n";
		}
		else{
			if(mat[px][i-1]==black){
				cout<<"2\n";
				if(tx<px){ for(int tt=0;tt<px-tx;++tt) cout<<"4\n";}
				else { for(int tt=0;tt<tx-px;++tt) cout<<"0\n";}
			}
			else{
				if(px>tx){cout<<"3\n"; for(int tt=1;tt<tx-px;++tt) cout<<"4\n";}
				else { cout<<"1\n"; for(int tt=1;tt<tx-px;++tt) cout<<"0\n";}
			}
		}
		px=tx;
	}
	//FROM upper right to upper left
	for(int j=urx; j>ulx; j--) cout<<"4\n";}
	return 0;
}
