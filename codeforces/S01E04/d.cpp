#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
int p[10000];
struct road
{
	int a,b,r;
	bool used;
	road(){
		used = false;
	}
};
struct pr
{
	int index;
	int set;
};
bool roadCmp(road x, road y){
	return x.r>y.r;
}
int main(){
	int t;

	while(t--){
		int n,m,c;
		cin>>n>>m>>c;
		road taxi[m];
		pr stn[n];
		for (int i = 0; i < n; ++i)
		{
			stn[i].index = i;
			stn[i].set = i;
		}
		for (int i = 0; i < m; ++i)
		{
			cin>>taxi[i].a>>taxi[i].b>>taxi[i].r;
		}

		sort(taxi,taxi+m,roadCmp);
	}
}