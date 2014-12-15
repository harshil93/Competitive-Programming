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

#define INF 1000000000000000000ll
ll dp[202][202];
bool idp[202][202];

ll recur(int copen, int len) {
    if (copen < 0)
        return 0;
    if (len == 0)
        return copen == 0;
    ll &ret = dp[copen][len];
    if (idp[copen][len]) {
        ret = 0;
        ret += recur(copen + 1, len - 1);
        ret += recur(copen - 1, len - 1); 
        if (ret > INF)
            ret = INF;
    }
    return ret;
}


int main(){
	memset(dp,0,sizeof(dp));
	int T;
	cin>>T;
	int _t = 1;

	dp[0][0] = 1;

	recur(0,201);

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	while(T--){
		cout<<"Case #"<<_t++<<": ";
		ll n,k;
		cin>>n>>k;
		n = n + n;

		if(dp[1][n] < k){
			cout<<"Doesn't Exist!"<<endl;
			continue;
		}
		int co = 0;
		int i=0;
		for (i = 0; i < n; ++i)
		{
			if(dp[co][n-i-1] > k){
				cout<<"(";
				co++;
				continue;
			}

			if(dp[co][n-i-1] == k){
				break;
			}
			cout<<")";
			co--;
			k -= dp[co][n-i-1];
		}
		

	}
}