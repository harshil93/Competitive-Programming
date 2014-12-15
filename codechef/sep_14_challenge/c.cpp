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
#include <functional>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )

#define MOD 1000000007
long long ipow(long long base, long long exp)
{
    long long result = 1;
    while (exp)
    {
        if (exp & 1){
            result = (result* base)%MOD;
        }
        exp >>= 1;
        base = (base* base)%MOD;
    }
 
    return result;
}

long long solve(long long n,long long r){

	if(r ==0 || n==r){
		return 1;
	}

	if(r > n -r){
		r = n-r;
	}

	long long num = n, den = r;

	for (int i = 1; i < r; ++i)
	{
		num = (num*(n-i))%MOD;
		den = (den*(r-i))%MOD;
	}

	return (num * ipow(den,MOD-2))%MOD;
}

int main(){
	int n,r;
	cin>>n;
	if(n%2){
		n--;
		n = n /2;
		n = n - 6;
	}else{
		n = n/2;
		n = n -7;
	}
	r = 7;
	if(n<0)
	{
		cout<<0<<endl;
		return 0;
	}
	cout<< solve(n+r-1,r-1)<<endl;
	return 0;

}