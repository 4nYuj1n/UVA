#include <bits/stdc++.h>
using namespace std;
vector <int> num;
vector <int> ans;
int mn;
void ubah(string a)
{
	int x;
	for(x=0;x<a.size();x++)
	{
		int temp=0;
		while(a[x]!=' '&&x<a.size())
		{
			temp=temp*10;
			temp+=(int)a[x]-'0';
			x++;
		}	
		num.push_back(temp);
	}
}
bool cek(){
	int x;
	for(x=0;x<num.size()-1;x++)
	{
		if(num[x]>num[x+1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
		int n;
		cin>>n;
		int x;
		for(x=1;x<=n;x++)
		{
			int a;
			cin>>a;
			num.push_back(a);
		}
		int kanan=0;	
	
		while(cek()==false)
		{
			
			int mx=0;
			int pos=0;
			for(x=0;x<num.size()-kanan;x++)
			{
				if(num[x]>mx)
				{
					mx=num[x];
					pos=x;
				}
			}

	
		if(pos!=num.size()-kanan-1)
		{
			if(pos!=0)
			{
			ans.push_back(num.size()-pos);
			reverse(num.begin(),num.begin()+pos+1);
			}
			else if(pos==0)
			{
				ans.push_back(kanan+1);
				reverse(num.begin(),num.end()-kanan);
				kanan++;
			}
		}
		else
		{
			kanan++;
		}
		}
		ans.push_back(0);
		for(x=0;x<ans.size();x++)
		{
			if(x)
			{
				cout<<" ";
			}
			cout<<n-ans[x]+1;
		}
		cout<<endl;
		num.clear();
		ans.clear();
	}
