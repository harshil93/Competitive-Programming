// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <cstdio>
#include <limits.h>
#include <string.h>
#include <queue>
#include <map>
#define PR(x) cout << #x " = " << x << "\n";
#define vvi vector< vector<int> >
#define vi vector<int>
using namespace std;
 
// Number of vertices in given graph
int V; 
/* Returns true if there is a path from source 's' to sink 't' in
  residual graph. Also fills parent[] to store the path */
bool bfs(vvi &rGraph, int s, int t, int parent[])
{
    // Create a visited array and mark all vertices as not visited
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    // Standard BFS Loop
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<rGraph[u].size(); v++)
        {
            if (visited[rGraph[u][v]]==false)
            {
                q.push(rGraph[u][v]);
                parent[rGraph[u][v]] = u;
                visited[rGraph[u][v]] = true;
            }
        }
    }
 
    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[t] == true);
}
 
// Returns tne maximum flow from s to t in the given graph
int fordFulkerson(vvi &graph, int s, int t)
{
    int u, v;
 
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    vvi rGraph = graph // Residual graph where rGraph[i][j] indicates 
                     // residual capacity of edge from i to j (if there
                     // is an edge. If rGraph[i][j] is 0, then there is not)  
 
    int parent[V];  // This array is filled by BFS and to store path
 
    int max_flow = 0;  // There is no flow initially
 
    // Augment the flow while tere is path from source to sink
    while (bfs(rGraph, s, t, parent))
    {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
 
        // update residual capacities of the edges and reverse edges
        // along the path
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        // Add path flow to overall flow
        max_flow += path_flow;
    }
 
    // Return the overall flow
    return max_flow;
}
struct p
{
	int x, y;
};
// Driver program to test above functions
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int cnt = 1;
		int n;
		cin>>n;
		std::map<int, int> m;
		V=2*(n+1)+1;
		std::vector<p> coords;
		for (int i = 0; i < n; ++i)
		{
			int x,y; 
			scanf("%d %d",&x,&y);
			p t; t.x = x; t.y = y;
			coords.push_back(t);
		}
		
		for (int i = 0; i < coords.size(); ++i)
		{
			if(!m[coords[i].x]) m[coords[i].x] = cnt++;
		}
		int xcnt = cnt - 1;
		for (int i = 0; i < coords.size(); ++i)
		{
			if(!m[xcnt+1+coords[i].y]) m[xcnt+1+coords[i].y] = cnt++;
		}

		int ycnt = cnt -xcnt-1;
		vvi graph;
        graph.resize(xcnt+ycnt+2);
        std::vector<int> v;
        for (int i = 0; i < xcnt; ++i)
        {
            v.push_back(i+1);
        }
        graph[0] = v;
        v.clear();

        for (int i = 0; i < coords.size(); ++i)
        {
            graph[m[coords[i].x]].push_back(m[xcnt+1+coords[i].y]);
        }
        for (int i = xcnt+1; i < xcnt+ycnt+1; ++i)
        {
            graph[i].push_back(xcnt+ycnt+1);
        }
    	
        /*for (int i = 0; i < graph.size(); ++i)
        {
            cout<<i<<" --> ";
            for (int j = 0; j < graph[i].size(); ++j)
            {
                cout<<graph[i][j]<<" ";
            }
            cout<<endl;
        }*/
	}
   
    
 
    return 0;
}