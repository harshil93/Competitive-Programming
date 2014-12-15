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

		sort(dial,dial+n);
		int ans =1;
		do {
			ans =1;
			int temp[14];
			for (int i = 0; i < n; ++i)
			{
				temp[i] = dial[i];
			}

			for (int i = 0; i < n; ++i)
			{
				temp[i] = (temp[i]+i)%n;
			}

			sort(temp,temp+n);
			for (int i = 0; i < n-1; ++i)
			{
				if(temp[i+1]>temp[i]){

				}else{
					ans =0;
					break;
				}
			}
			if(ans){
				cout<<"Possible"<<endl;
				break;
			}
		} while ( std::next_permutation(dial,dial+n) );

		if(!ans){
			cout<<"Not Possible"<<endl;
		}

	}
}
