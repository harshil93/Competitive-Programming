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
#include <climits>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int,int> 
#define VI vector<int> 
#define VII vector <VI >
#define REP(i,s,e) for(int i=s; i<e; i++)
#define ff first
#define ss second

int main(){
	int t;

	scanf("%d",&t);
	while(t--){
		std::map<int, int> x,y;
		int n;
		scanf("%d",&n);
		int64_t xcnt=0,ycnt=0;
		for (int i = 0; i < n; ++i)
		{
			int x_,y_;
			scanf("%d %d",&x_,&y_);
			
			if(!x[x_]){
				x[x_] = 1;
				xcnt++;
			}

			if(!y[y_]){
				y[y_] = 1;
				ycnt++;
			}
			
		}

		int64_t ans = (xcnt+1) * (ycnt+1);

		printf("%lld\n",ans );
	}

}