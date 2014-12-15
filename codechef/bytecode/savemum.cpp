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
	

	int64_t t;cin>>t;
	
	while(t--){
		int64_t visited[255]={0};
		string s;
		cin>>s;
		std::vector<char> distinctChars;
		for (int64_t i = 0; i < s.size(); ++i)
		{
			if(visited[s[i]] == 0 ){
				visited[s[i]] = 1;
				distinctChars.push_back(s[i]);
			}
		}

		int64_t n = distinctChars.size();		
		std::map<char, int64_t> maping;
		for (int64_t i = 0; i < distinctChars.size(); ++i)
		{
			if(i==0){
				 maping[distinctChars[i]] = 1;
			} 
			else if(i==1) {
				 maping[distinctChars[i]] = 0;
			}
			else{
				
				maping[distinctChars[i]] = i;
				
			}

		}
		int64_t ans = 0;
		int64_t base;

		if(distinctChars.size() ==  1){ base = 2;}else {base = distinctChars.size();}
		for (int64_t i = 0; i < s.size(); ++i)
		{
				ans = ans*base + maping[s[i]];
		}

		cout<<ans<<endl;
		maping.clear();
		distinctChars.clear();
	}
	return 0;
}