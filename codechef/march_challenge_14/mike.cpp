#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int disjoint[20][20];

int main(){
	int n,m; scanf("%d%d",&n,&m);
	std::vector<int> sets[20];
	for (int i = 0; i < m; ++i)
	{
		int k; cin>>k;
		for (int j = 0; j < k; ++j)
		{
			int temp; scanf("%d",&temp);
			sets[i].push_back(temp);
		}
	}
	
	/*for (int i = 0; i < m; ++i)
	{
		
		for (int j = 0; j < sets[i].size(); ++j)
		{
			cout<<sets[i][j]<<" ";
		}
		cout<<endl;
	}*/

	for (int i = 0; i < m; ++i)
	{
		for (int j = i+1; j < m; ++j)
		{
			int x=0,y=0;
			int bad=0;
			while(x<sets[i].size() && y<sets[j].size()){
				if(sets[i][x] == sets[j][y]){
					bad=1;
					break;
				}else if(sets[i][x] > sets[j][y]){
					y++;
				}else{
					x++;
				}
			}
			if(bad==0){
				disjoint[i][j] = 1;
				disjoint[j][i] =1;
			}
		}
	}


	/*for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cout<<disjoint[i][j]<<" ";
		}
		cout<<endl;
	}*/
	int finans=0;
	for (int i = (int) pow(2,m) - 1; i >=1; --i)
	{
		// cout<<"-----"<<endl;
		// cout<<i<<endl;
		std::vector<int> v;
		int t=0;
		while(t<m){
			if(i & 1<<t){
				v.push_back(t);
			}
			t++;
		}

		int ans = 1;

		for (int j = 0; j < v.size(); ++j)
		{
			for (int k = j+1; k < v.size(); ++k)
			{
				
				if(disjoint[v[j]][v[k]] ==0 ){
					ans=0;break;
				}
			}
			if(ans==0) break;
		}

		if(ans==1 && v.size() > finans) 
			finans = v.size();
	}

	printf("%d\n", finans);


}