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
#define REP(i,n) for( int64_t i =0 ; i < n ; i++ )

int maxSubArraySum(int a[], int n)
{
   int max_so_far = 0, max_ending_here = 0;
   for(int i = 0; i < n; i++)
   {
     max_ending_here = max_ending_here + a[i];
     if(max_ending_here < 0)
         max_ending_here = 0;
     else if (max_so_far < max_ending_here)
         max_so_far = max_ending_here;
   }
   
}

int main(){

	std::ios_base::sync_with_stdio(false);
	int64_t T;
	cin>>T;
	int64_t a[100001],l[100001],r[100001];
	while(T--){
		int64_t n,k;
		cin>>n>>k;
		REP(i,n){
			cin>>a[i];
		}		
		int64_t max_so_far = a[0];
   		int64_t curr_max = a[0];
 		l[0] = max_so_far;
	   	for (int i = 1; i < n; i++)
	   	{
	        curr_max = max(a[i], curr_max+a[i]);
	        max_so_far = max(max_so_far, curr_max);
	        l[i] = max_so_far;
	   	}
	   	max_so_far = a[n-1]; curr_max = a[n-1];
	   	r[n-1] = max_so_far;
		for (int i = n-2; i >=0; i--)
	   	{
	        curr_max = max(a[i], curr_max+a[i]);
	        max_so_far = max(max_so_far, curr_max);
	        r[i] = max_so_far;
	   	}

		int64_t ans = -10000000000000000;
		/*REP(i,n) cout<<a[i]<<"\t";
		cout<<endl;
		REP(i,n) cout<<l[i]<<"\t";
		cout<<endl;
		REP(i,n) cout<<r[i]<<"\t";
		cout<<endl;	*/	
		for(int i = 0; i+k+1 < n; i++){
			ans = max( ans ,  l[i] + r[i+k+1]);
		}
		cout<<ans<<endl;		
	}
	return 0;
}
