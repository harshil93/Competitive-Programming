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

char matrix[100][100];
int r,c;
int xC[] = {0,1,0,-1};
int yC[] = {1,0,-1, 0};
int checkPos(int x, int y){
	// cout<<x<<" "<<y<<endl;
	if(!(x<2 || y< 2 || x> r- 3 || y> c -3) ){
		bool check = true;
		for (int i = 0; i < 4; ++i)
		{
			
			if(matrix[x+ xC[i]][y+ yC[i]] != '^' || matrix[x+ 2* xC[i]][y+ 2*yC[i]] != '^'){
				// cout<<":2 "<<endl;
				check = false;
				break;
			}
		}

		return check?1:0;
		
	}else {
		return 0;
	}
}

int main(){
	int T;
	cin>>T;

	while(T--){
		cin>>r>>c;
		int count = 0;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				cin>>matrix[i][j];
			}
			
		}

		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
			{
				if(matrix[i][j] == '^')
					count += checkPos(i,j);
			}
		}

		cout<<count<<endl;

	}

	return 0;
}