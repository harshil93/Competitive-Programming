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
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )
#define MOD 1000000007
#define ll long long
#define N 100001
ll dp[N];

void recur(ll n, ll k){
	dp[0] = 1;

	for (ll i = 1; i < N; ++i)
	{
		if(i-k>=0){
			dp[i] = (dp[i-1] + dp[i-k])%MOD;
		}else{
			dp[i] = dp[i-1];
		}
	}
}

int main(){
	ll T,k;
	cin>>T>>k;
	recur(100000,k);
	ll cum[100002];
	cum[0] = 0;
	for (ll i = 3; i <= 100002; ++i)
	{
		cum[i-1] = cum[i-2] + dp[i-2];
	}


	while(T--){
		ll a,b;
		cin>>a>>b;

		cout<<(cum[b+1] - cum[a] + MOD)%MOD<<endl;
	}
}
