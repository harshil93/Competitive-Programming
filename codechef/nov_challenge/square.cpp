#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
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
int dp[100005];

int check(int64_t n){
	while(n!=0){
		int dig = n%10;
		if(dig == 4 || dig == 1 || dig == 0 || dig == 9){
			n = n/10;
		}else{
			return 0;
		}
	}
	
	return 1;
}


void preprocess(){
	int ans=0;
	for (int64_t i =1; i < 100001; ++i)
	{
		int64_t sq = i*i;
		ans+=check(sq);
		dp[i] = ans;
	}
	dp[100001] = dp[100000];
}
int main(){
	int t;
	preprocess();
	scanf("%d",&t);
	while(t--){
		int64_t a,b; 
		scanf("%lld %lld",&a,&b);
		a = ceil(sqrt(a));
		b = sqrt(b);
		printf("%d\n", dp[b] - dp[a-1]);
	}
	return 0;
}