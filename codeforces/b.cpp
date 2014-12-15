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
	int m,r;
	cin>>m>>r;

	int no_days = m*m;
	double mainans=0;
	for (int i = 0; i < no_days; ++i)
	{

		/*cout<<"2.0000000000"<<endl;
		return 0;*/
		int circle_num1 = i/m + 1;
		int circle_num2 = m + 1 + i%m;
		int x1,y1,x2,y2;
		if(circle_num1>m){
			x1 = 2*r*(circle_num1 - m) - r;
			y1 = 2*r;
		}else{
			x1 = 2*r*circle_num1 - r;
			y1 = 0;
		}

		if(circle_num2>m){
			x2 = 2*r*(circle_num2 - m) - r;
			y2 = 2*r;
		}else{
			x2 = 2*r*circle_num2 - r;
			y2 = 0;
		}

		double ans = abs(x1-x2);
		if(x1!=x2 && y1!=y2){
			ans = ans + sqrt(2*r*r);
		}else if(x1 == x2 && y1!=y2){
			ans = ans + abs(y2-y1);
		}
		// PR(ans);
		mainans += ans;

	}
	cout.precision(10);
	mainans = mainans / (m*m);
	cout<<mainans<<endl;
	printf("%0.10lf\n",mainans );
	return 0;
}