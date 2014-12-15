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

ll dis(pair<ll,ll> a, pair<ll,ll> b){
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.secon)d;
}

bool isSquare(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c, pair<ll,ll> d)
{
	ll d1 = dis(a,b);ll d2 = dis(a,c);ll d3 = dis(a,d);
	if(d1 == 0) return false;
	if(d3 > d1 && d3 > d2) swap(c,d);
	

	if(d1 > d2 && d1 > d3)swap(b,c);

	ll di = dis(a,b);
	if(di == 0)return false;
	if(dis(b,c) == di && dis(c,d) == di && dis(a,d) ==di && dis(a,c) == 2*di && dis(b,d) == 2*di)
		return true;
	else
		return false;
	
}

ll brute(std::vector< pair<ll,ll> > a, std::vector< pair<ll,ll> > b, std::vector< pair<ll,ll> > c, std::vector< pair<ll,ll> > d){
	ll ans = 1000000;
	for (ll i = 0; i < a.size(); ++i)
		for (ll j = 0; j < b.size(); ++j)
			for (ll k = 0; k < c.size(); ++k)
				for(ll l = 0; l < d.size(); ++l){
					if(isSquare(a[i],b[j],c[k],d[l])){
						ans = min((long long)i+j+k+l,ans);
					}
				
			
		
	
	if(ans == 1000000){
		return -1;
	}
	return ans;
}

int main(){

	ll n;
	cin>>n;
	std::vector< std::vector< pair<ll,ll> > > pos(4*n,std::vector< pair<ll,ll> >(4));

	for (ll i = 0; i < n; ++i)
	{
		for (ll j = 0; j < 4; ++j)
		{
			ll a,b,x,y;
			cin>>x>>y>>a>>b;
			pos[4*i+j][0] = make_pair(x,y);
			pos[4*i+j][1] = make_pair( -(y-b) + a, (x-a) + b );
			pos[4*i+j][2] = make_pair(-(x-a) + a , -(y-b) + b  );
			pos[4*i+j][3] = make_pair((y-b) + a, -(x-a) + b);
		}
	}

	
	for (ll i = 0; i < 4*n; i = i+4)
	{
		cout<<brute(pos[i],pos[i+1],pos[i+2],pos[i+3])<<endl;
	}
	return 0;
}