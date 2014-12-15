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
#define MOD 1000000007


int main(){
	int t; 
	cin>>t;
	while(t--){
		int n,m; cin>>n>>m;

		int f[11][501][10]={0};
		int h[10][501][10]={0};

		for (int i = 2; i <= n-1; ++i)
		{
			h[i][i][1] = 1 ;
			h[i][i][i] = 1 ;
			for (int j = i+1; j <= m; ++j)
			{
				for (int k = 1; k <= i; ++k)
				{
					if(k!=i && k!=1){
						h[i][j][k] = h[i][j-1][k-1] + h[i][j-1][k+1];
					}else if(k==i){
						h[i][j][k] = h[i][j-1][k-1]  + h[i-1][j-1][k-1];
					}else{
						h[i][j][k] = h[i][j-1][k-1];
						int s = i-1;
						for (int l = j-1; l >=2; --l)
						{
							if(s>1){
								h[i][j][k] +=h[s][l][1];	
								s--;
								PR(s)
							}
							
							
							
						}
					}
				}
			}

		}


		
		for (int i = 2; i <=n ; ++i)
		{
			f[i][i][0] = 1 ;
			f[i][i][i-1] = 0 ;
			for (int j = i+1; j <=m; ++j)
			{
				
				for (int k = 0; k <i; ++k)
				{
					if(k!=i-1 && k!=0){
						f[i][j][k] = f[i][j-1][k-1] + f[i][j-1][k+1];
					}else if(k==i-1){
						f[i][j][k] = f[i][j-1][k-1]  + f[i-1][j-1][k-1];
					}else{
						f[i][j][0]=f[i][j-1][1]+h[i-1][j-1][1];
						// cout<<i<<" "<<j-1<<" "<<k+1<<" "<<h[i-1][j-2][k+1]<<endl;
					}	
				}
			}
		}

		int sum = 0,sum2=0;
		for (int j = n-1; j <= m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				sum+= h[n-1][j][k];
				if(k==1) PR(h[n-1][j][k])
			}
			cout<<"###"<<j<<" "<<sum<<endl;
			sum =0;
		}
		PR(h[n-2][m-1][1])
		sum=0;int majorsum=0;
		for (int j = n; j <= m; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				sum+= f[n][j][k];
				// if(j==m) cout<<n<<" "<<j<<" "<<k<<" "<<f[n][j][k]<<endl;
			}
			// cout<<"@@"<<j<<" "<<sum<<endl;
			majorsum+=sum;
			sum =0;
		}
		PR(majorsum)
		cout<<endl;
	}
}