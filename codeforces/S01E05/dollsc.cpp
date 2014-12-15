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
bool cmp(const pair<int, int> a, const pair<int, int > b)
{
	return a.first<b.first && a.second<b.second;
}
int main(int argc, char const *argv[])
{
	int t,m,w,h; cin>>t;
	while(t--)
	{
		cin>>m;
		std::vector<pair<int, int> > in;
		for (int i = 0; i < m; ++i)
		{
			scanf("%d",&w);
			scanf("%d",&h);
			in.push_back(make_pair(w,h));
		}
		sort(in.begin(), in.end(),cmp);

		for (int i = 0; i < m; ++i)
		{
				cout<<in[i].first<<"\t"<<in[i].second<<endl;
		}

		cout<<"------------\n";


		std::vector<pair<int, int> > ::iterator it;
		int count=0;
		pair<int, int> temp;
		std::vector<pair<int, int> > :: iterator outIt=in.begin();
		bool flag=false;

		while (outIt!=in.end())
		{
			flag=false;
			temp=make_pair((outIt->first), (outIt->second));
			it=upper_bound(in.begin(), in.end(),temp, cmp);
			

			if(it!=in.end()) cout<<it->first<<"\t"<<it->second<<endl;

			while (it!=in.end())
			{
				temp=make_pair(it->first, it->second);
				in.erase(it);

				it=upper_bound(in.begin(), in.end(),temp,cmp);
				if(it!=in.end()) cout<<"a"<<it->first<<"\t"<<it->second<<endl;
				
				// flag=true;
			}
			in.erase(outIt);
count++;
			outIt=in.begin();
			cout<<"\nnext";
		}
		
		printf("\nans%d\n", count);
	}
	return 0;
}