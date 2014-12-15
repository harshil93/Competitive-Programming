#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define M 1000000007
int l,m,q;
string s;
int d[20002][502];
vector<int> a[502][502][10];

int dp(int in,int l)
{
	if(in==-1)if(l==0)return 1;else return 0;
	int &r=d[in][l];
	if(r>=0)return r;
	if(l!=0)r=0;
	else r=1;
	for(int i=0;i<a[l][m][s[in]-'0'].size();i++)
	{
			r=r+dp(in-1,a[l][m][s[in]-'0'][i]);
	}
	return r;
}

int main()
{
	cin>>s;
	cin>>q;
	for(int i=1;i<500;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=0;k<10;k++)a[(j*10+k)%i][i][k].push_back(j);
		}
	}
	while(q--)
	{
		memset(d,-1,sizeof(d));
		cin>>m>>l;
		int ans=0;
		for(int i=0;i<s.size();i++)
		{
			ans=ans+dp(i,l);
		}
		cout<<ans<<endl;
	}	
}