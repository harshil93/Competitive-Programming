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
 int64_t GCD(int64_t a, int64_t b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

 int64_t LCM(int64_t a, int64_t b)
{
   return b*a/GCD(a,b);
}

int main(){
	int64_t a,b,c,d;
	cin>>a>>b>>c>>d;

	if( (float)a/(float)b > (float)c/(float)d){
		int64_t y = LCM(b,d);
		// PR(y)
		int64_t mul1 = y/b;
		int64_t mul2 = y/d;
		// PR(mul1) PR(mul2)
		int64_t _a,_b,_c,_d;
		_a = mul1*a;
		_b = mul1*b;
		_c = mul2*c;
		_d = mul2*d;

		int64_t area1 = _a*_b; int64_t area2 = _c*_d;
		// PR(area1/area2);
		int64_t newNumber1 = area1 / GCD(area1, area2);
		int64_t newNumber2 = area2 / GCD(area1, area2);
		cout<<newNumber1- newNumber2<<"/"<<newNumber1<<endl;
		// cout<<1<<endl;
	}else{
		int64_t y = LCM(a,c);
		int64_t mul1 = y/a;
		int64_t mul2 = y/c;
		// PR(mul1) PR(mul2)
		int64_t _a,_b,_c,_d;
		_a = mul1*a;
		_b = mul1*b;
		_c = mul2*c;
		_d = mul2*d;

		int64_t area1 = _a*_b; int64_t area2 = _c*_d;
		// PR(area1/area2);
		int64_t newNumber1 = area1 / GCD(area1, area2);
		int64_t newNumber2 = area2 / GCD(area1, area2);
		cout<<newNumber1- newNumber2<<"/"<<newNumber1<<endl;
	}

	return 0;
}