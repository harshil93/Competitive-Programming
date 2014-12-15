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

ll dp[5001];
bool idp[5001];
int n;
string str;

ll f(int i){

	if(i == n) return 1;
	
	if(idp[i]) return dp[i];

	if(str[i] == '0'){
		idp[i] = true;
		dp[i] = 0;
		return dp[i];
	}


	ll r1 = f(i+1);
	ll r2 = 0;

	if(i<n-1){
		string s="26";
		s[0] = str[i];
		s[1] = str[i+1];
		if(s <= "26"){
			r2 = f(i+2);
		}
	}
	idp[i] = true;
	dp[i] = r1+r2;
	return r1+r2;
	
}

int main(){
	while(cin>>str){
		if(str == "0") break;
		n = str.size();
		memset(idp,0,sizeof(idp));
		cout<<f(0)<<endl;
	}

}