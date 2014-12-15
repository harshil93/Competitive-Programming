#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include <string>
using namespace std;
// limit of unsigned int
#define PR(x) cout << #x " = " << x << "\n";
#define INFINITY 100000000

struct nodeDistance
{
    int node;
    unsigned int distance;
    int wTime;
};

struct nodet
{
    int node;
    int distance;
    int wTime;
};

// This is the basis on which the elements of a priority queue are sorted and 
// kept in the queue, here the criteria is that the node with smaller distance should
// come above the one with larger distance

class CompareDist
{
    public:
        bool operator()(nodeDistance& n1, nodeDistance& n2)
        {
           if (n1.distance  > n2.distance ) 
                return true;
           else
                return false;
        }
};

// This implementation take 
// s --> source node (represented by an index) 
// size --> the total number of nodes in the graph
// graph --> pointer to a 2D array graph[size][size] that contains information about all the edges in the graph
// Instead of a 2D array you can also use an adjacency list if the graph is sparse
void dijkstra(int s, int d, int size, std::vector< std::vector<int> > &graph, std::vector<nodet> &v) 
{    
    int mini;
    bool *visited = new bool [size];
    unsigned int *dist = new unsigned int [size];

    // initialize the dist of each node as infinity and visited status as false
    for (int i = 0; i < size;   i++) 
    {
        dist[i] = INFINITY;
        visited[i] = false;
    }

    // the distance of the source to itself is 0
    dist[s] = 0;

    // instantiate a priority queue with the structure and comparison criteria
    // as defined above
 
    priority_queue< nodeDistance, vector< nodeDistance >, CompareDist> pq;

    // Create the first node as the source and put it into the queue
    nodeDistance first = {s,0,v[s].wTime};
    pq.push(first);
    
    // While queue is not empty, pick the topmost node
    // using it's neighbors update the distance of each node that can be reached
    // and insert that node in the priority queue

    /*for (int i = 0; i < size; ++i)
    {
    	for (int j = 0; j < size; ++j)
    	{
    		cout<<graph[i][j]<<" ";
    	} cout<<endl;
    }
    cout<<endl;*/
    while(!pq.empty())
    {

        nodeDistance temp = pq.top();
        pq.pop();
        int node= temp.node;
        // PR(node)
        for(int i=0;i < size;i++  )
        {
            if(graph[node][i]!=0)
            {
                // Update the distance if it is smaller than the current distance
                if(dist[i] > (dist[node] + graph[node][i]  ))
                    dist[i] = dist[node] + graph[node][i] ;

                // If not visited put it into the queue
                if(!visited[i])
                {
                    nodeDistance newNode;                   
                    newNode.node=i;
                    newNode.distance=dist[i];
                    // newNode.wTime = v[i].wTime;
                    pq.push(newNode);
                    visited[i]=true;
                }
            }
        }

    }

   
        cout <<dist[d] << endl;
    
   
}



int main(){
    int T;


    cin>>T;
    
    while(T--){
        std::vector< nodet > v;
        std::vector< std::vector<int> > graph;
        v.resize(15);
        graph.resize(15);
        for (int i = 0; i < 15; ++i)
        {
            graph[i].resize(15);
        }

        for (int i = 0; i < 15; ++i)
        {
            int temp;
            cin>>temp;
            // cout<<temp<<endl;
           v[i].wTime = temp;
        }

        for (int i = 0; i < 26; ++i)
        {
            string s_,t_;
            int dist;
            cin>>s_>>t_;
            scanf("%d", &dist);
            int s,t;
            s = s_[0] -'A';
            t = t_[0] -'A';
            // cout<<s<<" "<<t<<endl;
            graph[s][t] = dist;
            graph[t][s] = dist;
        }
        for (int i = 0; i < 15; ++i)
        {
        	for (int j = 0; j < 15; ++j)
        	{
        		if(graph[i][j]!=0){
        			graph[i][j]+=v[i].wTime;
        		}
        	}
        }
        string s_,d_;
        cin>>s_>>d_;
        int s,d;
        s = s_[0] -'A';
        d = d_[0] -'A';
        
        dijkstra(s,d,15,graph,v);
    }
    return 0;
}