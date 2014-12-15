#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

long long int input[1000];
int main(){
	int t;
	int n;
	int isneq=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		// printf("n == %d\n",n );
		for (int i = 0; i < n; ++i)
		{
			scanf("%lld",&input[i]);

		}

		std::vector<long long int> v(input,input + n);
		std::sort (v.begin(), v.end());

		for (int i = 0; i < n-1; ++i)
		{
			if (v[i]!=v[i+1])
			{
				isneq=1;
				break;
			}
		}

		if (isneq==0)
		{
			printf("%lld\n",v[n-1]);
			continue;
		}

		while(1){
			isneq=0;
			// for (int i = 0; i < n; ++i)
			// {
			// 	printf("%lld \t",v[i]);
			// }
			// printf("\n");
			for (int i = n-1; i >0;--i)
			{
				v[i]=v[i]%v[i-1];
				// printf("v[i] = %lld \n" , v[i]);
				if (v[i]==0)
				{
					// printf("v[i-1]=%lld\n",v[i-1]);
					v[i]=v[i-1];
				}
				if (!isneq && v[i]!=v[i-1])
				{
					isneq=1;
				}
			}

			if (isneq==0)
			{
				break;
			}
			std::sort (v.begin(), v.end());
			
		}

		printf("%lld\n",v[n-1]);



	}
	return 0;
}