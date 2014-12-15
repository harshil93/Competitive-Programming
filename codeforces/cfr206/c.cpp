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
	int n,l,r,ql,qr;

	cin>>n>>l>>r>>ql>>qr;
	int w[100001];

	for (int i = 0; i < n; ++i)
	{
		cin>>w[i];
	}

	if(n==1){
		if(l<r){
			cout<<l*w[0]<<endl;
			return 0;
		}else{
			cout<<r*w[0]<<endl;
			return 0;
		}
	}
	 int64_t sum=0;
	 int curi=0, curj=n-1;
	 sum+=w[0]*l;
	 curi=1;
	 char pside = 'l';
	 while(curi!=curj){
	 	if(pside == 'l'){
	 		if(w[curj]*r < w[curj]*l + ql ){
	 			sum+=w[curj]*r;
	 			curj--;
	 			pside = 'r';
	 		}else{
	 			sum+= w[curi]*l +ql;
	 			curi++;
	 			pside = 'l';
	 		}
	 	}else{
	 		if(w[curi]*l < w[curi]*r + qr){
	 			sum+=w[curi]*l;
	 			curi++;
	 			pside = 'l';
	 		}else{
	 			sum+= w[curj]*r +qr;
	 			curj--;
	 			pside = 'r';
	 		}
	 	}
	 }

	 if(pside=='l'){
	 	if(w[curj]*r > w[curj]*l + ql){
	 		sum+= w[curj]*l + ql;
	 	}else{
	 		sum+= w[curj]*r;
	 	}
	 }else{
	 	if(w[curi]*l > w[curi]*r + qr){
	 		sum+= w[curj]*r + qr;
	 	}else{
	 		sum+= w[curj]*l;
	 	}
	 }
	 int64_t finalsum= sum;

	 sum=w[n-1]*r;
	 curi=0;
	 curj=n-2;
	  pside = 'r';
	 while(curi!=curj){
	 	if(pside == 'l'){
	 		if(w[curj]*r < w[curj]*l + ql ){
	 			sum+=w[curj]*r;
	 			curj--;
	 			pside = 'r';
	 		}else{
	 			sum+= w[curi]*l +ql;
	 			curi++;
	 			pside = 'l';
	 		}
	 	}else{
	 		if(w[curi]*l < w[curi]*r + qr){
	 			sum+=w[curi]*l;
	 			curi++;
	 			pside = 'l';
	 		}else{
	 			sum+= w[curj]*r +qr;
	 			curj--;
	 			pside = 'r';
	 		}
	 	}
	 }

	 if(pside=='l'){
	 	if(w[curj]*r > w[curj]*l + ql){
	 		sum+= w[curj]*l + ql;
	 	}else{
	 		sum+= w[curj]*r;
	 	}
	 }else{
	 	if(w[curi]*l > w[curi]*r + qr){
	 		sum+= w[curj]*r + qr;
	 	}else{
	 		sum+= w[curj]*l;
	 	}
	 }

	 cout<<min(sum,finalsum)<<endl;
}