#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

std::map<int64_t, int64_t> m;
int64_t asd(int64_t n){
	if(m[n]) return m[n];
	int64_t maxi =n/2 + 1;
	if(n==1){
		return 1;
	}
	if(n==2) return 2;
	if(n==3) return 2;
	
	for (int64_t i = 2; i < sqrt(n)+1; ++i)
	{
		if(n%i == 0){
			int64_t t= asd(i);
			maxi = min(maxi,((n/i)/2 + 1)*asd(i));
			maxi = min(maxi, (i/2 + 1)*asd (n/i));
		}
	}
	m[n] = maxi;
	return maxi;

};
int main(){
	int64_t n;
	m[1] = 1;
	m[2] = 2;
	m[3] = 2;
		cin>>n;
	cout<<asd(n)<<endl;
	
	

}

