#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int main()
{
	int64_t a,b,m;
	cin>>a>>b>>m;
	int64_t temp,t;

	if (a<=0 && b<= 0)
	{
		if (a>=m || b>=m)
		{
			cout<<0<<endl;
		}else{
			cout<<-1<<endl;
		}
		return 0;
	}

	if (a>b)
	{
		t=b;
		b=a;
		a = b;
	}
	int64_t i=0;
	while(a<=m && b<=m){
		if (a>b)
		{
			b= a+b;
		}else{
			a = a+b;
		}
		i++;
	}

	cout<<i<<endl;
}