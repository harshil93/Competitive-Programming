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
	if(a.val!=b.val)
		return a.val<b.val;

	return a.ind<b.ind;
}

bool cmpn(p a, p b){

		return a.val<b.val;
}

bool cmpind(p a, p b){
	return a.ind < b.ind;
}
int main(){
	std::vector<p> v,orig;

	lint n,s;
	cin>>n>>s;

	for (lint i = 0; i < n; ++i)
	{
		p t;
		cin>>t.val; t.ind = i;
		v.push_back(t);
	}
	orig = v;
	lint tempsum=v[0].val;
	for (lint i = 1; i < n; ++i)
	{
		v[i].val += tempsum;
		tempsum = v[i].val;
	}
	sort(v.begin(),v.end(),cmp);

	lint diff = 0;
	lint cnt=0;

	/*for (lint i = 0; i < n; ++i)
	{
		cout<<v[i].val<<","<<v[i].ind<<" >" ;
	}
	cout<<endl;*/
	for (lint i = 0; i < n; ++i)
	{
		std::vector<p>::iterator low,up,indexit;
		p t; t.val= s+diff; t.ind = 0;
		low=std::lower_bound (v.begin(), v.end(), t,cmpn);
		up=std::upper_bound (v.begin(), v.end(), t,cmpn);
		/*PR(diff)
		PR(s+diff)
		PR((*low).val)
		PR((*low).ind)

		PR((*up).val)
		PR((*up).ind)*/

		p indexs; indexs.ind = i; 
		if(up-low>0){

			if(0) {
				cnt++;
				cout<<"added"<<endl;
			}
			else{
				indexit = std::lower_bound (low, up, indexs,cmpind);
				// PR((*indexit).val)
				// PR((*indexit).ind)
				cnt+= up - indexit;
			}
			
		}
		

		diff += orig[i].val;
		// cout<<endl;
	}

	cout<<cnt<<endl;
	
	return 0;
}