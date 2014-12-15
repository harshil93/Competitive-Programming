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
#include <climits>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int64_t,int64_t> 
#define VI vector<int64_t> 
#define VII vector <VI >
#define REP(i,s,e) for(int64_t i=s; i<e; i++)
#define ff first
#define ss second
#define MOD 1000000007
int64_t getSumDiff(int64_t y,int64_t x){
	if(x==y){
		return x%MOD;
	}
	return ((x*(x+1))/2 - (y*(y-1))/2)%MOD;
}

int64_t pow10(int64_t k){
	if(k==0){
		return 1;
	}
	int64_t t = pow10(k/2);
	if(k%2==0){
		return (t*t)%MOD;
	}else{
		return (t*t*10)%MOD;
	}
}

int64_t getDigs(int64_t n){
	int64_t retval =0;

	while(n!=0){
		retval++;
		n= n/10;
	}
	return retval;
}
int main(){
	int64_t t; cin>>t;

	while(t--){
		int64_t l,r;

		cin>>l>>r;
		int64_t sum = 0;
		for (int64_t i = l; i <= r; )
		{
			int64_t d = getDigs(i);
			int64_t  x = pow10(d);

			if(r>= x){
				sum+=d*getSumDiff(i,x-1);
				sum = sum%MOD;
				i=x;
			}else{
				sum+=d*getSumDiff(i,r);
				sum = sum%MOD;
				break;
			}
		}

		cout<<sum<<endl;
	}
}