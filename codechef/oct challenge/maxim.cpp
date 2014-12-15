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

bool checkOverLucky(int n){
	bool ans = false;
	while(n!=0){
		int t = n%10;
		if(t==4 || t==7){
			ans=true;break;
		}
		n= n/10;
	}
	return ans;
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n;

		cin>>n;
		int ans=0;
		for (int i = 1; i < sqrt(n)+1; ++i)
		{
			if(n%i==0){
				if(checkOverLucky(n/i)) ans++;
				if(checkOverLucky(i)) ans++;
			}
		}
		cout<<ans<<endl;

	}
}