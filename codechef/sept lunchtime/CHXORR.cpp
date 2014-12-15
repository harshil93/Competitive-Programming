#include <iostream>
using namespace std;

int maxi(int a, int b){
	return a>b?a:b;
}

int main(){
	int t; cin>>t;
	int a[10000];
	
	while(t--){
		int n;
		cin>>n;
		for(int i=0 ; i<n; i++){
			cin>>a[i];
			// cout<<a[i]<<endl;
		}
		int maxVal = 0;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				for(int k=j+1;k<n;k++){
					maxVal = maxi(maxVal, a[i]^a[j]^a[k]);
				}
		
		cout<<maxVal<<endl;
	}
	
	return 0;
}