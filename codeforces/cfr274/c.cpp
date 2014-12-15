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
	int n; cin>>n;
	pair<int,int> date[5001];
	
	for (int i = 0; i < n; ++i)
	{
		cin>>date[i].FF >> date[i].SS;
	}

	sort(date,date+n);

	int ans = min(date[0].FF,date[0].SS);

	for (int i = 1; i < n; ++i)
	{
		if(ans<= date[i].SS){
			ans = date[i].SS;
		}else{
			ans = date[i].FF;
		}
	}

	cout<<ans<<endl;

}