#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define PR(x) cout << #x " = " << x << "\n";



long long x[105],y[105];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		long long matrix[105][105]={0};
		scanf("%d%d",&n,&m);
		for (int i = 0; i < m; ++i)
		{
			scanf("%lld%lld",&x[i],&y[i]);
		}
		for (int i = x[0]; i < y[0]+1; ++i)
		{
			matrix[0][i]=1;
		}

		for (int i = 1; i < m; ++i)
		{
			for (int j = 0; j < n+1; ++j)
			{
				for (int k = x[i]; k < y[i]+1; ++k)
				{
					if(j-k>=0){
						matrix[i][j]+=matrix[i-1][j-k];
						if (matrix[i][j]>=MOD)
						{
							matrix[i][j]=matrix[i][j]%MOD;
						}
					}
				}
			}
		}

		printf("%lld\n",matrix[m-1][n] );
	}
	return 0;
}