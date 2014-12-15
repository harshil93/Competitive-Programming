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
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> x,y;
		x.resize(n);
		y.resize(n);

		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&x[i]);
		}

		int no_1_y = 0,no_2_y =0;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",&y[i]);
			if(y[i] == 1) no_1_y++;
			if(y[i] == 2) no_2_y++;
		}
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());

		int64_t cnt=0;

		for (int i = 0; i < n; ++i)
		{
			int xcur  = x[i];
			int ycur = y[0];
			if(xcur == 1){
				continue;
			}else if(xcur == 2){
				cnt+=no_1_y;
				std::vector<int>::iterator up;
				up = upper_bound(y.begin(),y.end(),4);
				int pos = up - y.begin();
				cnt+= (n - pos);
			}else if(xcur == 3){
				cnt+=no_1_y;
				cnt+=no_2_y;
				std::vector<int>::iterator up;
				up = upper_bound(y.begin(),y.end(),3);
				int pos = up - y.begin();
				cnt+= (n - pos);
			}else{
				cnt+=no_1_y;
				std::vector<int>::iterator up;
				up = upper_bound(y.begin(),y.end(),xcur);
				int pos = up - y.begin();
				cnt+= (n - pos);
			}
		}

		double ans = (double)cnt/(double)n;

		printf("%0.6lf\n",ans );
	}
}