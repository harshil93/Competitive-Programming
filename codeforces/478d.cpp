#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

const int mod = 1e9 + 7;
int getHeight(int r, int g){
	int h=1;
	while((h*(h+1))/2 <= r+g) h++;
	return h-1;
}

int main(){
	int r,g;
	cin>>r>>g;
	vector<int> dp(r+1,0);
	int height = getHeight(r,g);
	int elems = (height*(height+1))/2;
	dp[0] = 1;

	for(int i=1; i<=height; i++){
		for(int j=r; j>=i;j--){
			assert(j>=0 && j<r+1 && j-i>=0 && j-i<r+1);
			dp[j]+=dp[j-i];
			if(dp[j]>=mod)dp[j]-=mod;
		}
	}
	int ans = 0;
	
	for(int i = 0 ; i<= r ; i++){
		if(i+g >= elems){
			ans+= dp[i];
			if(ans>=mod) ans-=mod;
		}
	}
	cout<<ans<<endl;

	return 0;

}
