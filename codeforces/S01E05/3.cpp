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
	int t;

	cin>>t;

	while(t--){
		int64_t n;
		cin>>n;

		int64_t *a = new int64_t[n];

		for (int64_t i = 0; i < n; ++i)
		{
			cin>>a[i];
		}

		sort(a,a+n);

		cout<<2*(a[n-1] - a[0])<<endl;
	}

	return 0;
}