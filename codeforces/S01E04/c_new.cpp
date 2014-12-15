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
	int t;
	cin>>t;
	int dial[14];
	while(t--){
		int n; cin>>n;
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			int t; cin>>t;
			dial[i] = t;
			sum += dial[i];
		}
		int k1 = (sum + (n*(n-1))/2 ) % n;
		int k2 = (n*(n-1))/2;
		k2 = k2%n;

		if(k1==k2){
			cout<<"Sepehr"<<endl;
		}else{
			cout<<"Sohrab"<<endl;
		}
	}
	return 0;
}