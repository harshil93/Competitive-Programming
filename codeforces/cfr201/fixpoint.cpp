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
	int n;
	cin>>n;
	int a[100000];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int count=0;
	int done =0;
	for (int i = 0; i < n; ++i)
	{
		if(a[i] == i) count++;
		else if(!done && a[a[i]] == i){
			done = 1;
			count = count+2;
		}
	}

	if(!done && count!=n){
		count++;
	}
	cout<<count<<endl;
	return 0;
}