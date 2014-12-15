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
	int t;
	cin>>t;
	while(t--){

		int n,m,c2,c3;
		
		cin>>n>>m>>c2>>c3;
		string mat[n];
		// cout<<"##"<<endl;
		for (int i = 0; i < n; ++i)
		{
			cin>>mat[i];
		}

		int cnt=0;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(mat[i][j] == 'B') cnt++;
			}
		}

		char c;

		if(cnt*c3<(m*n - cnt)*c2){
			c = 'B';
			cout<<cnt<<endl;
		} 
		else{
			 c='W';
			 cout<<m*n - cnt<<endl;
		}
		
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if(mat[i][j] == c){
					if(c=='B')cout<<3<<" "<<i+1<<" "<<j+1<<endl;
					else cout<<2<<" "<<i+1<<" "<<j+1<<endl;
				} 
			}
		}

	}

	return 0;
}