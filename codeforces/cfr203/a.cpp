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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int main(){
	int n,m;
	cin>>n>>m;
	int c[101];
	int w[101];

	for (int i = 0; i < n; ++i)
	{
		cin>>c[i];
	}

	for (int i = 0; i < m; ++i)
	{
		cin>>w[i];
	}

	sort(c,c+n);
	sort(w,w+m);
	int ans = -1;
	if(2*c[0] >= w[0]){
		ans = -1;
	}else{
		for (int i = c[n-1]; i < w[0]; ++i)
		{
			if(i>=2*c[0]){
				ans = i;
				break;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}