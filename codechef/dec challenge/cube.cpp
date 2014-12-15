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
#define N 43

int main(){
	char in1[N][N][N] = {0};
	char in2[N][N][N] = {0};
	std::ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int dp[N][N][N] = {0};
		int n,p;
		cin>>n>>p;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				for (int k = 1; k < n+1; ++k)
				{
					cin>>in1[i][j][k];
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				for (int k = 1; k < n+1; ++k)
				{
					cin>>in2[i][j][k];
				}
			}
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j < n+1; ++j)
			{
				for (int k = 1; k < n+1; ++k)
				{
					dp[i][j][k] = dp[i-1][j][k] + dp[i][j-1][k] + dp[i][j][k-1] - dp [i-1][j-1][k] - dp[i-1][j][k-1] - dp[i][j-1][k-1] + dp[i-1][j-1][k-1];
					if(in1[i][j][k] == in2[i][j][k]) dp[i][j][k]++;
				}
			}
		}
		int sizeofsubcube=0;
		int noofsubcubes=0;
		for (int l = n; l >=1 ; --l)
		{
			for (int i = 1; i+l-1 <= n; ++i)
			{
				for (int j = 1; j+l-1 < n+1; ++j)
				{
					for (int k = 1; k+l-1 < n+1; ++k)
					{
						int temp = dp[i+l-1][j+l-1][k+l-1] -  dp[i+l-1][j+l-1][k-1] - dp[i+l-1][j-1][k+l-1] - dp[i-1][j+l-1][k+l-1] + dp[i+l-1][j-1][k-1] + dp[i-1][j+l-1][k-1] + dp[i-1][j-1][k+l-1] - dp[i-1][j-1][k-1];
						int tsz = l*l*l;
						int sz = (int) ceil((tsz*p)/100.0);
						if(temp>=sz){
							sizeofsubcube = l;
							noofsubcubes++;
						}
					}
				}
			}
			if(sizeofsubcube!=0){
				break;
			}
		}
		if(sizeofsubcube){
			cout<<sizeofsubcube<<" "<<noofsubcubes<<endl;
		}else{
			cout<<"-1"<<endl;
		}

	}
	return 0;

}