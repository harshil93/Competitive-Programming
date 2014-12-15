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
#include <stdint.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
uint64_t GCD(uint64_t a, uint64_t b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

 uint64_t LCM(uint64_t a, uint64_t b)
{
   return b*a/GCD(a,b);
}

int main(){
	int T;
	scanf("%d",&T);

	while(T--){
		int64_t n; 

		scanf("%lld",&n);
		uint64_t num=0;
		for (int64_t i = 1; i <= n/2; ++i)
		{
			int64_t rem = n%i;
			int64_t quo = n/i;
			if(quo>rem)
				num += quo;
			else{
				num += (rem/quo + 1)*quo; i = i+ rem/quo;
			}
		}
		num+= (n- n/2);

		uint64_t deno = n*n;

		uint64_t newNumber1 = num / GCD(num, deno);
		uint64_t newNumber2 = deno / GCD(num, deno);

		printf("%lld/%lld\n",newNumber1,newNumber2 );
	}
	return 0;

}