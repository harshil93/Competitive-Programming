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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define REP(i,n) for(int i=0; i<n;i++)

const int INF = 2000000000;
typedef pair<int,int> PII;

int main(){
	int n,m;
	cin>>n>>m;
	std::vector<int> price(n);
	REP(i,n) cin>>price[i];
	vector<vector<PII> > edges(n*101);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			edges[i*101+j].push_back(make_pair(1,i*101+j+1));
		}
	}
	for (int j = 0; j < m; j++){
      int to,from, d;
      scanf ("%d%d%d", &from,&to, &d);
      
      for (int i = 0; d+i < 101; ++i)
      {
      	edges[from*101 + d+i].push_back(make_pair(0,to*101 + i));
      }
    }

 int q;
 cin>>q;

 while(q--){
 	int c,s,t;
 	cin>>c>>s>>t;
 	s= s*101;
 	t= t*101;
 	priority_queue<PII, vector<PII>, greater<PII> > Q;
 	  vector<int> dist(n*101, INF), dad(n*101, -1);
 	  Q.push (make_pair (0, s));
 	  dist[s] = 0;
 	  while (!Q.empty()){
 	    PII p = Q.top();
 	    if (p.second == t) break;
 	    Q.pop();
 	    
 	    int here = p.second;
 	    for (vector<PII>::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
 	      if(it->second - (here/101)*101 <= c)
	 	      if (dist[here] + it->first < dist[it->second]){
	 	        dist[it->second] = dist[here] + it->first;
	 	        dad[it->second] = here;
	 	        Q.push (make_pair (dist[it->second], it->second));
	 	      }
 	    }
 	  }
 	  if(dist[t]<INF)
 	  	printf ("%d\n", dist[t]);

 }
    



}