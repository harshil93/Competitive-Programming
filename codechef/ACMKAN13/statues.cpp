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
	int t=1;
	do{
		int n;
		cin>>n;
		if(n==0) break;
		int a[n];
		int64_t sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			sum+=a[i];
		}
		int opt = sum/n;
		int ans=0;
		for (int i = 0; i < n; ++i)
		{
			ans +=	(int) abs(opt - a[i]);
		}
		cout<<"Set #"<<t++<<endl;
		cout<<"The minimum number of moves is "<<ans/2<<"."<<endl;
		cout<<endl;

	}while(1);
}