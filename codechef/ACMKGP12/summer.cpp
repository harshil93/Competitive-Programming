// Implementation of Dijkstra's algorithm using adjacency lists
// and priority queue for efficiency.
//
// Running time: O(|E| log |V|)

#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;
const int INF = 2000000000;
typedef pair<int,int> PII;

int main(){
  
  int N, s, t,T;
  // scanf("%d",&T);
  cin>>T;
  while(T--)
  {
    // cout<<"T = "<<T<<endl;
    scanf ("%d", &N);
    // cout<<"N = "<<N<<endl;
    vector<vector<PII> > edges(N+2);
    std::vector<PII> v(N+2);
    for (int i = 0; i < N; ++i)
    {
      // scanf("%d %d ",&v[i].first,&v[i].second);
      cin>>v[i].first>>v[i].second;
    }

    // scanf("%d %d " ,&v[N].first,&v[N].second);
    // scanf("%d %d " ,&v[N+1].first,&v[N+1].second);

    cin>>v[N].first>>v[N].second;
    cin>>v[N+1].first>>v[N+1].second;

    s = N; t = N+1;
    for (int i = 0; i < N+2; i++){
      
      for (int j = i+1; j < N+2; j++){
        int vertex, dist;
        dist = (v[i].first - v[j].first)*(v[i].first - v[j].first) + (v[i].second - v[j].second)*(v[i].second - v[j].second);
        edges[i].push_back (make_pair (dist, j)); // note order of arguments here
        edges[j].push_back (make_pair(dist,i));
      }
    }
    
    // use priority queue in which top element has the "smallest" priority
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    vector<int> dist(N+2, INF), dad(N+2, -1);
    Q.push (make_pair (0, s));
    dist[s] = 0;
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
    
    printf ("%d\n", dist[t]);
  }
    
  return 0;
}