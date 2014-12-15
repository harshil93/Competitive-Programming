#include "iostream"
#include "vector"
#include "stdint.h"
using namespace std;

struct prop
{
	int a, b, cost;
};

prop p[513];

int64_t dp[513];

int main()
{
	int t;
	cin>>t;

	while(t--){
		int l,k;
		cin>>l>>k;
		for (int i = 0; i < 513; ++i)
		{
			dp[i]=1000000000;
		}
		dp[0] =0;
		for (int i = 0; i < k; ++i)
		{
			cin>>p[i].a>>p[i].b>>p[i].cost;
		}
		bool mark = false;
		int next = -1;
		for (int i = 1; i <= l; ++i)
		{
			if(mark && i<=next){
				dp[i] = dp[i-1];
				continue;
			}else{
				mark = false;
			}
			
			for (int j = 0; j < k; ++j)
			{
				if(i>=p[j].a && i<=p[j].b){

					if(dp[i]>dp[p[j].a - 1] + p[j].cost){
						dp[i] = dp[p[j].a - 1] + p[j].cost;
						next = p[j].b;
						mark = true;
					}
					
				}
			}

			for (int z = 0; z < count; ++z)
			{
				/* code */
			}
		
		}
		int f=0;
		for (int i = 1; i <= l; ++i)
		{
			if(dp[i]>=1000000000){
				f=1;
				break;
			}
		}

		if(f){
			cout<<"-1"<<endl;
		}else{
			cout<<dp[l]<<endl;
		}
	}
	return 0;
}