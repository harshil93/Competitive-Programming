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
#define INF 100000

int main(){
	int T;
	cin>>T;

	while(T--){
		
		int n,m;
		cin>>n>>m;
		int order[401];
		int next[401];
		int hash[401];
		for (int i = 0; i < 401; ++i)
		{
			next[i] = INF;
			hash[i] = -1;
		}
		for (int i = 0; i < m; ++i)
		{
			int _t; cin>>_t;
			order[i] = _t;
			if(hash[_t] == -1)
			{
				hash[_t] = i;
			}
			else
			{
				next[hash[_t]] = i;
				hash[_t] = i;
			}
		}
		for(int i = 0 ; i < 401 ; i++) hash[i] = -1;

		int tables[201];

		for(int i = 0 ; i < 201 ; i++) tables[i] = -1;
		int ans=0;

		/*for (int i = 0; i < m; ++i)
		{
			cout<<order[i]<<"\t";
		}
		cout<<endl;

		for (int i = 0; i < m; ++i)
		{
			cout<<next[i]<<"\t";
		}
		cout<<endl;*/

		for (int i = 0; i < m; ++i)
		{
			if(hash[order[i]] != -1){
				tables[hash[order[i]]] = i;
				//already there replace the elem
			}else{
				//its not there find a replacement
				
				bool freeTable = false;
				for (int j = 0; j < n; ++j)
				{
					if(tables[j] == -1){
						//allocate
						tables[j] = i;
						hash[order[i]] = j;
						freeTable = true;
						break;
					}
				}

				if(freeTable){
					
				}else{
					int maxi = -1;
					int indToReplace = -1;

					for (int j = 0; j < n; ++j)
					{
						if(maxi < next[tables[j]]){
							maxi = next[tables[j]];
							indToReplace = j;
						}
					}

					hash[order[tables[indToReplace]]] = -1;
					tables[indToReplace] = i;
					hash[order[tables[indToReplace]]] = indToReplace;
				}
				ans++;
			}
			
		}

		cout<<ans<<endl;

	}
}