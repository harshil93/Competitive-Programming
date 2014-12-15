/*The New Scheme*/

#include<stdio.h>

int modpow(int,int,int);

int main()
{
	int mod,N,T,val;
	mod=1000000007;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		val=modpow(3,N,mod);
		if(N&1)
			val=(val-3+mod)%mod;
		else
			val=(val+3)%mod;
		printf("%d\n",val);
	}
	return 0;
}

int modpow(int a,int b,int mod)
{
	long long product,psequence;
	product=1;
	psequence=a;
	while(b>0)
	{
		if(b&1)
			product=(product*psequence)%mod;
		b>>=1;
		psequence=(psequence*psequence)%mod;
	}
	return (int)product;
}