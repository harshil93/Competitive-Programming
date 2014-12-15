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
#include <climits>
#include <functional>
using namespace std;

#define MOD 1000000
bool isp[MOD];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int64_t n,a,b,c,d;
		int64_t x,y;
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
		bool isp[MOD]={false};
		x = d;
		isp[x] = true;
		int64_t ans=0;
		for (int i = 1; i < n; ++i)
		{
			y= (a*x*x + b*x + c)%MOD;
			isp[y] = !isp[y];
			x=y;
		}
		for (int i = 0; i < MOD; ++i)
		{
			if(isp[i]){
				ans = -1*ans + i;
			}
		}
		printf("%lld\n",ans );
	}
}