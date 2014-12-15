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


int main(){
	int t;cin>>t;
	while(t--){
		int64_t n;
		cin>>n;
		std::vector<int> v(n);
		int64_t cnt0=0,cnt1=0,cnt2=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
			if(v[i] == 0) cnt0++;
			else if(v[i] == 1) cnt1++;
			else if(v[i] == 2) cnt2++;
		}
		// cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
		int64_t z = n - cnt0 - cnt1;
		z = (z*(z-1))/2 - (cnt2*(cnt2-1))/2;
		if(z<0) z=0;

		cout<<z<<endl;
	}
	return 0;
}