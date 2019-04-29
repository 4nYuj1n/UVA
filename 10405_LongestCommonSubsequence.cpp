#include <bits/stdc++.h>
using namespace std;
long long dp[1010][1010];
bool sudah[1010][1010];
long long solve(int posa,int posb,string a,string b)
{
	if(posa<a.size()&&posb<b.size())
	{
		if(sudah[posa][posb]==0)
		{
			sudah[posa][posb]=1;
			if(a[posa]==b[posb])
			{
				dp[posa][posb]=solve(posa+1,posb+1,a,b)+1;
			}
			else
			{
			dp[posa][posb]=max(dp[posa][posb],solve(posa,posb+1,a,b));
			dp[posa][posb]=max(dp[posa][posb],solve(posa+1,posb,a,b));
			}	
		}
		return dp[posa][posb];
	}
	else
	{
		return 0;
	}
}
int main(){
	string a,b;
	while(getline(cin,a))
	{
		getline(cin,b);
		int temp=solve(0,0,a,b);
		cout<<temp<<endl;
		memset(dp,0,sizeof dp);
		memset(sudah,0,sizeof sudah);
	}
}
