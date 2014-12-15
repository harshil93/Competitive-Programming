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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int,int> 
#define VI vector<int> 
#define VII vector <VI >
#define REP(i,s,e) for(int i=s; i<e; i++)
#define ff first
#define ss second
#define MOD 1000000007

int64_t modpow(int64_t n,int64_t k){
	if(k==0){
		return 1;
	}
	int64_t ans = modpow(n,k/2);
	ans = ans*ans;
	if(ans>=MOD) ans = ans%MOD;

	if(k%2){
		return (ans*n)%MOD;
	}else{
		return (ans)%MOD;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		cout<<modpow(2,n) - 1<<endl;
	}
	return 0;
}