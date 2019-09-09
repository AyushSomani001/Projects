#include<bits/stdc++.h>
using namespace std;
int main()
{
	long int t;
	cin>>t;
	while(t>0)
	{
		long long int n,w;
		cin>>n>>w;
		if(w>=9)
			cout<<0<<endl;
		else
		{
			long long int p=1;
			long long int mod=1000000007;
			for(int i=1;i<=n-2;i++)
			{
				p=((p%mod)*(10))%mod;
			}
			p=(p*(9-w))%mod;
			cout<<p<<endl;
		}
		t--;
	}
	return 0;
}
