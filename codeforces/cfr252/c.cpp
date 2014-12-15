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
#define REP(i,n) for( int i =0 ; i < n ; i++ )

struct pt
{
	int r,c;

	pt& operator=(pt &b){
		r = b.r;
		c = b.c;
	}
};

std::vector<pt> ans;

int absi(int x){
	if(x<0) return -x;
	return x;
}

void recur(int k, pt pt1, pt pt2){

	if(k==0){
		return;
	}
	cout<<k<<"\t"<<pt1.r<<","<<pt1.c<<"\t"<<pt2.r<<","<<pt2.c<<endl;

	if(k==1){
		ans.push_back(pt1);
		ans.push_back(pt2);
		return;
	}
	// rows divide
	int z1 = (absi(pt2.r - pt1.r) + 1 + 1) / 2 ;
	int z2 = (absi(pt2.c - pt1.c) +1);
	int z3 = ((k+1)/2) * 2;
	// PR(z1)
	// PR(z2)
	// PR(z3)
	if( z1*z2 > z3  ){
		pt a_pt1, a_pt2, b_pt1, b_pt2;

		a_pt1 = pt1;
		b_pt2 = pt2;

		a_pt2.r = a_pt1.r + (pt2.r - pt1.r + 1)/2 ; 
		a_pt2.c = pt2.c;

		b_pt1.r = a_pt2.r + 1;
		b_pt1.c = pt1.c;
		cout<<"row"<<k<<endl;
		recur(k+1/2, a_pt1,a_pt2);
		recur(k/2, b_pt1, b_pt2);
	}else{
		//col dividept a_pt1, a_pt2, b_pt1, b_pt2;
		pt a_pt1, a_pt2, b_pt1, b_pt2;

		a_pt1 = pt1;
		b_pt2 = pt2;

		a_pt2.c = a_pt1.c + (pt2.c - pt1.c + 1)/2 ; 
		a_pt2.r = pt2.r;

		b_pt1.c = a_pt2.c + 1;
		b_pt1.r = pt1.r;
		

		recur((k+1)/2, a_pt1,a_pt2);
		
		recur(k/2, b_pt1, b_pt2);
		//
		
		

	}
}

int main(){
	int n, m , k;
cin>>n>>m>>k;
	pt pt1 , pt2;

	pt1.r = 1; pt1.c = 1;
	pt2.r = n; pt2.c = m;

	recur(k,pt1,pt2);
cout<<"------------------------"<<endl;
	for (int i = 0; i < ans.size(); i = i+2)
	{
		cout<<ans[i].r<<","<<ans[i].c<<"\t"<<ans[i].r<<","<<ans[i].c<<endl;
	}
	return 0;
}