#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int main(){
	char matrix[101][101];
	int n;
	cin>>n;
	int allErows[101]={0};
	for (int i = 0; i < n; ++i)
	{
		bool flag = false;
		for (int j = 0; j < n; ++j)
		{
			cin>>matrix[i][j];
			if(matrix[i][j] == '.'){
				flag = true;
			}
		}
		if(flag){
			allErows[i]++;
		}
	}
	bool colWise = false;
	for (int i = 0; i < n; ++i)
	{
		if(allErows[i]==0){
			colWise = true;
			break;
		}
	}

	std::vector< pair<int,int> > v;
	if(!colWise){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(matrix[i][j] == '.'){
					v.push_back(make_pair(i,j));
					break;
				}
			}
		}
	}else{
		for (int j = 0; j < n; ++j)
		{
			for (int i = 0; i < n; ++i)
			{
				if(matrix[i][j] == '.'){
					v.push_back(make_pair(i,j));
					break;
				}
			}
		}
	}

	if(v.size() == n){
		for (int i = 0; i < v.size(); ++i)
		{
			cout<<v[i].first + 1<<" "<<v[i].second + 1<<endl;
		}
	}else{
		cout<<"-1"<<endl;
	}


}