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
	int64_t pos,val;
};

bool cmp(p x, p y){
	if(x.val == y.val){
		return x.pos<y.pos;
	}else
	return x.val<y.val;
}
int main(){
	int64_t n;
	cin>>n;
	p *a = new p[n+1];
	int64_t freq[100001] ={0};
	for (int64_t i = 0; i < n; ++i)
	{
		cin>>a[i].val;
		a[i].pos = i;
		freq[a[i].val]++;
	}

	sort(a,a+n,cmp);
	p ans[n];
	int64_t cnt=0;
	for (int64_t i = 0; i < n; i = i+ freq[a[i].val])
	{
		bool is=true; int64_t cd =0;
		if(freq[a[i].val]>1){
			cd =a[i+1].pos -  a[i].pos;
			for (int64_t j = i+1; j < i+ freq[a[i].val]; ++j)
			{
				if(cd != (a[j].pos - a[j-1].pos)){
					is = false;break;
				}
			}

			if(is){
				// cout<<a[i].val<<" "<<cd<<endl;
				ans[cnt].val = a[i].val;
				ans[cnt].pos = cd;
				cnt++;
			}
		}else{
			ans[cnt].val = a[i].val;
			ans[cnt].pos =0;
			cnt++;
		}
		
	}

	cout<<cnt<<endl;

	for (int64_t i = 0; i < cnt; ++i)
	{
		cout<<ans[i].val<<" "<<ans[i].pos<<endl;
	}

	return 0;
}