#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";


int main(){
	string s;

	cin>>s;
	int i=0;
	while(i<s.length()){
		if (s[i]=='1')
		{
			if (s[i+1]=='4' && s[i+2]==4)
			{
				i=i+3;
			}else if(s[i+1]=='4'){
				i=i+2;
			}else{
				i=i+1;
			}
		}else{
			cout<<"NO"<<endl;
			return 0;
		}
	}

	cout<<"YES"<<endl;
}