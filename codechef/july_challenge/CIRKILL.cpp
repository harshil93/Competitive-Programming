#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

typedef struct pt
{
	float x;
	float y;
} pt;

typedef struct line
{
	float  m;
	pt c;
} line;

typedef struct circle
{
	pt c;
	float r;
} circle;

float slope(pt pt1,pt pt2){
	return (pt1.y - pt2.y)/(pt1.x - pt2.x + 1e-8);
}

float perp_slope(pt pt1,pt pt2){
	return (-1.0) / slope(pt1,pt2);
}

pt midpoint(pt pt1,pt pt2){
	pt temp;
	temp.x = (pt1.x + pt2.x)/2;
	temp.y = (pt1.y + pt2.y)/2;
	return temp;
}

pt intersection(line ln1, line ln2){
	pt inter_point;
	inter_point.x  = (ln1.c.y - ln2.c.y + ln2.m * ln2.c.x - ln1.m * ln1.c.x)/(ln2.m - ln1.m + 1e-8);
	inter_point.y = (ln2.m * ln1.c.y - ln1.m * ln2.c.y + ln1.m * ln2.m*(ln2.c.x - ln1.c.x))/(ln2.m - ln1.m + 1e-8);
	return inter_point;
}

float dist(pt pt1, pt pt2){

	return sqrt(pow(pt1.x - pt2.x,2) + pow(pt1.y - pt2.y,2));
}

bool isinside(circle c, pt p){
	float val = pow(p.x - c.c.x,2) + pow(p.y - c.c.y,2) - pow(c.r,2);
	if(val>0){
		return false;
	}else{
		return true;
	}
}
int main(){
	int t;
	cin>>t;
	pt tiles[31];
	while(t--){
		int n;
		cin>>n;
		float ashandar=0;
		float total=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>tiles[i].x>>tiles[i].y;
		}

		std::vector<bool> v(n);
		std::fill(v.begin() + 4, v.end(), true);

		do {
			vector<pt> fourpts;
		    for (int i = 0; i < n; ++i) {
		        if (!v[i]) {
		           fourpts.push_back(tiles[i]);
		           
		        }
		    }
		    for (int i = 0; i < fourpts.size(); ++i)
		    {
		    	pt ash = fourpts[i];
		    	// PR(ash.x)PR(ash.y)
		    	std::vector<pt> tr;
		    	for (int j = 0; j < 4; ++j)
		    	{
		    		if(i==j){
		    			continue;
		    		}else{
		    			tr.push_back(fourpts[i]);
		    		}
		    	}
		    	
		    	float slope1 = slope(tr[0],tr[1]);
		    	float slope2 = slope(tr[1],tr[2]);
		    	pt midpoint1 = midpoint(tr[0],tr[1]);
		    	pt midpoint2 = midpoint(tr[1],tr[2]);
		    	line l1;l1.m = slope1;l1.c = midpoint1;
		    	line l2;l2.m = slope2;l2.c = midpoint2;

		    	pt circle_center = intersection(l1,l2);
		    	float circle_radius = dist(circle_center,tr[0]);

		    	circle C;C.r = circle_radius; C.c = circle_center;
		    	total = total +1;
		    	if(isinside(C,ash)){
		    		// ?PR(ash.x) PR(ash.y) PR(C.c.x)PR(C.c.y) PR(C.r)
		    		ashandar= ashandar +1;
		    	}
		    }
		} while (std::next_permutation(v.begin(), v.end()));
		float ans =  1 -ashandar/total;
		// PR(ashandar)PR(total)
		printf("%lf\n",ans );
	}

	return 0;
}