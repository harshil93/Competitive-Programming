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

#define min (x)<(y)?(x):(y)

int main(){
	int n,m;

	cin>>n>>m;

	std::vector<int> v;

	for (int i = 0; i < m; ++i)
	{
		int temp ; cin>>temp;
		v.push_back(temp);
	}

	sort(v.begin(),v.end());

	int diff = v[m-1];

	for (int i = 0; i <= m-n; ++i)
	{

		if(diff> (v[i+n-1] - v[i])){
			diff=v[i+n-1] - v[i];
		}
	}

	cout<<diff<<endl;
}