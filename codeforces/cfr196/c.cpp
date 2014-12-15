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
#define MOD 1000000009



int main(){
	int n,m,k;

	cin>>n>>m>>k;
	int ans=0;

	int no_blocks;

	if( m%(k-1) ==0 ){
		no_blocks = m/(k-1);
	}else{
		no_blocks = ((m/(k-1)) + 1);
	}
	
	if( no_blocks - 1 <= n-m  ){
		
		ans = m;
	}else{
		int diff = n-m;
	
		int que_rem = n;

		while(diff--){
			que_rem = que_rem - (k-1);
			que_rem--;
			ans = ans + (k-1);
		}
		ans = ans % MOD;
		int ans_1 = ans;
		int scoreDoubleBlocks = que_rem/k;
		ans = 0;

		for (int i = 0; i < scoreDoubleBlocks; ++i)
		{
			ans = ans + k;
			ans = (ans * 2) ;
			if(ans>MOD)
				ans = ans% MOD;
		}
		ans += que_rem%k;
		ans = (ans+ans_1);
		if(ans>MOD)
				ans = ans% MOD;
	}

	cout<<ans<<endl;

	return 0;
}