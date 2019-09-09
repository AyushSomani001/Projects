#include<bits/stdc++.h>
#define black false
#define white true
using namespace std;
//Objective: seclusion of loop of black bits. output is made in .txt file.
int main(){
	freopen("YY1.pgm", "r", stdin);  freopen("op.txt", "w", stdout);
	string s; cin>>s;
	int r, c, b, x, y,count=0; bool mat[r+2][c+2];
	cin>>r>>c>>b;
	for(int i=0;i<r+2;++i) for(int j=0;j<c+2;++j) mat[i][j]=white;
	for(int i=1; i<=r; i++){
		for(int j=1; j<=c; j++){
			int temp; cin>>temp; mat[i][j]=(temp==255?white:black);
			if(count==0 && mat[i][j]==black){x = i; y = j; count=1;}
		}
	}
	//how to give input in an array ni aata.
	if(false){int i=x, j=y, z=99;
	do{
		if(mat[i][j+1]==black && mat[i-1][j+1]!=mat[i+1][j+1] && abs(z-0)!=4)
			{cout<<"0 "; j++; z=0;}
		else if(mat[i-1][j+1]==black && mat[i][j+2]!=mat[i-2][j] && abs(z-1)!=4)
			{cout<<"1 "; i--; j++; z=1;}
		else if(mat[i-1][j]==black && mat[i-1][j-1]!=mat[i-1][j+1] && abs(z-2)!=4)
			{cout<<"2 "; i--; z=2;}
		else if(mat[i-1][j-1]==black && mat[i][j-2]!=mat[i-2][j] && abs(z-3)!=4)
			{cout<<"3 "; i--; j--; z=3;}
		else if(mat[i][j-1]==black && mat[i+1][j-1]!=mat[i-1][j-1] && abs(z-4)!=4)
			{cout<<"4 "; j--;z=4; }
		else if(mat[i+1][j-1]==black && mat[i][j-2]!=mat[i+2][j] && abs(z-5)!=4)
			{cout<<"5 "; j--; i++; z=5;}
		else if(mat[i+1][j]==black && mat[i+1][j-1]!=mat[i+1][j+1] && abs(z-6)!=4)
			{cout<<"6 "; i++; z=6;}
		else if(mat[i+1][j+1]==black && mat[i+2][j]!=mat[i][j+2] && abs(z-7)!=4)
			{cout<<"7 "; i++; j++; z=7;}
		else{
			cout<<"NOT CYCLIC\n"; break;
		}
	}while(i!=x && j!=y);}
	return 0;
}
