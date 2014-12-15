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
#define REP(i,n) for(int i=0; i<n;i++)
int r,c;
int xC[] = {0,1,0,-1};
int yC[] = {1,0,-1, 0};
int checkPos(std::vector< std::vector<char> > &matrix,int x, int y){
	// cout<<x<<" "<<y<<endl;
	if(!(x<2 || y< 2 || x> r- 3 || y> c -3) ){
		bool check = true;
		for (int i = 0; i < 4; ++i)
		{
			
			if(matrix[x+ xC[i]][y+ yC[i]] == '#' || matrix[x+ 2* xC[i]][y+ 2*yC[i]] == '#'){
				check = false;
				break;
			}
		}

		return check?1:0;
		
	}else {
		return 0;
	}
}

void printMat(std::vector< std::vector<char> > mat){
	REP(i,r)
	{
		REP(j,c) cout<<mat[i][j];
		cout<<endl;
	}
}

struct p
{
	int x, y;
};

bool cmp(p a, p b){
	if(a.x == b.x) return a.y<b.y;
	return a.x<b.x;
}

int grundy[21][21][21][21];

int main(){
	int t;
	cin>>t;
	while(t--){
		std::vector< std::vector<char> > mat;
		vector<p> dragons;
		cin>>r>>c;
		mat.resize(r);
		for (int i = 0; i < r; ++i) mat[i].resize(c);
		REP(i,r) REP(j,c) cin>>mat[i][j];
		REP(i,r)
			REP(j,c)		
				if(mat[i][j] == '^')
					if(checkPos(mat,i,j)){
						mat[i][j]='d';
						p tmp; tmp.x=i;tmp.y=j;
						dragons.push_back(tmp);
					}
		sort(dragons.begin(),dragons.end(),cmp);

		
		printMat(mat);

		REP(i,r-1)
			REP(j,c-1)
				if(mat[i][j] == 'd')
					grundy[i][j][i][j] = 1;

		REP()

	}
}