#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
inline int fast_int()
{
int n=0;
int ch=getchar();
while(ch<48)ch=getchar();
while(ch >47)
n=(n<<3)+(n<<1)+ch-'0',ch=getchar();
return n;
}

typedef struct node
{
	int l;int r;std::vector<int> to;
} node;
int main(){
	int n;
	std::vector<node*> nodes;
	cin>>n;

	while(n--){
		int c;
		cin>>c;
		if(c==1){
			int l;int r; cin>>l>>r;
			node *newNode = new node();
			newNode->l = l; newNode->r = r;
			for (int i = 0; i < nodes.size(); ++i)
			{	
				int size = nodes.size();
				if( (nodes[i]->l < l && nodes[i]->r > l) || (nodes[i]->l < r && nodes[i]->r >r) ){
					nodes[i]->to.push_back(size);
					newNode->to.push_back(i);
				}else if(nodes[i]->l >= l && nodes[i]->r <= r){
					nodes[i]->to.push_back(size);
				}

			}
			nodes.push_back(newNode);
		}else{
			int explored[101]={0};
			for (int i = 0; i < 101; ++i)
			{
				explored[i]= 0;
			}
			queue<int> q;
			int from,to;
			cin>>from>>to;
			from = from -1;
			to = to -1;
			while(!q.empty()) q.pop();
			q.push(from);
			explored[from]=1;
			bool ans = false;
			while(!q.empty()){
				int elem = q.front();q.pop();
				// PR(elem)
				if(elem == to){
					cout<<"YES"<<endl;
					ans = true;
					break;
				}
				for (int i = 0; i < nodes[elem]->to.size(); ++i)
				{	
					if(explored[nodes[elem]->to[i]] == 0){
						// PR(nodes[elem]->to[i])
						q.push(nodes[elem]->to[i]);
						explored[nodes[elem]->to[i]] = 1;
					}
						
				}
			}
			if(!ans){
				cout<<"NO"<<endl;
			}


		}
	}
}