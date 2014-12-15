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
#include <limits>
#include <functional>
#include <cassert>
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
#define ll int
std::map< pair<int,int> , int > m;

#define INF numeric_limits<int>::max()

int arrMouse[131073];
int arrPos[131073];

inline ll iabs(ll a){
	if(a<0) return -a;
	return a;
}

ll recur(int remMouse,int remHoles){
	if(remMouse>remHoles){
		return INF;
	}

	if(remHoles == -1 && remHoles == -1 ){
		return 0;
	}

	pair<int,int > pp = make_pair(remMouse,remHoles);

	std::map< pair<int,int> , int >::iterator it = m.find(pp);

	if( it !=m.end() ){
		return (*it).second;
	}
	if(remMouse == -1){
		return 0;
	}

	ll a1 = max(iabs(arrPos[remHoles] - arrMouse[remMouse]),recur(remMouse-1,remHoles-1));

	ll a2 = recur(remMouse,remHoles-1);

	m[make_pair(remMouse,remHoles)] = min(a1,a2);

	return min(a1,a2);
}

int main(){
	std::ios_base::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--){
		m.clear();
		int Mi,Ni;
		cin>>Mi>>Ni;
		for (int i = 0; i < Mi; ++i)
		{
			cin>>arrMouse[i];
		}
		for (int i = 0; i < Ni; ++i)
		{
			cin>>arrPos[i];
		}

		sort(arrMouse,arrMouse+Mi);
		sort(arrPos,arrPos+Ni);

		if(Mi == Ni){
			int ans  = 0;
			for (int i = 0; i < Mi; ++i)
			{
				ans = max(ans,iabs(arrMouse[i] - arrPos[i]));
			}
			cout<<ans<<endl;
		}else{
			cout<<recur(Mi-1,Ni-1)<<endl;
		}
	} 
}