#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int x[] = {0,0,1,-1};
int y[] = {1,-1,0,0};

int main(){
	int m,n;
	char matrix[1001][1001];
	bool discovered[1001][1001];
	pair<int,int> start,end;
	cin>>m>>n;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>matrix[i][j];
			if(matrix[i][j]=='E'){
				end.first = i;
				end.second = j;
			}else if(matrix[i][j]=='S'){
				start.first = i;
				start.second = j;
			}
		}
	}

	queue< pair<int,int> > q;
	pair<int,int> parent[1001][1001];
	q.push(start);
	int count = 0;
	while(1){
		pair <int,int> cur;
		cur = q.front();
		q.pop();
		discovered[cur.first][cur.second]= true;
		bool endishere=false;
		for (int i = 0; i < 4; ++i)
		{
			if(0<= (cur.first + x[i]) && (cur.first + x[i])<m && 0<= (cur.second + y[i]) && (cur.second + y[i])<m   ){
				if(matrix[cur.first + x[i]][cur.second + y[i]]!='T' && discovered[cur.first + x[i]][cur.second + y[i]] == false ){
					if(matrix[cur.first + x[i]][cur.second + y[i]]=='E'){
						endishere = true;
						PR(count);
						discovered[cur.first + x[i]][cur.second + y[i]] =true;
						// parent[cur.first + x[i]][cur.second + y[i]] = make_pair(cur.first,cur.second);
						break;
					}else{
						count++;
						q.push(make_pair(cur.first + x[i],cur.second + y[i]));
						discovered[cur.first + x[i]][cur.second + y[i]] =true;
						// parent[cur.first + x[i]][cur.second + y[i]] = make_pair(cur.first,cur.second);
					}
				}
			}
		}

		if(endishere){
			break;
		}

		/*for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout<<"<"<<parent[i][j].first<<","<<parent[i][j].second<<">"<<"\t";
			}
			cout<<endl;
		}*/

	}
	
	return 0;
}