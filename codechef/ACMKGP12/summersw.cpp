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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define ff first
#define ss second
#define REP(i,n) for(int i=0 ; i<n ; i++)
int mat[2502][2502];
int main(){
	int t;
	cin>>t;
	
	while(t--){

		/*int **mat = new int*[2502];
		for (int i = 0; i < 2502; ++i)
		{
			mat[i] = new int[2502];
		}*/
		int n;
		std::vector<pair<int,int> > v;
		cin>>n;
		v.resize(n+2);

		for (int i = 1; i <= n; ++i)
		{
			scanf("%d",&v[i].ff,&v[i].ss);
			// cin>>v[i].ff>>v[i].ss;
		}
		pair<int,int> src, end;
		scanf("%d %d",&v[0].ff,&v[0].ss);
		scanf("%d %d",&v[n+1].ff,&v[n+1].ss);
		// cin>>v[0].ff>>v[0].ss;
		// cin>>v[n+1].ff>>v[n+1].ss;
		
		REP(i,n+2)
			for(int j=i+1;j<n+2;j++){
				mat[i][j] = (v[i].ff - v[j].ff)*(v[i].ff - v[j].ff) + (v[i].ss - v[j].ss)*(v[i].ss - v[j].ss);
				mat[j][i] = (v[i].ff - v[j].ff)*(v[i].ff - v[j].ff) + (v[i].ss - v[j].ss)*(v[i].ss - v[j].ss);
			}

		priority_queue< pair<int,int> , vector<pair<int,int> > , greater< pair<int,int> > > pq;
		vector<int> dist(n+2, INT_MAX), dad(n+2, -1);


		pq.push(make_pair(0,0));
		dist[0] = 0;
		while(!pq.empty()){
			pair<int,int> ele = pq.top();			
			if(ele.ss == n+1){
				break;
			}

			pq.pop();
			
			for(int i=0;i<n+2;i++){
				if(dist[ele.ss] + mat[ele.ss][i] < dist[i]){
					dist[i] = dist[ele.ss] + mat[ele.ss][i];
					dad[i] = ele.ss;
					pq.push(make_pair(dist[i],i));
				}
				
			}

		}

		

	cout<<dist[n+1]<<endl;
	}
	return 0;
}