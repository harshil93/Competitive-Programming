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
	int k,d; cin>>k>>d;

	if(d==0 && k==1){
		cout<<0<<endl;
		return 0;
	}
	if(d==0){
		cout<<"No solution"<<endl;
		return 0;
	}

		cout<<d;
		for (int i = 0; i < k-1; ++i)
		{
			cout<<"0";
		}
		cout<<endl;
	

	

	return 0;
}