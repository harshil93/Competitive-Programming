#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define max(x,y) x>y?x:y
#define min(x,y) x<y?x:y
inline int64_t fast_int64()
{
int64_t n=0;
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}

unsigned long long nCk(int n,int k)
{
	unsigned long long val=1;
	if(k>(n/2)) k=n-k;
	for(int i=1;i<k+1;i++)
	{
		val = val * (n-i+1)/i ;
	}

	return val;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		n=fast_int64();
		int64_t D[10002];
		int64_t maxFromStart[10002]={0};
		int64_t maxFromEnd[10002]={0};
		int64_t minFromStart[10002]={0};
		int64_t minFromEnd[10002]={0};

		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&D[i]);
		}

		int64_t curr_max=D[0],max_so_far=D[0];
		int64_t curr_min=D[0],min_so_far=D[0];
		maxFromStart[0] = D[0];
		minFromStart[0] = D[0];

		for (int i = 1; i < n; ++i)
		{
			curr_max = max(D[i],curr_max+ D[i]);
			max_so_far = max(max_so_far,curr_max);
			maxFromStart[i] = max_so_far;

			curr_min = min(D[i],curr_min+ D[i]);
			min_so_far = min(min_so_far,curr_min);
			minFromStart[i] = min_so_far;


		}

		curr_max=D[n-1],max_so_far=D[n-1];
		curr_min=D[n-1],min_so_far=D[n-1];

		maxFromEnd[n-1] = D[n-1];
		minFromEnd[n-1] = D[n-1];
		for (int i = n-2; i >=0; --i)
		{
			curr_max = max(D[i],curr_max+ D[i]);
			max_so_far = max(max_so_far,curr_max);
			maxFromEnd[i] = max_so_far;

			curr_min = min(D[i],curr_min+ D[i]);
			min_so_far = min(min_so_far,curr_min);
			minFromEnd[i] = min_so_far;


		}

		int64_t answer = abs(maxFromStart[0] - minFromEnd[1]);
		for (int i = 0; i < n-1; ++i)
		{
			if (answer<abs(maxFromStart[i] -minFromEnd[i+1]))
			{
				answer = abs(maxFromStart[i] -minFromEnd[i+1]);
			}
		}

		for (int i = 0; i < n-1; ++i)
		{
			if (answer<abs(minFromStart[i] - maxFromEnd[i+1]))
			{
				answer = abs(minFromStart[i] - maxFromEnd[i+1]);
			}
		}

		printf("%lld\n",answer);

	}

	return 0;
}