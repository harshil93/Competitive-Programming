#include "cstdio"
#include "iostream"
#include "string"
using namespace std;

void *freqBuild(string a,int *freq){
	
	for (int i = 0; i < a.length(); ++i)
	{
		freq[a[i]-'a']++;
	}
}

int main(){
	int t,n;
	int freq1[27]={0},freq2[27]={0};
	string a,b,c="",ab,temp;
	cin>>t;
	while(t--){
		a="";b="";c="";
		for (int i = 0; i < 27; ++i)
		{
			freq1[i] = freq2[i] = 0;
		}
		cin>>a>>b;
		cin>>n;
		for(int i = 0; i < n; ++i){
			cin>>temp;
			c+=temp;
		}
		ab=a+b;
		// cout<<ab<<endl;
		// cout<<c<<endl;

		freqBuild(ab,freq1);
		freqBuild(c,freq2);
		int ans=1;
		for (int i = 0; i < 26; ++i)
		{
			if(freq1[i]>=freq2[i]){
				continue;
			}else{
				ans=0;
			}
		}

		if (ans)
		{
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

	}
	return 0;
}