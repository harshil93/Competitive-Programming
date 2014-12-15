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
#include <functional>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )

int a[301][301];
int dp[301][301][11];
int dp1[301][301][11];

int main(){
	std::ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>a[i][j];
			// cout<<a[i][j]<<"\t";
		}
		// cout<<endl; 
	}
	dp[0][0][a[0][0]]++;

	for (int i = 1; i < n; ++i)
	{
		dp[i][0][a[i][0]]++;	
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			for (int k = 1; k < 11; ++k)
			{
				dp[i][j][k]+=dp[i][j-1][k];
			}
			dp[i][j][a[i][j]]++;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int k = 1; k < 11; ++k)
		{
			dp1[0][i][k] = dp[0][i][k];
		}
	}

	for (int j = 0; j < n; ++j)
	{
		for (int i = 1; i < n; ++i)
		{
			for (int k = 1; k < 11; ++k)
			{
				dp1[i][j][k] += dp[i][j][k] + dp1[i-1][j][k];
			}
		}
	}



	/*for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 10; k>= 1; --k)
			{
				cout<<dp1[i][j][k];
			}
			cout<<"\t";
		}
		cout<<endl;
	}*/




	int Q;
	cin>>Q;

	while(Q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		x1--;y1--;x2--;y2--;
		int temp1[11]={0},temp2[11]={0};
		if(x1==0 && y1==0){
			for (int i = 1; i < 11; ++i)
			{
					temp2[i] = dp1[x2][y2][i];
			}
		}else if(x1==0){
			for (int i = 1; i < 11; ++i)
				temp2[i] = dp1[x2][y2][i] - dp1[x2][y1 - 1][i] ;
		}else if(y1==0){
			for (int i = 1; i < 11; ++i)
				temp2[i] = dp1[x2][y2][i] - dp1[x1-1][y2][i] ;
		}else{
			for (int i = 1; i < 11; ++i)
				temp2[i] = dp1[x2][y2][i]- dp1[x1-1][y2][i] - dp1[x2][y1-1][i] + dp1[x1-1][y1-1][i];
		}
		/*for (int i = 10; i >=1; --i)
		{
			cout<<temp1[i]<<"\t";
		}
		cout<<endl;
		for (int i = 10; i >=1; --i)
		{
			cout<<temp2[i]<<"\t";
		}
		cout<<endl;*/
		int ans=0;
		for (int i = 1; i < 11; ++i)
		{
			if(temp2[i]>0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}


}