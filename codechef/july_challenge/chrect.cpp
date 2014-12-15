#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define sc(x) cin>>x;


int main(){
	int t ; sc(t);
	int ans;
	while(t--){
		int n,m,k;
		sc(n) sc(m) sc(k)
		if(n==1 && m==1){
			ans = 0;
			cout<<ans<<endl;
			return 0;
		}

		if((n==1 && m==2) || (m==1 && n==2)){
			ans = 0;
		}
		else if((n==1 && m>2) || (m==1 && n>2)){
			ans = k;
		}else{
			if(k%2==0){
				ans = k/2;
			}else{
				ans= k/2 +1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}