#include <bits/stdc++.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
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
typedef std::numeric_limits< double > dbl;

ll ipow(ll base, ll exp)
{
	ll one = 1;
    ll result = one;
    while (exp)
    {
        if (exp & one)
            result *= base;
        exp >>= one;
        base *= base;
    }

    return result;
}

const int MAX = 62;
int main(){
	ll level[MAX+1];
	level[0] = 0;
	for(int i=0;i<MAX;i++) level[i+1] = ipow(2,i+1) - 1;

	int T;
	cin>>T;
	while(T--){
		ll x,k;
		cin>>x>>k;
		int pos = lower_bound(level,level+MAX,k) - level;
		pos--;
		k-=level[pos];
		double diff = (double)x/(ipow(2,pos+1));
		cout << fixed << setprecision(10);
		cout<<diff + (k-1)*2*diff<<endl;
	}
	
}