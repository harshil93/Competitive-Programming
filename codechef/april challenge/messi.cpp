#include "cstdio"

using namespace std;


int main()
{
	long long int s[1001],result;
	int t,n,k;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&n,&k);
		s[1]=0;s[2]=k;
		if (n==2)
		{
			result=k;
		}else{
			for (int i = 3; i <= n; ++i)
			{
				s[i] = ((k-1)*s[i-1] + k*s[i-2])%1000000007;
			}
			result= s[n];
		}
		printf("%lld\n",result );
		
	}
}