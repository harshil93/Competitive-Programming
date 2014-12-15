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
	int k;
	cin>>k;
	char in[5][5];
	std::vector<int> v;
	getchar();
	for (int i = 0; i < 4; ++i)
	{
		scanf("%s",in[i]);

	}

	REP(i,4)
		REP(j,4){
			if(in[i][j]!='.'){
				v.pb(in[i][j]);
			}
		}
	sort(v.begin(),v.end());
	int cnt=1;
	bool ans = true;
	for (int i = 0; i < v.size(); ++i)
	{

		if(v[i] == v[i+1]) cnt++;
		else{
			cnt = 1;
		}
		if(cnt>2*k){
			ans = false; break;
		}
	}
	if(ans) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}