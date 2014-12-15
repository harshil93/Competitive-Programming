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
#include <iomanip>
#include <string>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int,int> 
#define VI vector<int> 
#define VII vector <VI >
#define REP(i,s,e) for(int i=s; i<e; i++)
#define ff first
#define ss second
int MODG= 1000000007;
inline int fast_int()
{
int n=0;
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}

int64_t modpow(int n,int k,int mod){
	if(k==0) return 1;
	int64_t ans = modpow(n,k/2,mod);
	ans = ans*ans;
	if(ans>=mod) ans = ans%mod;
	if(k%2) return (ans*n)%mod;
	else return (ans);
}

int64_t superpower(int n){
	int64_t r = 0;
	for (int i = 0; i < 32; ++i)
	{
		if(n & (1<<i)){
			r+= modpow(10,i,MODG-1);
		}
	}
	r = (2*r)%(MODG - 1);
	return modpow(2,r,MODG);
}
int main(){
	int t;
	t = fast_int();
	while(t--){
		int n = fast_int();
		printf("%lld\n", superpower(n));
	}

}