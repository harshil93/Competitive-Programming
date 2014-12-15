#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int main(){
	int t;
	cin>>t;
	int dial[14];
	while(t--){
		int n; cin>>n;

		for (int i = 0; i < n; ++i)
		{
			int t; cin>>t;
			dial[i] = t-1;
		}
		string ans="Possible";
		sort(dial,dial+n);
		if(n%2 == 0){
			for (int i = 0; i < n-1; ++i)
			{
				if(dial[i]!=dial[i+1]){
					ans = "Not Possible";
					break;
				}
			}
		}else{
			int neq =0;
			for (int i = 0; i < n-1; ++i)
			{
				if(dial[i]!=dial[i+1]) {
					neq = 1; break;
				}
			}

			if(neq){
				for (int i = 0; i < n-1; ++i)
				{
					if(dial[i]<dial[i+1]){

					}else{
						ans = "Not Possible";
						break; 
					}
				}
			}
		}

		cout<<ans<<endl;

	}
}
