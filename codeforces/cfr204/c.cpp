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
	double *a = new double[2*n];

	std::vector<double> vn,vp;
	for (int i = 0; i < 2*n; ++i)
	{
		double t; cin>>t;
		a[i] = t - (int) t;
	}

	for (int i = 0; i < 2*n; ++i)
	{
		if(a[i]>0.00001){
			vp.push_back(a[i]);
		}else if(a[i]< -0.00001){
			vn.push_back(a[i]);
		}
	}

	sort(vp.begin(),vp.end());
	sort(vn.begin(),vn.end());

	double diffp = 0;

	if(vp.size()%2 ==0){
		diffp += vp.size()/2;
		for (int i = 0; i < vp.size(); ++i)
		{
			diffp-=vp[i];
		}
	}else{
		diffp += vp.size()/2;
		for (int i = 0; i < vp.size() - 1; ++i)
		{
			diffp-=vp[i];
		}

		if(vp[vp.size()-1]>0.5){
			diffp+= (1 - vp[vp.size()-1]);
		}else{
			diffp-= vp[vp.size()-1];
		}
	}

	if(vn.size()%2 ==0){
		diffp -= vn.size()/2;
		for (int i = 0; i < vn.size(); ++i)
		{
			diffp-=vn[i];
		}
	}else{
		diffp -= vn.size()/2;
		for (int i = 0; i < vn.size() - 1; ++i)
		{
			diffp-=vn[i];
		}

		if(vn[vn.size()-1]>-0.5){
			diffp-= (vn[vn.size()-1]);
		}else{
			diffp+= (-1 - vn[vn.size()-1]);
		}
	}

}