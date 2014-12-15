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

struct p
{
	int w,h;
};

bool cmpW(p a, p b){
	return a.w<b.w;
}
bool cmpH(p a, p b){
	return a.h<b.h;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		std::vector<p> v;
		v.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i].w>>v[i].h;
		}

		sort(v.begin(),v.end(),cmpW);

		int cnt=0;
		std::multiset<int> myset;
		std::multiset<int>::iterator itlow,itup;
		for (int i = 0; i < n - 1; ++i)
		{
			
				if(myset.size() == 0){
					myset.insert(v[i].h);
					cnt++;
				}else{
					itlow = myset.lower_bound(v[i].h);
					if(itlow == myset.begin()) {
						cnt++;
						myset.insert(v[i].h);
					}else{
						itlow--;
						myset.erase(itlow);
						myset.insert(v[i].h);
					}
				
				}
		}

		PR(cnt) PR(myset.size())

	}
	return 0;
}