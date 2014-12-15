#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

class TrafficCongestionDivTwo
{
public:
	long long theMinCars(int treeHeight){
		if(treeHeight==0 || treeHeight ==1){
			return 1;
		}
	
		long long ans = 1;
		if(treeHeight%2==0){
			
			long long cur = 2;
			ans = ans + cur;
			// PR(ans);
			for (int i = 1; i < treeHeight/2 ; ++i)
			{
				ans = ans + cur*4;
				cur = cur *4;
			}
		}else{
			long long cur = 4;
			ans = ans + cur;
			for (int i = 1; i < treeHeight/2; ++i)
			{
				ans = ans + cur*4;
				cur = cur*4;
			}
		}

		return ans;
	}
	/* data */
};

int main(){
	TrafficCongestionDivTwo test;

	while(1){
		int v;
		cin>>v;
		cout<<"@@"<< test.theMinCars(v)<<endl;
	}
}