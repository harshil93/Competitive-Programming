#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int t;
	string s;
	int alpha[27]={0};
	scanf("%d",&t);

	while(t--){
		cin>>s;
		for (int i = 0; i < s.length()/2; ++i)
		{
			// cout<<s[i]-'a'<<endl;
			alpha[s[i]-'a']++;
		}
		for (int i = ceil(s.length()/2.0) ; i < s.length(); ++i)
		{
			// cout<<s[i]-'a'<<endl;
			alpha[s[i]-'a']--;
		}
		int flag = 0;
		flag=0;
		for (int i = 0; i < 26; ++i)
		{
			if (alpha[i]!=0)
			{
				flag = 1;
				break;
			}
		}
		if (flag==1)
		{
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}

		for (int i = 0; i < 27; ++i)
		{
			alpha[i]=0;
		}
	}
}