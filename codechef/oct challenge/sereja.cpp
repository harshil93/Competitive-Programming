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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define MOD 1000000007
int64_t powi(int64_t a, int64_t n){
	if(n==0){
		return 1;
	}else{
		int64_t retV = powi(a,n/2);
		int64_t rv = (retV*retV);
		if(rv >= MOD) rv = rv%MOD;
		if(n%2 == 0){
			return rv;
		}else{
			int64_t r = rv*a;
			if(r>=MOD)
				return (r)%MOD;
			else 
				return r;
		}
	}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int64_t n,m,q,k;cin>>n>>m>>q>>k;
		int64_t ans;
		ans = powi(q+1,n) - 2*powi(q,n) + powi(q-1,n);
		while(ans<0) ans+=MOD;
		ans = ((m-q) * ans)%MOD;
		if(m-q<0)
			cout<<0<<endl;
		else
			cout<<ans<<endl;
	}

	return 0;
}