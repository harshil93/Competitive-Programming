#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define pr(x) cout << #x " = " << x << "\n";
#define min(a,b) a<b?a:b


int main(){
	int64_t t;
	int64_t **cost,**discount,**dp;
	scanf("%lld",&t);
	while(t--){
		int64_t n,m,min=-1;
		scanf("%lld %lld",&n,&m);
		cost = (int64_t **)malloc(n*sizeof(int64_t *));
		discount = (int64_t **)malloc(n*sizeof(int64_t *));
		dp = (int64_t **)malloc(n*sizeof(int64_t *));

		for (int64_t i = 0; i < n; ++i)
		{
			cost[i] = (int64_t *)malloc(m*sizeof(int64_t));
			discount[i] = (int64_t *)malloc(m*sizeof(int64_t));
			dp[i]= (int64_t *)malloc(m*sizeof(int64_t));
		}
		for (int64_t i = 0; i < n; ++i)
		{
			for (int64_t j = 0; j < m; ++j)
			{
				scanf("%lld",&cost[i][j]);
			}
		}
		for (int64_t i = 0; i < n; ++i)
		{
			for (int64_t j = 0; j < m; ++j)
			{
				scanf("%lld",&discount[i][j]);
			}
		}
		min = 0;
		for (int64_t i = 0; i < m; ++i)
		{
			dp[0][i]=cost[0][i];
			if (dp[0][i]<dp[0][min])
			{
				min = i;
			}
		}
		int64_t cur_min = min;

		for (int64_t i = 1; i < n; ++i)
		{
			min = 0;
			for (int64_t j = 0; j < m; ++j)
			{
				int64_t with_dis = dp[i-1][j]; 
				if (cost[i][j]-discount[i-1][j]>0)
				{
					with_dis += cost[i][j]-discount[i-1][j];
				}
				int64_t no_disc =  dp[i-1][cur_min] + cost[i][j];
				dp[i][j] = min(with_dis,no_disc);
				/*pr(i);pr(j);
				pr(with_dis);pr(no_disc);
				pr(dp[i-1][j])
				pr(cost[i][j] - discount[i-1][j])
				printf("\n");*/
			}

			for (int64_t j = 0; j < m; ++j)
			{
				if(dp[i][j]<dp[i][min]){
					min = j;
				}
			}
			cur_min = min;
		}
		min =dp[n-1][0];
		/*for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				printf("%lld\t", dp[i][j]);
			}
			printf("\n");
		}*/
		for (int64_t i = 1; i < m; ++i)
		{
			if(dp[n-1][i]<min){
				min = dp[n-1][i];
			}
		}

		printf("%lld\n",min);


	}
}