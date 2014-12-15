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
	int n, v; cin>>n>>v;
	vector < pair<int,int> > ab;

	int fruitscount[5000]={0};

	for (int i = 0; i < n; ++i)
	{
		int a,b ; cin>>a>>b;
		ab.pb(make_pair(a,b));
		fruitscount[a]+=b;
	}
	int ans = 0;
	
	for (int i = 1; i < 3002; ++i)
	{
		if(fruitscount[i]>0 || fruitscount[i-1]>0){
			if(fruitscount[i] + fruitscount[i-1]<=v){
				ans += fruitscount[i-1];
				fruitscount[i-1] = 0;
				ans += fruitscount[i];
				fruitscount[i] = 0;
			}else{
				if(fruitscount[i-1]<=v){
					int tv= v;
					ans += fruitscount[i-1];
					tv = tv - fruitscount[i-1];
					fruitscount[i-1] = 0;

					ans += tv;

					fruitscount[i] -= tv;
				}else{
					ans +=v;
					fruitscount[i-1] -= v;
				}
			}

			
		}
	}
	//sort(ab.begin(),ab.end());

	cout << ans<<endl;

	


	return 0;
}