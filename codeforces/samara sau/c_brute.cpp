#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

typedef int64_t lint;

struct p
{
	lint ind,val;
};

bool cmp(p a, p b){
	return a.val<b.val;
}
int main(){
	std::vector<p> v,orig;

	lint n,s;
	cin>>n;
	
	p as; as.val = 0; as.ind = 0;
	v.push_back(as);
	for (lint i = 1; i <= n; ++i)
	{
		p t;
		cin>>t.val; t.ind = i;
		v.push_back(t);
		
	}

	for (lint i = 1; i < n+1; ++i)
	{
		v[i].val += v[i-1].val;
	}

	
	for(int s=0;s<100000;s++){lint cnt=0;for (lint i = 0; i < n+1; ++i)
		{ 
			for (lint j = i+1; j < n+1; ++j)
			{
				if(v[j].val - v[i].val == s){
					cnt++;
				}
			}
		}
	
		
		cout<<s<<" "<<cnt<<endl;}
	return 0;
}