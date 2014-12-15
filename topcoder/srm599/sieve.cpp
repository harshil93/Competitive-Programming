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
#include <functional>
#include <cstring>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 

void sieve(vector<int> &vp, int limit){
	int *isp = new int[limit];
	memset(isp, 0, limit*sizeof(int));
	isp[0]=1;isp[1]=1;
	for (int i = 2; i <= limit; ++i)
	{
		if(isp[i]) continue;
		else{
			vp.push_back(i);
		}
		for (int k=2; i*k <= limit; k++)
		{
			isp[i*k]=1;
		}
	}
}


int main(){
	std::vector<int> v;
	int limit = 100;
	sieve(v,limit);
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<endl;
	}
}