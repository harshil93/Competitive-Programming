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
	int n; int a[1005];
cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	sort(a,a+n);
	cout<<a[n-1]<<" ";
	for (int i = 1; i < n-1; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<a[0];
	cout<<endl;

	return 0;
}