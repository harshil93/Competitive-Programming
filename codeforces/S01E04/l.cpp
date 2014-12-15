#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#define PR(x) cout << #x " = " << x << "\n";

int64_t GCD(int64_t a, int64_t b)
{
   if (b==0) return a;
   return GCD(b,a%b);
}

int64_t LCM(int64_t a, int64_t b)
{
   return b*a/GCD(a,b);
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string str,enc;
		int n;
		cin>>n;
		cin>>str;
		cin>>enc;
		int freq[256]={0};
		char decode[256]={0};
		int minchar[256]={0};
		// cout<<enc<<endl;
		char decodestep[256][27]={0};
		for (int i = 0; i < 26; ++i)
		{
			decode[enc[i]] = 'a'+i;
			// cout<<enc[i]<<" "<<decode[enc[i]]<<endl;
		}
		/*for (int i = 0; i < 26; ++i)
		{
			char cur = 'a'+i;
			int mintime=0;
			char minc = 'a'+i;
			int f=1;
			decodestep['a'+i][0] = 'a'+i;
			while('a'+i !=decode[cur]){

				if(minc>decode[cur]){
					mintime = f;
					minc = decode[cur];
				}
				cur = decode[cur];
				decodestep['a'+i][f] = cur;
				f++;
			}
			freq['a'+i] = f+1;
			minchar['a'+i] = mintime;
		}

		for (int i = 0; i < 256; ++i)
		{
			if(minchar[i]==0) minchar[i]=freq[i];
		}

		for (int i = 0; i < 26; ++i)
		{
			cout<<(char) ('a'+i)<<" "<<minchar['a'+i]<<endl;
			cout<<"freq "<<(char) ('a'+i)<<" "<<freq['a'+i]<<endl;
		} */


		char aaya[26] = {0};
		std::vector<char> v;
		for (int i = 0; i < str.length(); ++i)
		{
			if(aaya[str[i]] == 0){
				v.push_back(str[i]);
				aaya[str[i]] =1;
			}
		}

		std::map<string, int> m1;
		string s(v.begin(),v.end());
		string min;
		min = s;
		while(!m1[s]){
			m1[s] = 1;
			// cout<<"@@"<<endl;
			for (int i = 0; i < s.size(); ++i)
			{
				s[i] = decode[s[i]];
			}

			if(s<min) min = s;

		}

		std::map<char, char> final;
		for (int i = 0; i < v.size(); ++i)
		{
			final[v[i]] = min[i];
		}
		

		for (int i = 0; i < str.size(); ++i)
		{
			str[i] = final[str[i]];
		}
		cout<<str<<endl;

	}
}
