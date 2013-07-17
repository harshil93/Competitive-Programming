#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
	int t;
	long long a,b,n;
	int n_a=0, n_b=0;
	scanf("%d",&t);

	while(t--){
		scanf("%lld %lld %lld",&n,&a,&b);

		for (int i = 0; i < n; ++i)
		{
			if (a & 1)	
			{
				n_a++;
			}
			if (b & 1)
			{
				n_b++;
			}
			a >>= 1;
			b >>= 1;
		}
		long long ans=0;
		int j=n-1;
		j=n-1;
		if (n_a + n_b <= n)
		{
			for (int i = n_a + n_b - 1; i >=0; --i)
			{
				ans = ans + (long long)pow(2,j);
				j--;
			}
		}else{

			for (int i = n - (n_a+n_b - n) -1; i >=0; --i)
			{
				ans = ans + (long long )pow(2,j);
				j--;
			}
		}

		printf("%lld\n", ans);
		n_a=0; n_b =0;
		ans = 0;
	}
}