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
	int n;

	std::vector< pair<int,int> > v;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int a,b; cin>>a>>b;
		v.push_back(make_pair(b,a));
	}

	int ind=0;
	int alexmax=v[0].second;
	int nikitamax = v[0].first;
	int max = v[0].second;
	for (int i = 0; i < n-1; ++i)
	{
		

		if(v[i+1].second > max){
			max = v[i+1].second;
			if(v[i+1].first > nikitamax){
				ind = i+1;
				nikitamax = v[i+1].first;
				
			}
		}
		
	}
	cout<<nikitamax<<endl;
}