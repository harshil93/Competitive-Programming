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
	int n;
	cin>>n;
	std::vector<int> v(n,0);
	REP(i,n) cin>>v[i];
	sort(v.begin(),v.end());
	bool done[n];
	REP(i,n) done[i] = false;
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<"\t";
	}
	cout<<endl;
	int m=-1;
  	std::vector<int>::iterator low,up;
  	int ans=0;
	
	cout<<m<<endl;
}