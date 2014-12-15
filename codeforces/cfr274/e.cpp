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
#include <cstring>
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
#define FF first
#define SS second
#define MOD 1000000007
int n,a,b,k;
ll dp[5001][5001];
bool idp[5001][5001];
ll freq[5002][5002];

ll iabs(ll a){
	return a>0:a?-a;
}

ll recur(){

	dp[0][a] = 1;

	for (int i = 1; i <= k; ++i)
	{
		for (int i = 0; i < count; ++i)
		{
			dp[i][]
		}
	}

}

int main(){
	cin>>n>>a>>b>>k;
}