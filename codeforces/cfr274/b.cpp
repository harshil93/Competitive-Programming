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

#define FF first
#define SS second

int main(){
	std::ios_base::sync_with_stdio(false);

	int n,k; pair<int,int> a[10000];
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i].first;
		a[i].second = i+1;
	}

	std::vector<pair<int,int> > moves;

	for (int i = 0; i < k; ++i)
	{
		sort(a,a+n);
		if(a[0].FF >= a[n-1].FF - 1){
			break;
		}else{
			a[0].FF++;
			a[n-1].FF--;
			moves.push_back(make_pair(a[n-1].second,a[0].second));
		}
	}
		sort(a,a+n);

		cout<<a[n-1].first -a[0].first<<" "<<moves.size()<<endl;
		for (int i = 0; i < moves.size(); ++i)
		{
			cout<<moves[i].first<<" "<<moves[i].second<<endl;
		}
		return 0;
}