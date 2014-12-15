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

int maxProfit(vector<int> &prices,int num) {
       vector<bool> segs(prices.size());
	int maxprofit = 0;
	for (int transact = 0; transact < num; ++transact) {
		int i0 = 0, c = 0, cmax = 0;
		vector<int> s;
		for (int i = 0; i < (int)prices.size() - 1; ++i) {
			if (i > 0 && segs[i] != segs[i - 1]) {
				i0 = i; c = 0;
			}
			c = c + prices[i + 1] - prices[i];
			if ((!segs[i] && c <= 0) || (segs[i] && c >= 0)) {
				i0 = i + 1; c = 0;
			}
			else if (cmax < abs(c)) {
				cmax = abs(c); s = { i0, i };
			}
		}
		if (cmax == 0) break;
		for (int i = s[0]; i <= s[1]; ++i) segs[i] = !segs[i];
		maxprofit += cmax;
	}
	return maxprofit;
    }

int main(){
	
}