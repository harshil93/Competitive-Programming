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
char mark[100001]={0};


struct node
{
	int type;
	int to;

	node(){
		to = 0;
	}
};
int type[100001];
int from[100001];

int dfsFromHotel(int i){
	if(mark[from[i]]<2 && from[i]>0){
		return 1+ dfsFromHotel(from[i] - 1);
	}else{
		return 1;
	}
}
stack<int> q;
int dfsPrint(int i){
	q.push(i+1);
	if(mark[from[i]]<2 && from[i]>0){
		return 1+ dfsPrint(from[i] - 1);
	}else{
		return 1;
	}
}
int main(){
	int n;

	cin>>n;
	
	for (int i = 0; i < n; ++i)
	{
		cin>>type[i];
	}
	for (int i = 0; i < n; ++i)
	{
		cin>>from[i];
		mark[from[i]]++;
	}
	int maxi = 0;
	int index = -1;
	for (int i = 0; i < n; ++i)
	{
		if(type[i] == 1){
			int temp = dfsFromHotel(i);
			if(temp>maxi){
				maxi = temp;
				index = i;
			}
			
		}
	}

	cout<<maxi<<endl;
	dfsPrint(index);
	int tt = q.size();
	for (int i = 0; i < tt; ++i)
	{
		int t = q.top();
		cout<<t<<" ";
		q.pop();
	}

	cout<<endl;
}