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
#include <cassert>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<long long> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )


int main(){
	long long n,l,x,y;

	cin>>n>>l>>x>>y;

	std::vector<long long> a(n);
	
	for (long long i = 0; i < n; ++i)
	{
		cin>>a[i];
	}

	bool xPresent=false, yPresent = false, xyPresent = false,ymxPresent = false;

	long long ans = 2;
	long long p1;

	for (long long i = 0; i < n; ++i)
	{

		long long px = binary_search(a.begin(),a.end(),a[i]-x);
		long long py = binary_search(a.begin(),a.end(),a[i]-y);
		long long pxy = binary_search(a.begin(),a.end(),a[i]-(x+y));
		long long ymx = binary_search(a.begin(),a.end(),a[i]-(y-x));

		if(px ){
			ans = 1;
			xPresent = true;
			p1 = y;
		}

		if(py ){
			yPresent = true;
			ans = 1;
			p1 =x;
		}

		if(pxy ){
			xyPresent = true;
			ans = 1;
			p1 = a[i] - x;
		}

		if(ymx){
			if(a[i]-y >0 ){
				ans = 1;
				ymxPresent = true;
				p1 = a[i] - y;
			}else if(a[i]+x<l){
				ans = 1;
				ymxPresent = true;
				p1 = a[i] + x;
			}
			
		}

		if(xPresent && yPresent){
			cout<<0<<endl;
			return 0;
		}
	}

	if(ans == 1){
		cout<<1<<endl;
		// PR(p1)
		assert(p1<l && p1>0);
		cout<<p1<<endl;
		return 0;
	}else{
		cout<<2<<endl;
		cout<<x<<" "<<y<<endl;
		return 0;
	}



}