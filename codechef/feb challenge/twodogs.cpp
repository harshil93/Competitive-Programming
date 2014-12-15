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

int bsearch(vector<pair<int,int> > &v,int val){
	int first = 0;
	int last = v.size() - 1;
	int middle = (first+last)/2;
 
	while( first <= last )
	{
	  if ( v[middle].first < val )
	     first = middle + 1;    
	  else if ( v[middle].first == val ) 
	  {
	     return middle;
	  }
	  else
	     last = middle - 1;
 
	  middle = (first + last)/2;
	}
	if ( first > last )
		return v.size(); 
}

int main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int> > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
	}

	for (int i = 0; i <= n/2; ++i)
	{
		v[i].second = i+1;
	}

	for (int i = n/2; i < n; ++i)
	{
		v[i].second = n - i ;
	}

	sort(v.begin(),v.end());
	int ans = 1000000000;
	for(int i=0,j=n-1;i<j;)
    {
        int x = v[i].first+v[j].first;
        if(x<k)         i++;
        else if(x>k)    j--;
        else
        {
            if(v[i].first!=v[j].first)    
            	ans = min(ans,max(v[i].second,v[j].second));
            if((v[j-1].first!=v[j].first) && (v[i].first==v[i+1].first)) 
            	i++;
            else j--;
        }
    }
	if(ans!=1000000000)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
	return 0;
}