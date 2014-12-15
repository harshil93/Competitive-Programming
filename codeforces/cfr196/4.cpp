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

int main(){
	int m,n,d;

	cin>>n>>m>>d;

	std::vector<int> p;
	for (int i = 0; i < m; ++i)
	{
		int temp ; cin>>temp;
		p.push_back(temp);
	}

	std::vector< std::vector<int> > graph;

	graph.resize(n);

	for (int i = 0; i < n; ++i)
	{
		int a,b;
		cin>>a>>b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	
}