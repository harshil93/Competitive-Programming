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
#define ll long long

int main(){
	ll n;
	cin>>n;
	std::vector<ll> a(n);
	std::vector<ll> cum(n,0);

	for (ll i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	cum[0] = a[0];
	for (ll i = 1; i < n; ++i)
	{
		cum[i] = cum[i-1] + a[i];
	}

	ll q;
	cin>>q;
	while(q--){
		ll r;
		cin>>r;
		// PR(r)
		std::vector<ll>::iterator it = lower_bound(cum.begin(),cum.end(),r);



		if(it==cum.begin()){
			cout<<it-cum.begin() + 1<<endl;
		}else if(cum[it-cum.begin() - 1] == r){
			cout <<it-cum.begin() <<endl;
		}else{
			cout<<it-cum.begin() + 1<<endl;
		}

	}

}