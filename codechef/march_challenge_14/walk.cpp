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


int main(){
	int t;
	cin>>t;

	while(t--){
		int n; cin>>n;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}

		int vel = v[0];
		int temp = vel - 1;

		for (int i = 1; i < n; ++i)
		{
			if(v[i]>temp){
				vel = v[i] + i;
				temp = vel-i;
			}else{
				temp--;
			}
		}

		cout<<vel<<endl;
	}
	return 0;
}