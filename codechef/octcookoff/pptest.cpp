#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <climits>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int64_t,int64_t> 
#define VI vector<int64_t> 
#define VII vector <VI >
#define REP(i,s,e) for(int64_t i=s; i<e; i++)
#define ff first
#define ss second
#define pb push_back

int main(){
	int64_t t;
	cin>>t;

	while(t--){
		int64_t n,w;cin>>n>>w;
		std::vector<int64_t> t,c,p;
		int64_t dp[101][101]={0};

		for (int64_t i = 0; i < n; ++i)
		{
			int64_t a1,b1,c1;
			cin>>a1>>b1>>c1;
			c.pb(a1); p.pb(b1); t.pb(c1);
		}

		for (int64_t i = t[0]; i <=w; ++i)
		{
			dp[0][i] = c[0]*p[0];
		}
		int64_t sumg=0;
		for (int64_t i = 1; i < n; ++i)
		{
			for (int64_t j = 0; j <=w ; ++j)
			{
				int64_t sumt=0;
				if(j-t[i]<0){
					dp[i][j] = max(dp[i][j],dp[i-1][j]);
					continue;
				}
				for (int64_t k = 0; k <= j - t[i] ; ++k)
				{
					sumt = max(sumt,dp[i-1][k] + c[i]*p[i]);
				}
				dp[i][j] = max(sumt,dp[i-1][j]);
			}

		}

		for (int64_t i = 0; i < n; ++i)
		{
			for (int64_t j = 0; j <= w; ++j)
			{
				sumg = max(sumg,dp[i][j]);
			}
			
		}

		cout<<sumg<<endl;


	}
}