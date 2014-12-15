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

std::vector<int> a,current,answer;
int main(){
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
	}

	for (int i = 0; i < 31; ++i)
	{
		int bit = 1 << i;
		int beaut =-1;
		current.clear();
		for (int j = n-1; j >= 0; --j)
		{
			int temp = a[j] & bit;
			if(temp != 0){
			 	current.push_back(a[j]);
			 	// PR(a[j])
			 	if(beaut == -1){
			 		beaut = a[j];
			 		// cout<<a[j]<<" firstset"<<endl;
			 	}else
			 	// cout<<"and"<<endl;
			 		beaut = beaut & a[j];
			}
		} 
		 // PR(beaut)
		if(beaut>0 && !(beaut % bit) ){
			answer = current;
		}
		
	}
	cout<<answer.size()<<endl;
	for (int i = answer.size()-1; i>=0; --i)
	{
		cout<<answer[i]<<" ";
	} 
	cout<<endl;
	return 0;
}