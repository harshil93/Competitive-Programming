#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

typedef struct recipe
{
	int priority;
	string s;
} recipe;

struct trienode
{
	recipe r;
	struct trienode *ch[30];
	trienode(recipe _r){
		r=_r;
		for (int i = 0; i < 30; ++i)
		{
			ch[i]= NULL:
		}
	}
	trienode(){
		for (int i = 0; i < 30; ++i)
		{
			ch[i]=NULL;
		}
	}
};

trienode* ins(recipe& r,int size){

}
int main(){
	int n,q;
	cin>>n;
	recipe *rp = new recipe[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>rp[i].s;
		cin>>rp[i].priority;
	}
	cin>>q;

	while(q--){

	}


}

