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


int makebtset(int &x){
	int t = x;
	int ans=0;
	while(t!=0){
		if(ans & 1<<(t%10))
			ans+=1<<(t%10);
		t = t/10;
	}
	return ans;
}
int main(){
	int n;

	while(cin>>n){
		int a[n];
		int btset[n];
		int sum[1025]={0};
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			btset[i] = makebtset(a[i]);
			sum[btset[i]] = max(a[i], sum[btset[i]]);
		}


		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <= 1024; ++j)
			{
				if(j & btset[i]){
					sum[j+btset[i]] = max(sum[j+btset[i]], sum[j] + sum[btset[i]]);
				}
			}
		}

	}
	
	return 0;
}