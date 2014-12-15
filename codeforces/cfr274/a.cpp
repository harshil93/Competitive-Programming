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
#include <stack>
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
	std::ios_base::sync_with_stdio(false);
	int a, b,c;
	cin>>a>>b>>c;

	int arr[10];
	arr[0] = a+b+c;
	arr[1] = (a+b)*c;
	arr[2] = a*(b+c);
	arr[3] = a*b*c;
	arr[4] = a*b + c;
	arr[5] = a+ b*c;
	int ans = -1;
	for (int i = 0; i < 6; ++i)
	{
		ans = max(ans,arr[i]);
	}
	cout<<ans<<endl;
}