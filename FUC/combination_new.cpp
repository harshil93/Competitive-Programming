#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}
std::vector<int> temp;

void combinateUtil(std::vector< std::vector<int> > &ans, std::vector<int> v,int s, int e, int k){
	if(k==1){
		for (int i = s; i <=e; ++i)
		{
			temp.push_back(v[i]);
			ans.push_back(temp);
			temp.pop_back();
		}
		
		return ;
	}

	temp.push_back(v[s]);
	combinateUtil(ans, v, s+1, e, k-1);
	temp.pop_back();

	if(e-s+1 > k){
		combinateUtil(ans,v,s+1,e,k);
	}
	
	return ;
}

vector< vector<int> > combinate(std::vector<int> v, int s, int e, int k){
	std::vector< std::vector<int> > ans;
	combinateUtil(ans,v,s,e,k);

	return ans;
}





int main(){
	std::vector<int> v;
	int n,k;
	cin>>n>>k;

	for (int i = 1; i <= n; ++i)
	{
		v.push_back(i);
	}
	std::vector< std::vector<int> > ans;
	ans = combinate(v,0,n-1,k);
	cout<<"Combinations are here"<<endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < ans[i].size(); ++j)
		{
			cout<<ans[i][j]<<" ";
		} cout<<endl;
	}
	return 0;
}