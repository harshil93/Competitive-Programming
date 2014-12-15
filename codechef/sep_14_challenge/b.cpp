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

int v[100001];
int main(){
	int n,m;
	std::ios_base::sync_with_stdio(false);
	cin>>n>>m;

	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	int ind = 0;
	while(m--){
		char c; int o;
		cin>>c>>o;

		if(c == 'C'){
			ind += o;
			if(ind>=n)
				ind = ind % n;
		}else if(c == 'A'){
			ind -= o;
			if(ind < 0 ){
				ind = (ind + n)%n;
			}
		}else{
			cout<<v[(ind + o - 1)%n]<<endl;
		}

		
	}
}