#include <iostream>
#include <vector>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
int main(){
	int n;
	cin>>n;
	
	while(n--){
		string a,b;
		cin>>a>>b;
		REP(i,a.size()){
			a[i]-='0';
		}
		
		REP(i,b.size()) b[i]-='0';
		if(a.size()<b.size()){
			string temp;
			temp=a;
			a=b;
			b=temp;
		}
		int i=0;
		int c=0;
		while(i<a.size()){
			if(i<b.size()){
				int s = (a[i] + b[i]+c)%10; 
			c = (a[i] + b[i])/10;
			a[i] = s;
			}else{
				int s = (a[i]+c)%10;
				c=(a[i]+s)/10;
			}
			i++;
		}

		vector<int> ans;
		// if(c) ans.push_back(c);
		for (int i = a.size()-1; i >=0; i--)
		{
			ans.push_back(a[i]);
		}
		
		int no=0;
		
		for(int i=ans.size()-1;i>0;i--){
			if(a[i]==0) no++;
			else break;
		}
		cout<<endl;cout<<endl;
		for(int i=0;i< ans.size() - no;i++){
			cout<<ans[i];
		}
		cout<<endl;
	}
}