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

int main(){
	int t; cin>>t;

	while(t--){
		int n; cin>>n;
		int a[n];
		int pos;
		int val;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
		}
		cin>>pos;
		val = a[pos-1];
		sort(a,a+n);
		for (int i = 0; i < n; ++i)
		{
			if(val == a[i]){
				cout<<i+1<<endl;
				break;
			}
		}

	}
}