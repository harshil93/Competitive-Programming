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

int64_t dig(int64_t n){
	int cnt=0;
	while(n!=0){
		cnt++;
		n=n/10;
	}
	return cnt;
}

int64_t pow10(int64_t k){
	if(k==0) return 1;
	
	int64_t ret = pow10(k/2);
	if(k%2==0){
		return ret*ret;
	}else{
		return ret*ret*10;
	}
}
int main(){
	int64_t w,m,k;cin>>w>>m>>k;
	w = w/k;
	int64_t ans=0;
	while(w!=0){
		
		int64_t d = dig(m);

		int64_t z = pow10(d);
		int64_t num = z-m;


		if(w<d*num){
			ans += (w/d);
			w = w%d;
			break;
		}else{
			ans+= num;
			w = w - num*d;
			m = z;
		}
	}

	cout<<ans<<endl;
	return 0;

}