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

class UnionFind
{
public:
	int *P,*rank,*size,*id;
	int cnt;
	UnionFind(int n){
		P = new int[n];
		id = new int[n];
		size = new int[n];
		rank = new int[n];
		cnt = n;
		for (int i = 0; i < n; ++i)
		{
			P[i] = i;
			id[i] = i;
			size[i] = 1;
			rank[i] = 1;
		}
	}

	int find(int x){
		int t = x;

		while(P[t]!=t){
			t = P[t];
		}
		int root =t;
		t=x;
		while(P[t]!=t){
			int temp = t;
			t = P[t];
			P[temp] = root;
		}

		return t;
	}

	void merge(int x, int y){
		int px = find(x);
		int py = find(y);

		if(rank[px]>rank[py]){
			P[py] = px;
		}else{
			P[px] = py;
		}

		if(rank[px]== rank[py]) rank[py]++; 
		cnt--;
	}

	int getCnt(){
		return cnt;
	}

	bool isConnected(int x, int y){
		return find(x)==find(y);
	}

};

int main(){
	UnionFind U(8);
	PR(U.getCnt());
	U.merge(2,4);
	U.merge(1,2);
	PR(U.getCnt());
	PR((U.find(1)))

	return 0;

}