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
	int n, v; 
	cin>>n>>v;
	std::vector< std::vector<int> > s;
	for (int i = 0; i < n; ++i)
	{
		int k; cin>>k;
		std::vector<int> t;
		for (int j = 0; j < k; ++j)
		{
			int temp; cin>>temp;
			t.pb(temp);
		}
		s.pb(t);
	}

	vector <int> ans ;
	for (int i = 0; i < s.size(); ++i)
	{
		for (int j = 0; j < s[i].size(); ++j)
		{
			if(s[i][j]< v){
				ans.pb(i+1);
				break;
			}
		}
	}

	cout<<ans.size()<<endl;
	for (int i = 0; i < ans.size(); ++i)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;


	return 0;
}