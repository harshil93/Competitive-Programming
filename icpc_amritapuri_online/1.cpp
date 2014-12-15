#include <bits/stdc++.h>
using namespace std;

#define PR(x) cout<< #x << " = " <<x<<endl;
#define N 202
#define ll long long
#define INF 1000000000
ll W[N][N];

int m,n;
		
void input(){
		cin>>m>>n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin>>W[i][j];
			}
		}
}

ll sumO(int x, int y){
	ll maxi = -INF;
	maxi = maxi * INF;
	int i1=x-1,i2=x+1,j1=y-1,j2=y+1;

	if(!(i1>=0 && i2 < m && j1 >=0 && j2 < n)) return maxi;

	ll curSum = max(W[x][y],maxi);

	while(i1>=0 && i2 < m && j1 >=0 && j2 < n){
		curSum = curSum +  W[i1][j1] + W[i2][j2] + W[i1][j2] + W[i2][j1];
		i1--; i2++; j1--; j2++;
		maxi = max(maxi, curSum);
	}
	return maxi;
}

ll sumE(int x, int y){
	ll maxi = -INF;
	maxi = maxi * INF;
	int i1=x,i2=x+1,j1=y,j2=y+1;

	if(!(i1>=0 && i2 < m && j1 >=0 && j2 < n)) return maxi;

	ll curSum = 0;

	while(i1>=0 && i2 < m && j1 >=0 && j2 < n){
		curSum = curSum +  W[i1][j1] + W[i2][j2] + W[i1][j2] + W[i2][j1];
		i1--; i2++; j1--; j2++;
		maxi = max(maxi, curSum);
	}
	return maxi;
}

int main(){
	std::ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		input();
		ll res = -INF;
		res = res*INF;

		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				res = max(res,sumO(i,j));
				res = max(res,sumE(i,j));
			}
		}
		cout<<res<<endl;
	}
}