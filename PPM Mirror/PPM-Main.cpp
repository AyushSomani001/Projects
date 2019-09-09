#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
  freopen("blackbuck.ascii.ppm", "r", stdin);  freopen("op.ppm", "w", stdout);
  string s; getline(cin,s); cout<<s<<endl; //getline(cin,s); cout<<s<<endl;
  int r,c,b ;cin>>r>>c>>b; cout<<r<<" "<<c<<endl<<b<<endl; stack<int> sr,sg,sb;
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j) {int cr,cg,cb; cin>>cr>>cg>>cb; sr.push(cr);sg.push(cg); sb.push(cb);}
    for(int j=c-1;j>=0;--j) {cout<<sr.top()<<" "<<sg.top()<<" "<<sb.top()<<" "; sr.pop();sg.pop();sb.pop();}
    cout<<endl;
  }
  return 0;
}
