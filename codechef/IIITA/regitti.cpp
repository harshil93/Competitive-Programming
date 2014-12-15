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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int64_t,int64_t> 
#define VI vector<int64_t> 
#define VII vector <VI >
#define REP(i,s,e) for(int64_t i=s; i<e; i++)
#define ff first
#define ss second
#define sc(t) scanf("%lld",&t);
int main(){
	int64_t t;
	sc(t);

	while(t--){
		int64_t n;
		sc(n);
		std::vector<int64_t> v(n,0);
		int64_t sum = 0;
		int64_t isneg = 0;
		for (int64_t i = 0; i < n; ++i)
		{
			sc(v[i]);
			sum+=v[i];
			if(v[i]<0) isneg = 1;
			v[i] = -v[i];
		}

		int64_t ms=INT_MIN,s=0;

		if(!isneg){
			printf("%lld\n",sum );
		}else{
			for (int64_t i = 0; i < n; ++i)
			{
				s +=v[i];

				if(s<0) s= 0;
				if(s>ms){
					ms = s;
				}
			}

			printf("%lld\n", sum + 2*ms );
		}
		


	}
}