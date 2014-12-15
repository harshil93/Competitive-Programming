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
	int r,c;
	cin>>r>>c;
	getchar();
	char matrix[11][11]={0};
	int rowcount[10]={0};
	int colcount[10]={0};
	int row_eaten = 0;
	int col_eaten =0;
	for (int i = 0; i < r; ++i)
	{
		bool flag= true;
		for (int j = 0; j < c; ++j)
		{
			matrix[i][j] = getchar();
			// cout<<i<<" "<<j<<" "<<matrix[i][j]<<endl;
			if(matrix[i][j] == 'S'){
				flag = false;
			}
		}
		getchar();

		if(flag){
			rowcount[i]++;
		}
	}

	for (int i = 0; i < c; ++i)
	{
		bool flag = true;
		for (int j = 0; j < r; ++j)
		{
			if(matrix[j][i] == 'S'){
				flag = false;
			}
		}

		if(flag){
			colcount[i]++;
		}
	}
	// cout<<"Row count"<<endl;
	for (int i = 0; i < r; ++i)
	{
		// PR(rowcount[i])
		if(rowcount[i]!=0){
			row_eaten++;
		}

	}

	if(row_eaten!=r){
		for (int i = 0; i < c; ++i)
		{
			if(colcount[i]!=0){
				col_eaten++;
			}
		}
	}

	int ans = row_eaten*c + col_eaten*(r - row_eaten);
	// PR(row_eaten) PR(col_eaten)
	cout<<ans<<endl;
	


}