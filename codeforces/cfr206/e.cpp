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
	int k; cin>>n>>k;

	int *a = new int[n];
	int mini = 1000000000;
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
		mini = min(mini,a[i]);
	}
	sort(a,a+n);
	bool t = true;
	for (int i = 0; i < n; ++i)
	{
		if(a[i]%mini > k){
			t = false;
			break;
		}
	}

	if(t){
		cout<<mini<<endl;
		return 0;
	}
	if(mini == 1){
		cout<<1<<endl;
		return 0;
	}else if(mini <= k){
		cout<<mini<<endl;
		return 0;
	}
	float minf=1000000000;
	for (int i = 1; i < n; ++i)
	{
		float z = ((float)a[i])/(mini - k) - ((float)a[i])/mini ;
		minf = min(minf, z);
	}
	
	cout<<mini - (int)minf<<endl;
}