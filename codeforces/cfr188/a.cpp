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
	int64_t n,k;
	cin>>n>>k;
	int64_t mid = (n%2==0)?n/2:n/2 +1;
	if (k<=mid)
	{
		cout<< 2*(k-1) + 1<<endl;
	}else{
		cout<<(k-mid)*2<<endl;
	}

}