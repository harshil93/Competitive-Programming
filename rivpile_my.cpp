#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

struct node
{
	int pos_index;
	int disc_index;
	int weight;
};

struct pt
{
	int x,y;
};

struct disc
{
	int r,c;
};

bool operator<(const struct disc &val1, const struct disc &val2){
	return val1.r<val2.r;
};

bool operator<(const node &in1, const node &in2)
{
	return (in1.weight > in2.weight);
}
int main(){
	int T;
	cin>>T;

	while(T--){
		int N,M,W;
		cin>>N>>M>>W;
		struct pt pt_ini; pt_ini.x=0;pt_ini.y=0;
		std::vector< struct pt > coords(N,pt_ini);
		for (int i = 0; i < N; ++i)
		{
			int x,y;
			cin>>x>>y;
			coords[i].x = x;
			coords[i].y = y;
		}
		struct disc disc_ini; disc_ini.r=0;disc_ini.c=0;
		std::vector< struct disc > discs(M,disc_ini);
		for (int i = 0; i < M; ++i)
		{
			int r,c;
			cin>>r>>c;
			discs[i].r = r;
			discs[i].c = c;
		}
		
		sort(discs.begin(),discs.end());

		std::vector< struct disc > discs_using;
		for (int i = discs.size() - 1; i >=0; --i)
		{
			bool flag = true;
			for (int j = i+1; j < discs.size(); ++j)
			{
				if(discs[j].c<=discs[i].c){
					flag = false;
					break;
				}
			}
			if(flag){
				discs_using.push_back(discs[i]);
			}
		}
		sort(discs_using.begin(),discs_using.end());
		std::vector< std::vector<long double> > distance(N,std::vector<long double>(N,0));

		for (int i = 0; i < N; ++i)
		{
			for (int j = i+1; j < N; ++j)
			{
				long double dx = coords[i].x - coords[j].x;
				long double dy = coords[i].y - coords[j].y;
				distance[j][i]=distance[i][j] = sqrtl(dx*dx + dy*dy);
			}
		}

		priority_queue <struct node> pq;
		int discCountForNode = new int[N];
		for (int i = 0; i < N; ++i)
		{
			discCountForNode[i]=discs_using-1;
		};
		for (int i = 0; i < N; ++i)
		{
			for (int j = discs_using.size()-1; j >=0; --j)
			{
		
				if(coords[i].y <= discs_using[j].r){
					struct node newNode;
					newNode.pos_index = i;
					newNode.disc_index = j;
					newNode.weight = discs_using[j].c;
					pq.push(newNode);
					discs_using--;
					// cout<<"node inserted"<<i<<" "<< j << " "<< newNode.weight<<endl;
				}else{
					break;
				}
			}
		}
		int ans = -1;
		while(!pq.empty()){
			struct node cur_node = pq.top();
			pq.pop();

			if(coords[cur_node.pos_index].y + discs[cur_node.disc_index].r <= W){
				ans = cur_node.weight;
			}


			for (int i = 0; i < N; ++i)
			{
				if(discCountForNode[i]>=0)
			}
		}

		


	}
	return 0;
}