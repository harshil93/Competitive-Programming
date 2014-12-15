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
	string str;
	cin>>str;
	int ma = 0;
	int cur = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if(str[i] == 'a'){
			cur++;
			ma = max(ma,cur);
		}else{
			cur = 0;
		}
	}

	for (int i = 0; i < ma + 1; ++i)
	{
		cout<<'a';
	}
	cout<<endl;
}