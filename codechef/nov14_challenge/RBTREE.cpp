#include <bits/stdc++.h>
using namespace std;
// #define PR(x) cout << #x " = " << x << "\n";
#define PR(x) ;
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> II; 
#define SZ(a) int((a).size()) 
#define PB push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FOR(i,n) for( int i =0 ; i < n ; i++ )
#define ll long long
#define FF first
#define SS second

ll f = 0;

ll lca(ll x,ll y){
	while(x!=1 && y!=1){
		if(x>y){
			x/=2;
		}else if(x<y){
			y/=2;
		}else{
			return x;
		}
	}
	return 1;	
}

ll ivpow(ll i){
	ll res = 0;
	while(i!=0){ i=i/2; res++;};
	return res;
}

ll countBlack(ll x){
	ll lev = ivpow(x);
	if(lev%2 != 0){
		return f==0?(lev/2+1):(lev/2);
	}
	return lev/2;
}

ll countRed(ll x){
	ll lev = ivpow(x);
	if(lev%2 != 0){
		return f==1?(lev/2+1):(lev/2);
	}
	return lev/2;
}

ll color(ll x){
	ll lev = ivpow(x);
	if(lev%2 == 0){
		return (1+f)%2;
	}else{
		return f%2;
	}
}

int main(){
	ll Q;
	cin>>Q;
	while(Q--){
		string qt;
		ll x,y;
		cin>>qt;
		if(qt == "Qi"){
			f = (f+1)%2;
		}else if(qt == "Qb"){
			cin>>x>>y;
			ll parent = lca(x,y);
			ll tx = countBlack(x);
			ll ty = countBlack(y);
			ll tp = countBlack(parent);
			PR(parent) PR(tx) PR(ty) PR(tp)
			PR(color(parent))
			cout<< (tx+ty-2*tp) + (color(parent)?0:1) <<endl;
		}else{
			cin>>x>>y;
			ll parent = lca(x,y);
			ll tx = countRed(x);
			ll ty = countRed(y);
			ll tp = countRed(parent);
			PR(parent) PR(tx) PR(ty) PR(tp)
			cout<< (tx+ty-2*tp) + (color(parent)?1:0) <<endl;
		}
	}
}