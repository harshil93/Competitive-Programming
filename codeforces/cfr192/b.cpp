#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int main(){
	int m,n;
	cin>>n>>m;
	std::vector< pair<int,int> > v;

	if(n==1){
		cout<<"0"<<endl;
		return 0;
	}
	int cities[1001]={0};
	for (int i = 0; i < m; ++i)
	{
		int t1,t2;
		cin>>t1>>t2;
		v.push_back(make_pair(t1,t2));
	}

	for (int i = 0; i < v.size(); ++i)
	{
		cities[v[i].first]++;
		cities[v[i].second]++;
	}
	int index=0;
	for (int i = 1; i < 1001; ++i)
	{
		if(cities[i] == 0){
			index = i;
			break;
		}
	}
	cout<<n-1<<endl;
	for (int i = 1; i <= n; ++i)
	{
		if(index != i){
			cout<<index<<" "<<i<<endl;
		}
		
	}

}