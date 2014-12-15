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
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
#define PII pair<int,int> 
#define VI vector<int> 
#define VII vector <VI >
#define REP(i,s,e) for(int i=s; i<e; i++)
#define ff first
#define ss second
#define pb push_back

int mat[10][10] = {{55,60,4,25,18,10,12,8,11,50},
{60,45,75,23,27,20,24,7,33,12},
{4,75,78,32,36,30,36,6,12,65},
{25,23,32,15,45,40,48,5,14,23},
{18,27,36,45,54,50,60,4,15,12},
{10,20,30,40,50,60,72,3,32,34},
{12,24,36,48,60,72,84,2,23,34},
{8,7,6,5,4,3,2,1,34,123},
{11,33,12,14,15,32,23,34,65,48},
{50,12,65,23,12,34,34,123,48,71}};


int main(int argc, char const *argv[])
{
	int num[10],temp;
	
	int t; cin>>t;

	while(t--){
		std::vector<int> v,w;
		for (int i = 0; i < 10; ++i)
		{
			cin>>num[i];
		}
		for (int i = 0; i < 10; ++i)
		{
			cin>>temp;
			if(temp == 1){
				v.pb(i);
				
			}
		}
		w = v;
		int64_t sum = 0,maxsum=0;
		sort(w.begin(),w.end());
		do{
			sum=0;
			for (int i = 0; i < v.size(); ++i)
			{
				sum+= mat[v[i]][w[i]];
			}
			maxsum = max(sum,maxsum);
			
		}while(next_permutation(w.begin(),w.end()));

		cout<<maxsum<<endl;



	}
	

	return 0;
}
