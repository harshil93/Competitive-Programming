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


int numRep(vector<int> &arr, int a, int d){
	int cur = a;
	int count = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		if(cur != arr[i]){
			count++;
		}
		cur = cur + d;
	}
	return count;
}



int main(){
	std::ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	std::vector<int> arr(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	int z = min(12,n);
	int f_a = INT_MAX;
	int f_d = INT_MAX;
	for (int i = 0; i < z; ++i)
	{
		for (int j = i+1; j < z; ++j)
		{
			int d = (arr[j] - arr[i])/(j-i);
			int a = arr[i] - i*d;
			int changes = numRep(arr,a,d);
			if(changes <= k ){
				if(a<f_a){
					f_a = a;
					f_d = d;
				}else if(a == f_a){
					f_d = min(f_d,d);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		cout<<f_a+i*f_d<<" ";
	}
	cout<<endl;
}