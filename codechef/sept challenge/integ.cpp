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
	int64_t n;
	std::vector<int64_t> a;
	cin>>n;
	for (int64_t i = 0; i < n; ++i)
	{
		int64_t inp; cin>>inp;
		if(inp<0) a.push_back(inp);
	}
	int64_t x; cin>>x;
	sort(a.begin(),a.end());
	int64_t cost=0;
	
	if(x>=a.size()){
		for (int64_t i = 0; i < a.size(); ++i)
		{
			cost+=abs(a[i]);
		}
	}else{
		cost += abs(a[x])*x;

		for (int64_t i = 0; i < x; ++i)
		{
			cost+=abs(a[i] - a[x]);
		}
	}
	if(x!=0)
		cout<<cost<<endl;
	else
		cout<<0<<endl;


}