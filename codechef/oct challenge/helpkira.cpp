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

	int maxa=-1;
	int mina=100000000;
	int maxai=0,minai=0;

	for (int i = 0; i < n; ++i)
	{
		int x1,x2,x3,y1,y2,y3;

		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		int area = abs(x2*y3 - y2*x3 -(x1*y3 - y1*x3) + x1*y2 - y1*x2);
		// PR(area)
		if(area>=maxa){
			maxa= area;
			maxai = i+1;
		}

		if(area<=mina){
			mina= area;
			minai = i+1;
		}
	}

	cout<<minai<<" "<<maxai<<endl;
}