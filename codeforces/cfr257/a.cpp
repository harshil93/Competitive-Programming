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
#include <cassert>
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
	int n, m ; 
	cin>>n>>m;

	std::vector<int> v(n);
	int ans;
	int maxi = -1;
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
		maxi = max(maxi,v[i]);
	}
	int temp = maxi/m + 1;
	int j=0;
	while(temp--){
		if(j%2 == 0){
			for (int i = 0; i < n; ++i)
			{
				if(v[i]>0){
					v[i] = v[i] - m;
					ans = i;
				}
			}
		}else{
			for(int i = n-1; i >=0; i--){
				if(v[i]>0){
					v[i] = v[i] - m ;
					ans = i;
				}
			}
		}
	}

	cout<<ans + 1<<endl;




}