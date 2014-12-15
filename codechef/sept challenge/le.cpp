#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

struct e
{
	double d;
	int a,b;
};

e mat[51];

double solve(int n,vector<bool> mark){
	double ans=0;
	if(n==0){
		if(!mark[mat[0].a]){
			ans+= mat[0].d/100;
		}
		if(!mark[mat[0].b]){
			ans+= 1 - mat[0].d/100;
		}
		// cout<<n<<"  "<<ans<<endl;
		return ans;
	}
	double ans1=0,ans2=0;
	if(!mark[mat[n].a]){
		mark[mat[n].a] = true;
		ans1 = solve(n-1,mark);
		mark[mat[n].a] = false;
	}
	
	if(!mark[mat[n].b]){
		mark[mat[n].b] = true;
		ans2 = solve(n-1,mark);
		mark[mat[n].b] = false;
	}
	// PR(n);
	// PR(mat[n].a)
	// PR(mat[n].b)
	// PR(ans1) PR(ans2)
	// PR(mat[n].d)
	return (mat[n].d/100)*ans1+ (1 - mat[n].d/100)*ans2;

}
int main(){
	int t;
	cin>>t;

	std::vector<bool> mark(17,false);
	while(t--){
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>mat[i].d>>mat[i].a>>mat[i].b;
		}

		if(n>16) printf("%0.7lf\n",0.0 );
		else
			printf("%0.7lf\n",solve(n-1,mark));


	}

	return 0;
}