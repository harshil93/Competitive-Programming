#include "iostream"
#include "stdint.h"
#include "algorithm"
using namespace std;

int sw[100005];
int ani[100005];
int main(){
	int t;
	cin>>t;

	while(t--){
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			cin>>sw[i];
		}

		for (int i = 0; i < n; ++i)
		{
			cin>>ani[i];
		}

		sort(sw,sw+n);
		sort(ani,ani+n);
		int flag = 0;
		for (int i = 0; i < n; ++i)
		{
			if(sw[i]<=ani[i]){
				flag = 1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
		
	}
	return 0;
}