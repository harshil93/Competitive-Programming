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

	
	int x,y,x1,x2,y1,y2;
	int c;cin>>x>>y;
	if(x>0 && y>0){
		 c = x + y;
		 x1 = 0, y1 = c, x2 = c, y2 = 0;
	}else if(x<0 && y>0){
		 c = -x + y;
		 // PR(c)
		 x2 = 0, y2 = c, x1 = -c, y1 = 0;
	}else if(x<0 && y<0){
		 c = -x -y;
		 x2 = 0, y2 = -c, x1 = -c, y1 = 0;
	}else{
		 c = x - y;
		 x1 = 0, y1 = -c, x2 = c, y2 = 0;
	}

	cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	return 0;

}