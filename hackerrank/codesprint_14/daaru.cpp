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

int nSum(int n){
	return (n*(n+1))/2;
}
int getRow(int l, int n){
	for (int i = 1; i <= l+1; ++i)
	{
		if(nSum(i)> n ){
			return i-1;
		}
	}
}

int getRowIndex(int r, int n){
	return n - nSum(r-1);
}

int getAt(int r, int n){
	if(r==0) return -1;
	if(r>n) return -1;
	if(n<=0) return -1; 
	return nSum(r-1) + n;
}

vector<int> parents(int l, int n){
	std::vector<int> ans;
	int row = getRow(l,n);
	if(row == l){
		
		int ind = getRowIndex(l,n);
		int pl = getAt(row-1,ind-1);
		int pr = getAt(row-1,ind);

		if(pl!=-1) 
			ans.push_back(pl);
		if(pr!=-1)
			ans.push_back(pr);
	}else{
		ans.push_back(n);
		int ind = getRowIndex(l,n);
		int pl = getAt(row-1,ind-1);
		int pr = getAt(row-1,ind);

		if(pl!=-1) 
			ans.push_back(pl);
		if(pr!=-1)
			ans.push_back(pr);
	}
}


int main(){
	
}