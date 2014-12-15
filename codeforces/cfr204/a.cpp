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
	int n;
	cin>>n;
	int n5=0, n0=0;

	for (int i = 0; i < n; ++i)
	{
		int t;
		cin>>t;
		if(t==5) n5++;
		else n0++;
	}


	if(n0==0){
		cout<<-1<<endl;
	}else if(n5<9){
		cout<<0<<endl;
	}else{
		int k = n5/9;
		string ans="";
		for (int i = 0; i < k; ++i)
		{
			ans = ans + "555555555";
		}

		for (int i = 0; i < n0; ++i)
		{
			ans = ans+"0";
		}

		for (int i = 0; i < ans.size(); ++i)
		{
			printf("%c",ans[i] );
		}
		printf("\n");
	}

	return 0;
}

