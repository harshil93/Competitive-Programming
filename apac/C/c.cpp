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
#include <cstring>
using namespace std;
//#define PR(x) cout << #x " = " << x << "\n";
#define PR(x) ;
typedef vector<int> vi; 
typedef vector< vi > vvi; 
typedef pair<int,int> ii; 
typedef pair<int,int> PII;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define REP(i,n) for( int i =0 ; i < n ; i++ )
#define ll long long
#define FF first
#define SS second
const int INF = 2000000000;
int main(){
	int T; cin>>T;
	for(int _t = 1; _t <= T; _t++){
		cout<<"Case #"<<_t<<":"<<endl;
		int N;
		cin>>N;
		vector<vector<PII > > edges(1000*N + 1);
		PR(N);
		vi W;
		for (int i = 0; i < N; ++i)
		{
			int sn,_w;
			cin>>sn>>_w;
			W.pb(_w);
			for (int j = 0; j < sn-1; ++j)
			{
				int ti; cin>>ti;
				edges[1000*i+j].pb(make_pair(ti,1000*i+j+1));
				edges[1000*i+j+1].pb(make_pair(ti,1000*i+j));
			}

		}
			int m;
			cin>>m;
			PR(m);
			for (int j = 0; j < m; ++j)
			{
				int m1,s1,m2,s2,t;
				cin>>m1>>s1>>m2>>s2>>t;
				PR(m1) PR(s1) PR(m2) PR(s2) PR(t)
				edges[(m1-1)*1000 + s1-1].pb(make_pair(t+W[s2-1],(m2-1)*1000 + s2-1));
				edges[(m2-1)*1000 + s2-1].pb(make_pair(t+W[s1-1],(m1-1)*1000 + s1-1));
			}

		int numQ;cin>>numQ;
		while(numQ--){
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			int s = 1000*(x1-1)+y1-1;
			int t = 1000*(x2-1)+y2-1;
			priority_queue<PII, vector<PII>, greater<PII> > Q;
			  vector<int> dist(1001*N + 1, INF), dad(1001*N + 1, -1);
			  Q.push (make_pair (0, s));
			  dist[s] = 0;
			  PR(t)
			  while (!Q.empty()){
			    PII p = Q.top();
			    if (p.second == t) break;
			    Q.pop();
			    
			    int here = p.second;
			    for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
			      if (dist[here] + it->first < dist[it->second]){
			        dist[it->second] = dist[here] + it->first;
			        dad[it->second] = here;
			        Q.push (make_pair (dist[it->second], it->second));
			      }
			    }
			  }
			  PR(t)
			  cout<<dist[t]<<endl;
			  if (dist[t] < INF)
			      for(int i=t;i!=-1;i=dad[i])
			        printf ("%d%c", i, (i==s?'\n':' '));
		}

		
		
	}
}