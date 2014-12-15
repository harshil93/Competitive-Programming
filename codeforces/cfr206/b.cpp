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
	int c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int n,m; cin>>n>>m;
	int *bus = new int[n];
	int64_t bussum=0,trolsum=0;
	for (int i = 0; i < n; ++i)
	{
		cin>>bus[i];
		bussum+=bus[i];
	}

	int *trol = new int[m];

	for (int i = 0; i < m; ++i)
	{
		cin>>trol[i];
		trolsum+=trol[i];
	}

	bool ulridebus[1200]={false}, ultrolride[1200]={false};
	int tempBussum = 0,tempTrolsum=0;
	for (int i = 0; i < n; ++i)
	{
		if(bus[i]*c1>c2){
			ulridebus[i] = true;
			tempBussum+=c2;
		}else{
			tempBussum+=(bus[i]*c1);
		}
	}

	for (int i = 0; i < m; ++i)
	{
		if(trol[i]*c1>c2){
			ultrolride[i] = true;
			tempTrolsum+=c2;
		}else{
			tempTrolsum+=(trol[i]*c1);
		}
	}
	// PR(tempTrolsum)
	// PR(tempBussum)
	int neveruse4=0;
	int neveruse3=0;
	if(2*c3<c4) neveruse4=1;
	if(c3>c4) neveruse3=1;
	int finalsum=0;
	if(tempTrolsum > c3){
		if(neveruse3){
			finalsum+=c4;
			cout<<finalsum<<endl;
			return 0;
		}else{
			finalsum+=c3;
		}
	}else{
		finalsum+=tempTrolsum;
	}

	if(tempBussum>c3){
		if(neveruse3){
			finalsum+=c4;
			cout<<finalsum<<endl;
		}else{
			finalsum+=c3;
		}
	}else{
		finalsum+=tempBussum;
	}

	if(finalsum>c4) finalsum=c4;
		cout<<finalsum<<endl;
	return 0;
		
}