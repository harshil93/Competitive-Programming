#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
int off(int n){
	return n+100;
}
int map[200][200];

void preprocess(int n){
	std::vector< pair<int,int> > v[2];
	int cur_v = 0;
	pair<int, int> ini;
	ini = make_pair(off(0),off(0));
	map[off(0)][off(0)] = n;
	v[cur_v].push_back(ini);
	while(1){
		
		bool isZero = true;
		// PR(v[cur_v].size())
		for (int i = 0; i < v[cur_v].size(); ++i)
		{
			int ants = map[(v[cur_v][i]).first][(v[cur_v][i]).second];
			int ants_4 = ants/4;
			int rem_ants = ants%4;
			
			if (ants_4>0)
			{
				isZero = false;
			}
			if (ants_4==0)
			{
				continue;
			}
			map[v[cur_v][i].first - 1][v[cur_v][i].second]+=ants_4;
			map[v[cur_v][i].first + 1][v[cur_v][i].second]+=ants_4;
			map[v[cur_v][i].first ][v[cur_v][i].second- 1]+=ants_4;
			map[v[cur_v][i].first ][v[cur_v][i].second+ 1]+=ants_4;

			map[v[cur_v][i].first ][v[cur_v][i].second]=rem_ants;

			v[(cur_v+1)%2].push_back(make_pair(v[cur_v][i].first - 1,v[cur_v][i].second));
			v[(cur_v+1)%2].push_back(make_pair(v[cur_v][i].first + 1,v[cur_v][i].second));
			v[(cur_v+1)%2].push_back(make_pair(v[cur_v][i].first ,v[cur_v][i].second- 1));
			v[(cur_v+1)%2].push_back(make_pair(v[cur_v][i].first ,v[cur_v][i].second+ 1));
		}
		cur_v = (cur_v +1)%2;
		v[(cur_v+1)%2].clear();
		if (isZero)
		{
			break;
		}
	}

}

int main(){
	int n, t;
	cin>>n>>t;
	preprocess(n);
	/*for (int i = 80; i < 111; ++i)
		{
			for (int j = 80; j < 111; ++j)
			{
				cout<<map[i][j]<<"\t";
			}
			cout<<endl;
		}*/

	while(t--){
		int x,y;
		cin>>x>>y;
		if (x>=-99 && y>=-99 && x<=99 && y<=99)
		{
			cout<<map[off(x)][off(y)]<<endl;
		}else{
			cout<<0<<endl;
		}
	}
			return 0;
}

