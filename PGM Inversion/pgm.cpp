#include<bits/stdc++.h>
using namespace std;
int main()
{

  freopen("eyes.pgm", "r", stdin);  freopen("OPeyes.pgm", "w", stdout) ;
  string s; getline(cin,s); cout<<s<<endl;
  int r,c,b; cin>>r>>c>>b; cout<<r<<" "<<c<<" "<<b<<endl;
  for(int i=0;i<r;++i){
    for(int j=0;j<c;++j) {int temp; cin>>temp; cout<<abs(temp-b)<<" ";}
    cout<<endl;
  }
  return 0;
}
