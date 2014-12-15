#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
#define min(a,b) (a<b?a:b)
long long int gcd(long long a, long long b){
   if (b==0) return a;
   return gcd(b,a%b);
}

long long input[1000];
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
		long long int result = input[0];
		for(int i = 1; i < n; i++){
		    result = gcd(result, input[i]);
		}
				printf("%lld\n",result);



	}
	return 0;
}