#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define MIN(x,y) x<y?x:y
inline int fast_int()
{
int n=0;
int ch=getchar_unlocked();
while(ch<48)ch=getchar_unlocked();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
return n;
}
int M[105][105];
int minRats[105][105];

void printMatrix(int m,int n){
	for (int i = 1; i <=m; ++i)
	{
		for (int j = 1; j <=n; ++j)
		{
			printf("%d\t", M[i][j] );
		}
		printf("\n");
	}
	printf("-----------------------------------------\n");
}





int findMinMouse(int x, int y,int n, int m){
	int down=1000000;
	int right=1000000;
	// printMatrix(n,m);
	if (x==n && y==m)
	{
		int temp=0;
		if (M[x-1][y]==1)
		{
			temp++;
		}
		if (M[x][y-1]==1)
		{
			temp++;
		}
		if (temp<minRats[x][y])
		{
			minRats[x][y]=temp;
		}
		
		return temp;
	}
	if (x+1<=n && y<=m)
	{
		int temp = 0;
		std::vector<int> v_x,v_y;
		if ( (x-1) >= 1 && M[x-1][y]==1)
		{
			temp++;
			M[x-1][y]=2;
			v_x.push_back(x-1);
			v_y.push_back(y);
		}
		if (x+1<=n && M[x+1][y]==1)
		{
			temp++;
			M[x+1][y]=2;
			v_x.push_back(x+1);
			v_y.push_back(y);
		}
		if (y-1>=1 && M[x][y-1]==1)
		{
			temp++;
			M[x][y-1]=2;
			v_x.push_back(x);
			v_y.push_back(y-1);
		}
		if (y+1<=m && M[x][y+1]==1)
		{
			temp++;
			M[x][y+1]=2;
			v_x.push_back(x);
			v_y.push_back(y+1);
		}

		down = findMinMouse(x+1,y,n,m);
		down = down + temp;
		for (int i = 0; i < v_x.size(); ++i)
		{
			M[v_x[i]][v_y[i]] = 1;
		}

	}

	if (x<=n && y+1<=m)
	{
		int temp = 0;
		std::vector<int> v_x,v_y;
		if (x-1>=1 && M[x-1][y]==1)
		{
			temp++;
			M[x-1][y]=2;
			v_x.push_back(x-1);
			v_y.push_back(y);
		}
		if (x+1<=n && M[x+1][y]==1)
		{
			temp++;
			M[x+1][y]=2;
			v_x.push_back(x+1);
			v_y.push_back(y);
		}
		if (y-1>=1 && M[x][y-1]==1)
		{
			temp++;
			M[x][y-1]=2;
			v_x.push_back(x);
			v_y.push_back(y-1);
		}
		if (y+1<=m && M[x][y+1]==1)
		{
			temp++;
			M[x][y+1]=2;
			v_x.push_back(x);
			v_y.push_back(y+1);
		}

		right = findMinMouse(x,y+1,n,m);
		right = right + temp;
		for (int i = 0; i < v_x.size(); ++i)
		{
			M[v_x[i]][v_y[i]] = 1;
		}
	}
	// printf("x=%d y=%d\n",x,y );
	// PR(down);
	// PR(right);
	// printf("\n");
	if (right == 1000000 && down == 1000000)
	{
		minRats[x][y]=0;
		return 0;
	}
	minRats[x][y] = MIN(down,right);
	return MIN(down,right);
}
int main(){
	int t;
	for (int i = 0; i < 105; ++i)
	{
		for (int j = 0; j < 105; ++j)
		{
			minRats[i][j] = -1;
		}
	}
	t = fast_int();
	

	while(t--){
		int n = fast_int();
		int m = fast_int();

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				M[i][j] = getchar_unlocked() - '0';
			}
			getchar_unlocked();
		}

		int answer = findMinMouse(1, 1,n, m);
		
			printf("%d\n",answer );
		
		
		// printMatrix(n,m);
		// printf("-----------------\n");
	
	}
}