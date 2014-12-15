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
	int cnt=0;
	while(n--){
		float x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;

		if((y2-y1)*(y3-y1) == -(x2-x1)*(x3-x1) || (y2-y3)*(y3-y1) == -(x2-x3)*(x3-x1) || (y2-y1)*(y3-y2) == -(x2-x1)*(x3-x2)){
			cnt++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}