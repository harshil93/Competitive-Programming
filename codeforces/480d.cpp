#include <bits/stdc++.h>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef pair<int,int> II; 
#define SZ(a) int((a).size()) 
#define PB push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define FOR(i,n) for( int i =0 ; i < n ; i++ )
#define ll long long
#define FF first
#define SS second

int n;

struct parcel
{
	int in,out,w,s,v,ind;
	parcel(int _ind,int _in,int _out,int _w,int _s,int _v){
		in = _in;out = _out;w = _w;s = _s;v = _w; ind = _ind;
	}
};

bool funcOut(parcel &p1,parcel &p2){
	return p1.out < p2.out;
}


std::vector<parcel> col;

ll dp[501][1001];

ll solveOverlapping(VI &set)
{
	if(set.size() == 0) return 0;
	ll dp[2001]={0};
	int j=0;
	for (int i = 1; i < 2001; ++i)
	{
		if(col[set[j]].out == i){
			dp[i] = max(dp[i-1],dp[i - col[set[j]].out + col[set[j]].in] + col[set[j]].v);
			j++;
			if(set.size() == j){
				return dp[i];
			}
		}else{
			dp[i] = dp[i-1];
		}
	}
	return dp[2000];
}

ll recur(int top,int rem){

	if(dp[top][rem]!=-1) return dp[top][rem];
	std::vector<int> inset;

	for (int i = 0; i < col.size(); ++i)
	{
		if(i!=top && col[i].in >= col[top].in && col[i].out <= col[top].out){
			int remS = min(rem-col[i].w,col[i].s);
			
			if( remS >= 0 ){
				dp[i][remS] = recur(i,remS) + col[i].v;
				inset.PB(i);
			}
		}
	}

	if(inset.size() != 0)
		dp[top][rem] = solveOverlapping(inset);
	else 
		dp[top][rem] = 0;
	return dp[top][rem];
}

int main(){
		memset(dp,-1,sizeof(dp));
		int s;
		cin>>n>>s;
		col.PB(parcel(0,-1,2000,0,s,0));

		FOR(i,n){
			int in,out,w,s,v;
			cin>>in>>out>>w>>s>>v;
			col.PB(parcel(i+1,in,out,w,s,v));
		}
		sort(col.begin(),col.end(),funcOut);
		cout<<recur(SZ(col) - 1,s)<<endl;
}